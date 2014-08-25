#ifndef _INDEXBOOK_H_
#define _INDEXBOOK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "indexbook.h"
#endif
/*---------------------------------------------------------------------------*/
#include "dbbook.h"
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxSpecGrid;
class wxSQLite3Database;
/*---------------------------------------------------------------------------*/
class wxIndexBook: public wxDbBook
{    
   DECLARE_DYNAMIC_CLASS(wxIndexBook)
   DECLARE_EVENT_TABLE()

   public:

      wxIndexBook();
      wxIndexBook(wxWindow* parent, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxTAB_TRAVERSAL);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxTAB_TRAVERSAL);

      ~wxIndexBook();

      virtual void SetDbObjectName(wxSQLite3Database* db,
                                   const wxString& objectname,
                                   const wxString& base);

      virtual void RefreshDbObject();

   protected:
      
      void Init();
      void CreateControls();
      static bool ShowToolTips();

      void OnCopyClick(wxCommandEvent& event);
      void OnCopyUpdate(wxUpdateUIEvent& event);
      void OnEdRefresh(wxCommandEvent& event);
      
   private:
      
      wxSpecGrid* m_PageColumns;
      wxDDLEditor* m_PageDdl;

};
/*---------------------------------------------------------------------------*/
#endif   // _INDEXBOOK_H_

