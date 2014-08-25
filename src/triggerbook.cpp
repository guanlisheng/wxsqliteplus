#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "triggerbook.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
/*---------------------------------------------------------------------------*/
#include "triggerbook.h"
#include "sqlite3table.h"
#include "wxsqliteplusapp.h"
#include "sqliteplusframe.h"
/*---------------------------------------------------------------------------*/
#define ID_PAGEDDL 15001
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS(wxTriggerBook, wxDbBook)

BEGIN_EVENT_TABLE(wxTriggerBook, wxDbBook)
   EVT_MENU(wxID_COPY, wxTriggerBook::OnCopyClick)
   EVT_UPDATE_UI(wxID_COPY, wxTriggerBook::OnCopyUpdate)
   EVT_MENU(ID_CMD_ED_REFRESH, wxTriggerBook::OnEdRefresh)
END_EVENT_TABLE()
/*---------------------------------------------------------------------------*/
wxTriggerBook::wxTriggerBook()
{
   Init();
}
/*---------------------------------------------------------------------------*/
wxTriggerBook::wxTriggerBook(wxWindow* parent, wxWindowID id,
                             const wxPoint& pos, const wxSize& size, long style)
{
   Init();
   Create(parent, id, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxTriggerBook::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos,
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
wxTriggerBook::~wxTriggerBook()
{
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::Init()
{
   m_PageDdl = NULL;
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::CreateControls()
{    
   wxBoxSizer* bSizer = new wxBoxSizer(wxHORIZONTAL);
   SetSizer(bSizer);
   
   m_PageDdl = new wxDDLEditor(this, ID_PAGEDDL);
   bSizer->Add(m_PageDdl, 1, wxGROW, 0);
}
/*---------------------------------------------------------------------------*/
bool wxTriggerBook::ShowToolTips(){return true;}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::SetDbObjectName(wxSQLite3Database* db,
                                    const wxString& objectname,
                                    const wxString& base)
{
   wxDbBook::SetDbObjectName(db, objectname, base);
   RefreshDbObject();
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::RefreshDbObject()
{
   if (!m_db || m_DbObjectName.IsEmpty())
      return;

   wxSQLitePlusFrame* frame;
   wxString sql, basename;
   wxSQLite3ResultSet resultSet;

   if (m_Base != wxEmptyString)
      basename = m_Base;
   else
      basename = ("main");

   frame = (wxSQLitePlusFrame*)wxGetApp().GetTopWindow();
   m_PageDdl->SetValue(frame->GetDbObjectDDL(otTrigger, m_DbObjectName, basename));
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::OnCopyClick(wxCommandEvent& event)
{
   wxWindow* window = FindFocus();

   if (window && (window == m_PageDdl))
      window->GetEventHandler()->ProcessEvent(event);
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::OnCopyUpdate(wxUpdateUIEvent& event)
{
   wxWindow* window = FindFocus();

   if (window && (window == m_PageDdl))
      window->GetEventHandler()->ProcessEvent(event);
   else
      event.Enable(false);
}
/*---------------------------------------------------------------------------*/
void wxTriggerBook::OnEdRefresh(wxCommandEvent& event)
{
   m_PageDdl->InitStyle();
}
/*---------------------------------------------------------------------------*/

