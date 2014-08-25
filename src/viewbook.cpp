#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "viewbook.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/aui/auibook.h>
/*---------------------------------------------------------------------------*/
#include "viewbook.h"
#include "wxsqliteplusapp.h"
#include "sqliteplusframe.h"
#include "sqlite3table.h"
#include "paneldata.h"
#include "specgrid.h"
/*---------------------------------------------------------------------------*/
#define ID_VIEWEBOOK    15001
#define ID_PAGECOLUMNS  15002
#define ID_PAGEDATA     15003
#define ID_PAGEDDL      15004
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS(wxViewBook, wxDbBook)

BEGIN_EVENT_TABLE(wxViewBook, wxDbBook)
   EVT_AUINOTEBOOK_PAGE_CHANGING(ID_VIEWEBOOK, wxViewBook::OnViewebookPageChanging)
   EVT_MENU(wxID_COPY, wxViewBook::OnCopyClick)
   EVT_UPDATE_UI(wxID_COPY, wxViewBook::OnCopyUpdate)
   EVT_MENU(ID_CMD_ED_REFRESH, wxViewBook::OnEdRefresh)
END_EVENT_TABLE()
/*---------------------------------------------------------------------------*/
wxViewBook::wxViewBook()
{
   Init();
}
/*---------------------------------------------------------------------------*/
wxViewBook::wxViewBook(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                       const wxSize& size, long style)
{
   Init();
   Create(parent, id, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxViewBook::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                        const wxSize& size, long style)
{
   wxDbBook::Create( parent, id, pos, size, style );

   CreateControls();
   if (GetSizer())
   {
      GetSizer()->SetSizeHints(this);
   }
   return true;
}
/*---------------------------------------------------------------------------*/
wxViewBook::~wxViewBook()
{
}
/*---------------------------------------------------------------------------*/
void wxViewBook::Init()
{
   m_Book = NULL;
   m_PageColumns = NULL;
   m_PageData = NULL;
   m_PageDdl = NULL;
   m_InitData = true;
}
/*---------------------------------------------------------------------------*/
void wxViewBook::CreateControls()
{
   wxBoxSizer* bSizer = new wxBoxSizer(wxHORIZONTAL);
   SetSizer(bSizer);

   m_Book = new wxAuiNotebook(this, ID_VIEWEBOOK, wxDefaultPosition,
                              wxDefaultSize,
                              wxAUI_NB_TOP|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE);

   m_PageColumns = new wxSpecGrid(m_Book, ID_PAGECOLUMNS, wxDefaultPosition,
                                  wxDefaultSize, wxHSCROLL|wxVSCROLL);
   m_PageColumns->SetDefaultColSize(50);
   m_PageColumns->SetDefaultRowSize(25);
   m_PageColumns->SetColLabelSize(25);

   wxBitmap m_PageColumnsBitmap(wxGetApp().GetBmp(ID_BMP_FIELD));
   m_Book->AddPage(m_PageColumns, _("Columns"), false, m_PageColumnsBitmap);

   m_PageData = new wxPanelData(m_Book, ID_PAGEDATA, wxDefaultPosition, wxDefaultSize);

   wxBitmap m_PageDataBitmap(wxGetApp().GetBmp(ID_BMP_TABLE));
   m_Book->AddPage(m_PageData, _("Data"), false, m_PageDataBitmap);

   m_PageDdl = new wxDDLEditor(m_Book, ID_PAGEDDL);

   wxBitmap m_PageDdlBitmap(wxGetApp().GetBmp(ID_BMP_RUNSCRIPT));
   m_Book->AddPage(m_PageDdl, _("DDL"), false, m_PageDdlBitmap);

   bSizer->Add(m_Book, 1, wxGROW, 0);
}
/*---------------------------------------------------------------------------*/
bool wxViewBook::ShowToolTips(){return true;}
/*---------------------------------------------------------------------------*/
void wxViewBook::OnViewebookPageChanging( wxAuiNotebookEvent& event )
{
   if (m_InitData)
   {  // Vérifier si c'est l'onglet Data qui doit être affiché
      if (("Data") == m_Book->GetPageText(event.GetSelection()))
      {  // Si oui lancer la sélection des données de la table
         m_InitData = false;
         RefreshData();
      }
   }
   event.Skip();
}
/*---------------------------------------------------------------------------*/
void wxViewBook::SetDbObjectName(wxSQLite3Database* db,
                                 const wxString& objectname, const wxString& base)
{
   wxDbBook::SetDbObjectName(db, objectname, base);
   m_PageData->SetDbTableViewName(db, objectname, base);
   RefreshStruct();
}
/*---------------------------------------------------------------------------*/
void wxViewBook::RefreshDbObject()
{
   RefreshStruct();
   if (("Data") == m_Book->GetPageText(m_Book->GetSelection()))
      RefreshData();
   else
      m_InitData = true;
}
/*---------------------------------------------------------------------------*/
void wxViewBook::RefreshStruct()
{
   if (!m_db || m_DbObjectName.IsEmpty())
      return;
   // Remplir les wxGrid avec les paramètres de la table
   wxSQLitePlusFrame* frame;
   wxString sql, basename;
   wxSQLite3ResultSet resultSet;
   wxGridSQLite3TableBase* table;
   wxColour oddColour(wxGetApp().GetParamStr(PARAM_ODDROWCOLOR));

   if (m_Base != wxEmptyString)
      basename = m_Base;
   else
      basename = ("main");
   try
   {
      // remplissage de la grille des colonnes
      m_PageColumns->SetTable(&g_EmptyTable);
      m_PageColumns->ForceRefresh();
      table = new wxGridTblColumnsTable(m_db, m_DbObjectName, basename);
      table->SetAttrProvider(new OddRowsGridCellAttrProvider(oddColour));
      m_PageColumns->SetTable((wxGridTableBase*)table, true);
      table->AdaptColumnsSize();
      m_PageColumns->SetRowLabelSize(0);
      m_PageColumns->SetDefaultSelection();
      m_PageColumns->ForceRefresh();
   }
   catch(wxSQLite3Exception& ex)
   {
      wxGetApp().ShowError(("RefreshStruct"), ex);
   }

   frame = (wxSQLitePlusFrame*)wxGetApp().GetTopWindow();
   m_PageDdl->SetValue(frame->GetDbObjectDDL(otView, m_DbObjectName, basename));
}
/*---------------------------------------------------------------------------*/
void wxViewBook::RefreshData()
{
   m_PageData->DoRefresh();
}
/*---------------------------------------------------------------------------*/
void wxViewBook::OnCopyClick(wxCommandEvent& event)
{
   wxWindow* window = FindFocus();

   if (window && ((window == m_PageDdl)||
      (m_PageColumns && m_PageColumns->HasFocus())||
      (m_PageData && m_PageData->HasFocus())))
      window->GetEventHandler()->ProcessEvent(event);
}
/*---------------------------------------------------------------------------*/
void wxViewBook::OnCopyUpdate(wxUpdateUIEvent& event)
{
   wxWindow* window = FindFocus();

   if (window && ((window == m_PageDdl)||
      (m_PageColumns && m_PageColumns->HasFocus())||
      (m_PageData && m_PageData->HasFocus())))
      window->GetEventHandler()->ProcessEvent(event);
   else
      event.Enable(false);
}
/*---------------------------------------------------------------------------*/
void wxViewBook::OnEdRefresh(wxCommandEvent& event)
{
}
/*---------------------------------------------------------------------------*/

