#ifndef _CREATEVIEW_H_
#define _CREATEVIEW_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "createview.h"
#endif

/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include <wx/notebook.h>
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxCreateViewDialog: public wxDialog
{    
   DECLARE_DYNAMIC_CLASS(wxCreateViewDialog)
   DECLARE_EVENT_TABLE()

   public:

      wxCreateViewDialog();
      wxCreateViewDialog(wxWindow* parent, wxWindowID id = -1,
                         const wxString& caption = _("Create View"),
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize,
                         long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Create View"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxCreateViewDialog();

      wxString GetCreateViewDDL();

      void SetDatabase(wxSQLite3Database* db,
                       const wxString& base = wxEmptyString);

      bool GetTemporary() const {return m_Temporary;}
      
   protected:

      void Init();
      void CreateControls();

      void OnChar(wxKeyEvent& event);
      void OnNotebookPageChanging(wxNotebookEvent& event);
      void OnBtnTestClick(wxCommandEvent& event);
      void OnBtnTestUpdate(wxUpdateUIEvent& event);
      void OnOkClick(wxCommandEvent& event);

      static bool ShowToolTips();

   private:

      wxTextCtrl* m_ViewName;
      wxCheckBox* m_TempView;
      wxSQLEditor* m_ViewQuery;
      wxTextCtrl* m_ParseResults;
      wxDDLEditor* m_TextDdl;

      wxSQLite3Database* m_Db;
      wxString m_Base;
      wxString m_QueryError;
      bool m_Temporary;

      bool CheckViewQuery(const wxString& query);
};
/*---------------------------------------------------------------------------*/
#endif   // _CREATEVIEW_H_

