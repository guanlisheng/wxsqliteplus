#ifndef _ADDCOLUMN_H_
#define _ADDCOLUMN_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "addcolumn.h"
#endif
/*---------------------------------------------------------------------------*/
#include "createtable.h"
/*---------------------------------------------------------------------------*/
class wxGridAddColumnsTable : public wxGridColumnsTable
{
public:

    wxGridAddColumnsTable();

    void SetExistingColumnsName(const wxArrayString& colsname);

protected:

    virtual bool CheckName(const wxString& name, int row = -1);

private:

    wxArrayString m_ExistingColumnsName;

};
/*---------------------------------------------------------------------------*/
class wxAddColumnDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxAddColumnDialog)
    DECLARE_EVENT_TABLE()

public:

    wxAddColumnDialog();
    wxAddColumnDialog(wxWindow* parent, wxWindowID id = -1,
                      const wxString& caption = _("Add Column"),
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxSize(400, 300),
                      long style = wxDEFAULT_DIALOG_STYLE);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("Add Column"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxSize(400, 300),
                long style = wxDEFAULT_DIALOG_STYLE);

    ~wxAddColumnDialog();

    wxString GetAddColumnsDDL();
    wxArrayString GetAddColumnsScript();

    void SetDatabase(wxSQLite3Database* db,
                     const wxString& base = wxEmptyString);
    void SetTable(const wxString& table);

protected:

    void Init();
    void CreateControls();

    void OnTablenameSelected(wxCommandEvent& event);
    void OnBookPageChanging(wxNotebookEvent& event);
    void OnGridChar(wxKeyEvent& event);
    void OnBtnAddcolumnClick(wxCommandEvent& event);
    void OnBtnDelcolumnClick(wxCommandEvent& event);
    void OnBtnDelcolumnUpdate(wxUpdateUIEvent& event);
    void OnOkClick(wxCommandEvent& event);

    static bool ShowToolTips();

private:

    wxChoice* m_ChoiceTableName;
    wxGrid* m_GridColumns;
    wxDDLEditor* m_TextDdl;
    wxButton* m_BtnAddColumn;

    wxSQLite3Database* m_Db;
    wxString m_Base;
    wxGridAddColumnsTable m_TableColumns;

    void DoTablenameSelected();
};
/*---------------------------------------------------------------------------*/
#endif   // _ADDCOLUMN_H_

