#ifndef _TRIGGERBOOK_H_
#define _TRIGGERBOOK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "triggerbook.h"
#endif
/*---------------------------------------------------------------------------*/
#include "dbbook.h"
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxTriggerBook : public wxDbBook
{
    DECLARE_DYNAMIC_CLASS(wxTriggerBook)
    DECLARE_EVENT_TABLE()

public:

    wxTriggerBook();
    wxTriggerBook(wxWindow* parent, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxTAB_TRAVERSAL);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL);

    ~wxTriggerBook();

    virtual void SetDbObjectName(wxSQLite3Database* db,
                                 const wxString& objectname,
                                 const wxString& base);

    virtual void RefreshDbObject();

protected:

    void Init();
    void CreateControls();
    static bool ShowToolTips();

    void OnCopyClick(wxCommandEvent& event);
    void OnCopyUpdate(wxUpdateUIEvent& event);
    void OnEdRefresh(wxCommandEvent& event);

private:

    wxDDLEditor* m_PageDdl;

};
/*---------------------------------------------------------------------------*/
#endif   // _TRIGGERBOOK_H_

