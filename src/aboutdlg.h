#ifndef _ABOUTDLG_H_
#define _ABOUTDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "aboutdlg.h"
#endif
/*---------------------------------------------------------------------------*/
class wxAboutDlg: public wxDialog
{    
   DECLARE_DYNAMIC_CLASS(wxAboutDlg)
   DECLARE_EVENT_TABLE()

   public:

      wxAboutDlg();
      wxAboutDlg(wxWindow* parent, wxWindowID id = -1,
                 const wxString& caption = _("About %s"),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxDEFAULT_DIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("About %s"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

      ~wxAboutDlg();

   protected:

      void Init();
      void CreateControls();
      static bool ShowToolTips();

   private:

      wxStaticText* m_AppName;
      wxStaticText* m_AppDescription;
      wxStaticText* m_AppCopyright;
};
/*---------------------------------------------------------------------------*/
#endif   // _ABOUTDLG_H_

