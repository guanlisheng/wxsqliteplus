#ifndef _SQLHISTORY_H_
#define _SQLHISTORY_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "sqlhistory.h"
#endif
/*---------------------------------------------------------------------------*/
#include "specgrid.h"
/*---------------------------------------------------------------------------*/
class wxSpecGrid;
class wxSQLite3ResultSet;
/*---------------------------------------------------------------------------*/
class wxSQLHistory: public wxDialog
{    
   DECLARE_DYNAMIC_CLASS(wxSQLHistory)
   DECLARE_EVENT_TABLE()

   public:

      wxSQLHistory();
      wxSQLHistory(wxWindow* parent, wxWindowID id = -1,
                   const wxString& caption = _("SQL History"),
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("SQL History"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxSQLHistory();

      void SetResultSet(wxSQLite3ResultSet& resultSet);
      
      wxString GetSQLStatement(){return m_SqlStatement;}
      
   protected:

      void Init();
      void CreateControls();

      void OnCellLeftDClick(wxGridEvent& event);
      void OnOkClick(wxCommandEvent& event);

      static bool ShowToolTips();

   private:

      wxSpecGrid* m_HistoryGrid;
      wxString m_SqlStatement;
      
      bool PopulateStement();
};
/*---------------------------------------------------------------------------*/
#endif   // _SQLHISTORY_H_

