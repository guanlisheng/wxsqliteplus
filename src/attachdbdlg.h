#ifndef _ATTACHDBDLG_H_
#define _ATTACHDBDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "attachdbdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
/*---------------------------------------------------------------------------*/
class wxAttachDbDlg: public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxAttachDbDlg)
   DECLARE_EVENT_TABLE()

   public:

      wxAttachDbDlg();
      wxAttachDbDlg(wxWindow* parent, wxWindowID id = -1,
                    const wxString& caption = _("Attach Database"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Attach Database"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxAttachDbDlg();

      void SetDatabase(wxSQLite3Database* db);

      wxString GetFileName() const {return m_FileName;}
      void SetFileName(wxString value) {m_FileName = value;}

      wxString GetAlias() const {return m_Alias;}
      void SetAlias(wxString value) {m_Alias = value;}

      wxString GetKey() const {return m_Key;}
      void SetKey(wxString value) {m_Key = value;}

      void OnlyKey();

   protected:

      void Init();
      void CreateControls();

      void OnAttachbtnClick(wxCommandEvent& event);
      void OnOkClick(wxCommandEvent& event);
      void OnChar(wxKeyEvent& event);


      static bool ShowToolTips();

   private:

      wxBitmapButton*   m_BtnAttach;
      wxTextCtrl*       m_EdFilename;
      wxTextCtrl*       m_EdAlias;
      wxTextCtrl*       m_EdKey;

      wxString m_FileName;
      wxString m_Alias;
      wxString m_Key;

      wxSQLite3Database* m_Db;
};
/*---------------------------------------------------------------------------*/
#endif   // _ATTACHDBDLG_H_

