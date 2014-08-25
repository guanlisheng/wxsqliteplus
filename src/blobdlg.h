#ifndef _BLOBDLG_H_
#define _BLOBDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "blobdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/notebook.h>
/*---------------------------------------------------------------------------*/
class wxRichTextCtrl;
class wxMemoryBuffer;
/*---------------------------------------------------------------------------*/
class wxBlobDialog : public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxBlobDialog)
   DECLARE_EVENT_TABLE()

   public:

      wxBlobDialog();
      wxBlobDialog(wxWindow* parent, wxWindowID id = -1,
                   const wxString& caption = _("Blob"),
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxSize(450, 400),
                   long style = wxDEFAULT_DIALOG_STYLE|
                                wxRESIZE_BORDER|wxTAB_TRAVERSAL);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Blob"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxSize(450, 400),
                  long style = wxDEFAULT_DIALOG_STYLE|
                               wxRESIZE_BORDER|wxTAB_TRAVERSAL);

      ~wxBlobDialog();

      void SetBlob(wxMemoryBuffer* buffer);

   protected:

      void Init();
      void CreateControls();

      void OnBtnSaveasClick(wxCommandEvent& event);

      static bool ShowToolTips();

   private:

      wxNotebook* m_Notebook;
      wxStaticText* m_BlobLen;
      wxTextCtrl* m_EditHexa;
      wxRichTextCtrl* m_EditText;
      wxStaticBitmap* m_Image;
      wxStaticText* m_RealSize;
      bool m_FlagBin;
      bool m_FlagBmp;

      wxString GetHexaString(wxMemoryBuffer* buffer);
      wxSize RescaleImage(int width, int height);
};
/*---------------------------------------------------------------------------*/
#endif   // _BLOBDLG_H_
