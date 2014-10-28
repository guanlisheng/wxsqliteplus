#ifndef _CREATETRIGGER_H_
#define _CREATETRIGGER_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "createtrigger.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxCreateTriggerDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxCreateTriggerDialog)
    DECLARE_EVENT_TABLE()

public:

    wxCreateTriggerDialog();
    wxCreateTriggerDialog(wxWindow* parent, wxWindowID id = -1,
                          const wxString& caption = _("Create Trigger"),
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize,
                          long style = wxDEFAULT_DIALOG_STYLE);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("Create Trigger"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE);

    ~wxCreateTriggerDialog();

    wxString GetCreateTriggerDDL();

    void SetDatabase(wxSQLite3Database* db,
                     const wxString& base = wxEmptyString);
    void SetObject(const wxString& objname, bool table = true);

    bool GetTemporary() const {
        return m_Temporary;
    }

protected:

    void Init();
    void CreateControls();

    void OnChar(wxKeyEvent& event);
    void OnNotebookPageChanging(wxNotebookEvent& event);
    void OnTypeObjSelected(wxCommandEvent& event);
    void OnObjNameSelected(wxCommandEvent& event);
    void OnTriggerEventSelected(wxCommandEvent& event);
    void OnAddcolumnClick(wxCommandEvent& event);
    void OnAddcolumnUpdate(wxUpdateUIEvent& event);
    void OnAddallcolumnsClick(wxCommandEvent& event);
    void OnAddallcolumnsUpdate(wxUpdateUIEvent& event);
    void OnRemovecolumnClick(wxCommandEvent& event);
    void OnRemovecolumnUpdate(wxUpdateUIEvent& event);
    void OnRemoveallcolumnsClick(wxCommandEvent& event);
    void OnRemoveallcolumnsUpdate(wxUpdateUIEvent& event);
    void OnOkClick(wxCommandEvent& event);

    static bool ShowToolTips();

private:

    wxTextCtrl* m_TriggerName;
    wxCheckBox* m_TempTrigger;
    wxChoice* m_TypeObj;
    wxChoice* m_ObjName;
    wxChoice* m_TriggerTime;
    wxChoice* m_TriggerEvent;
    wxListBox* m_AvailableColumns;
    wxBitmapButton* m_BtnAddColumn;
    wxBitmapButton* m_BtnAddAllColumns;
    wxBitmapButton* m_BtnRemoveColumn;
    wxBitmapButton* m_BtnRemoveAllColumns;
    wxListBox* m_SelectedColumns;
    wxCheckBox* m_ForEachRow;
    wxTextCtrl* m_When;
    // wxTextCtrl* m_Statement;
    wxSQLEditor* m_Statement;
    wxDDLEditor* m_TextDdl;

    wxSQLite3Database* m_Db;
    wxString m_Base;
    bool m_Temporary;

    void PopulateObjName();
    void PopulateColumns();
    void DoEnableColumns();
};
/*---------------------------------------------------------------------------*/
#endif   // _CREATETRIGGER_H_

