#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "indexbook.h"
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
#include "indexbook.h"
#include "wxsqliteplusapp.h"
#include "sqliteplusframe.h"
#include "sqlite3table.h"
#include "specgrid.h"
/*---------------------------------------------------------------------------*/
#define ID_INDEXBOOK    15001
#define ID_PAGECOLUMNS  15002
#define ID_PAGEDDL      15003
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS(wxIndexBook, wxDbBook)

BEGIN_EVENT_TABLE(wxIndexBook, wxDbBook)
    EVT_MENU(wxID_COPY, wxIndexBook::OnCopyClick)
    EVT_UPDATE_UI(wxID_COPY, wxIndexBook::OnCopyUpdate)
    EVT_MENU(ID_CMD_ED_REFRESH, wxIndexBook::OnEdRefresh)
END_EVENT_TABLE()
/*---------------------------------------------------------------------------*/
wxIndexBook::wxIndexBook()
{
    Init();
}
/*---------------------------------------------------------------------------*/
wxIndexBook::wxIndexBook(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                         const wxSize& size, long style)
{
    Init();
    Create(parent, id, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxIndexBook::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos,
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
wxIndexBook::~wxIndexBook()
{
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::Init()
{
    m_PageColumns = NULL;
    m_PageDdl = NULL;
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::CreateControls()
{
    wxBoxSizer* bSizer = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bSizer);

    wxAuiNotebook* noteBook = new wxAuiNotebook(this, ID_INDEXBOOK,
            wxDefaultPosition, wxDefaultSize,
            wxAUI_NB_TOP|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE);

    m_PageColumns = new wxSpecGrid(noteBook, ID_PAGECOLUMNS, wxDefaultPosition,
                                   wxSize(200, 150), wxHSCROLL|wxVSCROLL);
    m_PageColumns->SetDefaultColSize(50);
    m_PageColumns->SetDefaultRowSize(25);
    m_PageColumns->SetColLabelSize(25);

    wxBitmap m_PageColumnsBitmap(wxGetApp().GetBmp(ID_BMP_FIELD));
    noteBook->AddPage(m_PageColumns, _("Columns"), false, m_PageColumnsBitmap);

    m_PageDdl = new wxDDLEditor(noteBook, ID_PAGEDDL);

    wxBitmap m_PageDdlBitmap(wxGetApp().GetBmp(ID_BMP_RUNSCRIPT));
    noteBook->AddPage(m_PageDdl, _("DDL"), false, m_PageDdlBitmap);

    bSizer->Add(noteBook, 1, wxGROW, 0);
}
/*---------------------------------------------------------------------------*/
bool wxIndexBook::ShowToolTips() {
    return true;
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::SetDbObjectName(wxSQLite3Database* db,
                                  const wxString& objectname,
                                  const wxString& base)
{
    wxDbBook::SetDbObjectName(db, objectname, base);
    RefreshDbObject();
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::RefreshDbObject()
{
    if (!m_db || m_DbObjectName.IsEmpty())
        return;

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
        sql = wxString::Format(("PRAGMA '%s'.index_info(\"%s\");"),
                               basename.c_str(), m_DbObjectName.c_str());
        resultSet = m_db->ExecuteQuery(ToUTF8(sql));
        m_PageColumns->SetTable(&g_EmptyTable);
        m_PageColumns->ForceRefresh();
        table = new wxGridSQLite3Table(&resultSet);
        table->SetAttrProvider(new OddRowsGridCellAttrProvider(oddColour));
        m_PageColumns->SetTable((wxGridTableBase*)table, true);
        table->AdaptColumnsSize();
        m_PageColumns->SetRowLabelSize(0);
        m_PageColumns->SetDefaultSelection();
        m_PageColumns->ForceRefresh();
        resultSet.Finalize();
    }
    catch(wxSQLite3Exception& ex)
    {
        wxGetApp().ShowError("RefreshDbObject", ex);
    }

    frame = (wxSQLitePlusFrame*)wxGetApp().GetTopWindow();
    m_PageDdl->SetValue(frame->GetDbObjectDDL(otIndex, m_DbObjectName, basename));
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::OnCopyClick(wxCommandEvent& event)
{
    wxWindow* window = FindFocus();

    if (window && ((window == m_PageDdl)||(m_PageColumns && m_PageColumns->HasFocus())))
        window->GetEventHandler()->ProcessEvent(event);
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::OnCopyUpdate(wxUpdateUIEvent& event)
{
    wxWindow* window = FindFocus();

    if (window && ((window == m_PageDdl)||(m_PageColumns && m_PageColumns->HasFocus())))
        window->GetEventHandler()->ProcessEvent(event);
    else
        event.Enable(false);
}
/*---------------------------------------------------------------------------*/
void wxIndexBook::OnEdRefresh(wxCommandEvent& event)
{
    m_PageDdl->InitStyle();
}
/*---------------------------------------------------------------------------*/

