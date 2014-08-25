#ifndef _DETACHDBDLG_H_
#define _DETACHDBDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "detachdbdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
/*---------------------------------------------------------------------------*/
class wxDetachDbDlg: public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxDetachDbDlg)
   DECLARE_EVENT_TABLE()

   public:

      wxDetachDbDlg();
      wxDetachDbDlg(wxWindow* parent, wxWindowID id = -1,
                    const wxString& caption = _("Detach Database"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Detach Database"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxDetachDbDlg();

      void SetDatabase(wxSQLite3Database* db,
                       const wxString& base = wxEmptyString);

       int GetAliasList(wxArrayString& aliaslist);

   protected:

      void Init();
      void CreateControls();

      void OnOkClick(wxCommandEvent& event);

      static bool ShowToolTips();

   private:

      wxListBox* m_DataBasesList;

      wxSQLite3Database* m_Db;
};
/*---------------------------------------------------------------------------*/
#endif   // _DETACHDBDLG_H_

