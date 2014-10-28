#ifndef _TABLEBOOK_H_
#define _TABLEBOOK_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "tablebook.h"
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
class wxTableBook: public wxDbBook
{
    DECLARE_DYNAMIC_CLASS(wxTableBook)
    DECLARE_EVENT_TABLE()

public:

    wxTableBook();
    wxTableBook(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL);

    ~wxTableBook();

    virtual void SetDbObjectName(wxSQLite3Database* db,
                                 const wxString& objectname,
                                 const wxString& base = wxEmptyString);

    virtual void RefreshDbObject();

protected:

    void Init();
    void CreateControls();
    static bool ShowToolTips();

    void OnTablebookPageChanging( wxAuiNotebookEvent& event );
    void OnCopyClick(wxCommandEvent& event);
    void OnCopyUpdate(wxUpdateUIEvent& event);
    void OnEdRefresh(wxCommandEvent& event);

private:

    wxAuiNotebook* m_Book;
    wxSpecGrid* m_PageColumns;
    wxPanelData* m_PageData;
    wxSpecGrid* m_PageForeignKey;
    wxSpecGrid* m_PageTriggers;
    wxSpecGrid* m_PageIndexes;
    wxDDLEditor* m_PageDdl;
    bool m_InitData;

    void RefreshStruct();
    void RefreshData();
};
/*---------------------------------------------------------------------------*/
#endif   // _TABLEBOOK_H_

