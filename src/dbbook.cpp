#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dbbook.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "dbbook.h"
#include "sqlite3table.h"
/*---------------------------------------------------------------------------*/
IMPLEMENT_CLASS(wxDbBook, wxPanel)
/*---------------------------------------------------------------------------*/
wxDbBook::wxDbBook()
{
   Init();
}
/*---------------------------------------------------------------------------*/
wxDbBook::wxDbBook(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                   const wxSize& size, long style)
{
   Init();
   Create(parent, id, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxDbBook::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                      const wxSize& size, long style)
{
   wxPanel::Create( parent, id, pos, size, style );
   return true;
}
/*---------------------------------------------------------------------------*/
wxDbBook::~wxDbBook()
{
}
/*---------------------------------------------------------------------------*/
void wxDbBook::Init()
{
   m_db = NULL;
}
/*---------------------------------------------------------------------------*/
void wxDbBook::SetDbObjectName(wxSQLite3Database* db,
                               const wxString& objectname, const wxString& base)
{
   m_db = db;
   m_Base = base;
   m_DbObjectName = objectname;
}                               
/*---------------------------------------------------------------------------*/

