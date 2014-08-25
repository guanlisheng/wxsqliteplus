#ifndef _BACKRESTDLG_H_
#define _BACKRESTDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "backrestdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
/*---------------------------------------------------------------------------*/
class wxBackupRestoreDbDlg: public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxBackupRestoreDbDlg)
   DECLARE_EVENT_TABLE()

   public:

      wxBackupRestoreDbDlg();
      wxBackupRestoreDbDlg(wxWindow* parent, bool backup,
                           wxWindowID id = -1,
                           const wxPoint& pos = wxDefaultPosition,
                           const wxSize& size = wxDefaultSize,
                           long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, bool backup, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxBackupRestoreDbDlg();

      wxString GetFileName() const {return m_FileName;}
      void SetFileName(wxString value) {m_FileName = value;}

      wxString GetAlias() const {return m_Alias;}
      void SetAlias(wxString value) {m_Alias = value;}

      wxString GetKey() const {return m_Key;}
      void SetKey(wxString value) {m_Key = value;}

      void SetDatabase(wxSQLite3Database* db,
                       const wxString& base = wxEmptyString);

   protected:

      void Init();
      void CreateControls();
      void OnGetfilebtnClick(wxCommandEvent& event);
      void OnOkClick(wxCommandEvent& event);

      static bool ShowToolTips();

   private:

      wxTextCtrl* m_EdFilename;
      wxTextCtrl* m_EdKey;
      wxChoice* m_Database;

      wxString m_Key;
      wxString m_FileName;
      wxString m_Alias;

      wxSQLite3Database* m_Db;
      bool m_BackUp;
};
/*---------------------------------------------------------------------------*/
#endif   // _BACKRESTDLG_H_
