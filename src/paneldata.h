#ifndef _PANELDATA_H_
#define _PANELDATA_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "paneldata.h"
#endif
/*---------------------------------------------------------------------------*/
#include "dbbook.h"
/*---------------------------------------------------------------------------*/
class wxDataGrid;
/*---------------------------------------------------------------------------*/
class wxPanelData : public wxPanel
{
   DECLARE_DYNAMIC_CLASS(wxPanelData)
   DECLARE_EVENT_TABLE()

   public:

      wxPanelData();
      wxPanelData(wxWindow* parent, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxTAB_TRAVERSAL);

      bool Create(wxWindow* parent, wxWindowID id = -1,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxTAB_TRAVERSAL);

      ~wxPanelData();

      void SetDbTableViewName(wxSQLite3Database* db,
                              const wxString& objectname,
                              const wxString& base = wxEmptyString);

      bool HasFocus();

      void DoRefresh(bool usefilter = false);

   protected:

      void Init();
      void CreateControls();

      void OnMnuFilterClick(wxCommandEvent& event);
      void OnMnuSortClick(wxCommandEvent& event);
      void OnMnuRefreshClick(wxCommandEvent& event);
      void OnStaticUpdate(wxUpdateUIEvent& event);

   private:

      wxStaticText* m_active;
      wxDataGrid* m_DataGrid;
};

#endif   // _PANELDATA_H_

