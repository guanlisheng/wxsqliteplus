#ifndef _DROPOBJECT_H_
#define _DROPOBJECT_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dropobject.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include "sqliteplusframe.h"
/*---------------------------------------------------------------------------*/
#define WXDROPOBJECT_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
/*---------------------------------------------------------------------------*/
class wxDropObject: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxDropObject)
    DECLARE_EVENT_TABLE()

public:

    wxDropObject();
    wxDropObject(wxWindow* parent, wxWindowID id = -1,
                 const wxString& caption = _("DROP Object"),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize(250, 200),
                 long style = WXDROPOBJECT_STYLE);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("DROP Object"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxSize(250, 200),
                long style = WXDROPOBJECT_STYLE);

    void SetDatabase(wxSQLite3Database* db,
                     const wxString& base = wxEmptyString);

    void DisableType();
    void DisableName();

    ~wxDropObject();

    wxSQLiteObjectType GetObjectType() const;
    void SetObjectType(wxSQLiteObjectType value);

    wxString GetObjectName() const {
        return m_ObjectName;
    }
    void SetObjectName(wxString value) {
        m_ObjectName = value;
    }

protected:

    void Init();
    void CreateControls();

    void OnObjTypeSelected( wxCommandEvent& event );
    void OnOkClick( wxCommandEvent& event );

    static bool ShowToolTips();

private:

    wxChoice* m_ChoiceObjType;
    wxChoice* m_TextObjName;
    wxString m_ObjectType;
    wxString m_ObjectName;

    wxSQLite3Database* m_Db;
    wxString m_Base;

    void PopulateNameList(wxSQLiteObjectType objecttype);
};
/*---------------------------------------------------------------------------*/
#endif   // _DROPOBJECT_H_

