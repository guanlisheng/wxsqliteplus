#ifndef _DESCRIBEDLG_H_
#define _DESCRIBEDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "describedlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
/*---------------------------------------------------------------------------*/
class wxSpecGrid;
/*---------------------------------------------------------------------------*/
class wxDescribeDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxDescribeDlg)
    DECLARE_EVENT_TABLE()

public:

    wxDescribeDlg();
    wxDescribeDlg(wxWindow* parent, wxWindowID id = -1,
                  const wxString& caption = _("Describe"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxSize(600, 500),
                  long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("Describe"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxSize(600, 500),
                long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

    ~wxDescribeDlg();

    void Describe(wxSQLite3Database* db, const wxString& name,
                  const wxString& base);

protected:

    void Init();
    void CreateControls();
    static bool ShowToolTips();

private:

    wxStaticText* m_DescribeName;
    wxSpecGrid* m_DescribeGrid;
};
/*---------------------------------------------------------------------------*/
#endif   // _DESCRIBEDLG_H_

