#ifndef _VIEWBOOK_H_
#define _VIEWBOOK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "viewbook.h"
#endif
/*---------------------------------------------------------------------------*/
#include "dbbook.h"
#include "sqleditor.h"
/*---------------------------------------------------------------------------*/
class wxAuiNotebook;
class wxSpecGrid;
class wxPanelData;
class wxSQLite3Database;
/*---------------------------------------------------------------------------*/
class wxViewBook: public wxDbBook
{
    DECLARE_DYNAMIC_CLASS(wxViewBook)
    DECLARE_EVENT_TABLE()

public:

    wxViewBook();
    wxViewBook(wxWindow* parent, wxWindowID id = -1,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTAB_TRAVERSAL);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL);

    ~wxViewBook();

    virtual void SetDbObjectName(wxSQLite3Database* db,
                                 const wxString& objectname,
                                 const wxString& base);

    virtual void RefreshDbObject();

protected:

    void Init();
    void CreateControls();
    static bool ShowToolTips();

    void OnViewebookPageChanging(wxAuiNotebookEvent& event);
    void OnCopyClick(wxCommandEvent& event);
    void OnCopyUpdate(wxUpdateUIEvent& event);
    void OnEdRefresh(wxCommandEvent& event);

private:
    wxAuiNotebook* m_Book;
    wxSpecGrid* m_PageColumns;
    wxPanelData* m_PageData;
    wxDDLEditor* m_PageDdl;
    bool m_InitData;

    void RefreshStruct();
    void RefreshData();
};
/*---------------------------------------------------------------------------*/
#endif   // _VIEWBOOK_H_

