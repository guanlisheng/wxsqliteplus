#ifndef _DBBOOK_H_
#define _DBBOOK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dbbook.h"
#endif
/*---------------------------------------------------------------------------*/
class wxSQLite3Database;
/*---------------------------------------------------------------------------*/
class wxDbBook : public wxPanel
{
    DECLARE_CLASS(wxDbBook)

public:

    wxDbBook();
    wxDbBook(wxWindow* parent, wxWindowID id = -1,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxTAB_TRAVERSAL);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL);

    virtual ~wxDbBook();

    virtual void SetDbObjectName(wxSQLite3Database* db,
                                 const wxString& objectname,
                                 const wxString& base = wxEmptyString);


    virtual void RefreshDbObject() = 0;

    wxString GetObjectName() const {
        return m_DbObjectName;
    }
    wxString GetBaseName() const {
        return m_Base;
    }

protected:

    void Init();

    wxSQLite3Database* m_db;
    wxString m_Base;
    wxString m_DbObjectName;
};
/*---------------------------------------------------------------------------*/
#endif   // _DBBOOK_H_

