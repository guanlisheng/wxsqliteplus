#ifndef _SQLPARAMETERS_H_
#define _SQLPARAMETERS_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "sqlparameters.h"
#endif

/*---------------------------------------------------------------------------*/
#include <wx/dynarray.h>
/*---------------------------------------------------------------------------*/
#define WXSQLPARAMETERSDIALOG_STYLE wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER
/*---------------------------------------------------------------------------*/
class wxSQLParametersDialog: public wxDialog
{
   DECLARE_DYNAMIC_CLASS(wxSQLParametersDialog)

   public:

      wxSQLParametersDialog();
      wxSQLParametersDialog(wxWindow* parent, wxWindowID id = -1,
                            const wxString& caption = _("SQL Parameters"),
                            const wxPoint& pos = wxDefaultPosition,
                            const wxSize& size = wxSize(400, 250),
                            long style = WXSQLPARAMETERSDIALOG_STYLE);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("SQL Parameters"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxSize(400, 250),
                  long style = WXSQLPARAMETERSDIALOG_STYLE);

      ~wxSQLParametersDialog();

      void AddParameter(const wxString& name, const wxString& value = wxEmptyString);
      wxString GetParameter(size_t index);

   protected:

      void Init();
      void CreateControls();

      static bool ShowToolTips();

   private:

      wxScrolledWindow* m_ScrolledWindow;
      wxFlexGridSizer* m_FlexSizer;
      wxArrayPtrVoid m_PtrArray;
};
/*---------------------------------------------------------------------------*/
#endif   // _SQLPARAMETERS_H_

