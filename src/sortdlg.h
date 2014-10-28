#ifndef _SORTDLG_H_
#define _SORTDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "sortdlg.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include <wx/arrstr.h>
/*---------------------------------------------------------------------------*/
class wxSortDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxSortDialog)
    DECLARE_EVENT_TABLE()

public:

    wxSortDialog();
    wxSortDialog(wxWindow* parent, wxWindowID id = -1,
                 const wxString& caption = _("Sort"),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("Sort"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);

    ~wxSortDialog();

    wxArrayString GetStringsOrder() {
        return m_StringsOrder;
    }
    void SetStringsOrder(wxArrayString& array);

    void SetDatabase(wxSQLite3Database* db,
                     const wxString& base = wxEmptyString);
    void SetTable(const wxString& table);

protected:

    void Init();
    void CreateControls();

    void OnTorightClick(wxCommandEvent& event);
    void OnTorightUpdate(wxUpdateUIEvent& event);
    void OnAlltorightClick(wxCommandEvent& event);
    void OnAlltorightUpdate(wxUpdateUIEvent& event);
    void OnToleftClick(wxCommandEvent& event);
    void OnToleftUpdate(wxUpdateUIEvent& event);
    void OnAlltoleftClick(wxCommandEvent& event);
    void OnAlltoleftUpdate(wxUpdateUIEvent& event);
    void OnSelectedSelected(wxCommandEvent& event);
    void OnFirstClick(wxCommandEvent& event);
    void OnFirstUpdate(wxUpdateUIEvent& event);
    void OnUpClick(wxCommandEvent& event);
    void OnUpUpdate(wxUpdateUIEvent& event);
    void OnDownClick(wxCommandEvent& event);
    void OnDownUpdate(wxUpdateUIEvent& event);
    void OnLastClick(wxCommandEvent& event);
    void OnLastUpdate(wxUpdateUIEvent& event);
    void OnRbAscSelected(wxCommandEvent& event);
    void OnRbDescSelected(wxCommandEvent& event);
    void OnOkClick(wxCommandEvent& event);

private:

    wxListBox*           m_Available;
    wxBitmapButton*      m_BtnRight;
    wxBitmapButton*      m_BtnAllRight;
    wxBitmapButton*      m_BtnLeft;
    wxBitmapButton*      m_BtnAllLeft;
    wxListBox*           m_Selected;
    wxBitmapButton*      m_BtnTop;
    wxBitmapButton*      m_BtnUp;
    wxBitmapButton*      m_BtnDown;
    wxBitmapButton*      m_BtnBottom;
    wxRadioButton*       m_Ascending;
    wxRadioButton*       m_Descending;

    wxSQLite3Database*   m_Db;
    wxString             m_Base;
    wxString             m_Table;
    wxArrayString        m_StringsOrder;
};
/*---------------------------------------------------------------------------*/
#endif   // _SORTDLG_H_

