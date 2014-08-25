
#ifndef _FILTERDLG_H_
#define _FILTERDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "filterdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxFilterDialog: public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxFilterDialog)
   DECLARE_EVENT_TABLE()

   public:

      wxFilterDialog();
      wxFilterDialog(wxWindow* parent, wxWindowID id = -1,
                     const wxString& caption = _("Filter"),
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Filter"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

      ~wxFilterDialog();

      void SetDatabase(wxSQLite3Database* db,
                       const wxString& base = wxEmptyString);
      void SetTable(const wxString& table);

      wxString GetStatement(){return m_Statement;}
      void SetStatement(const wxString& value);

   protected:

      void Init();
      void CreateControls();

      void OnFieldsSelected(wxCommandEvent& event);
      void OnValueUpdate(wxUpdateUIEvent& event);
      void OnBtnAndClick(wxCommandEvent& event);
      void OnBtnOrClick(wxCommandEvent& event);
      void OnBtnOparClick(wxCommandEvent& event);
      void OnBtnCparClick(wxCommandEvent& event);
      void OnClearClick(wxCommandEvent& event);
      void OnClearUpdate(wxUpdateUIEvent& event);
      void OnBtnAddClick(wxCommandEvent& event);
      void OnOkClick(wxCommandEvent& event);

   private:

      wxChoice* m_fields;
      wxChoice* m_operators;
      wxTextCtrl* m_Value;
      wxSQLEditor* m_filter;

      wxSQLite3Database* m_Db;
      wxString m_Base;
      wxString m_Table;
      wxString m_Statement;

};
/*---------------------------------------------------------------------------*/
#endif   // _FILTERDLG_H_

