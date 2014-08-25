#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "sqlparameters.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
/*---------------------------------------------------------------------------*/
#include "sqlparameters.h"
#include "wxsqliteplusapp.h"
/*---------------------------------------------------------------------------*/
#define ID_SCROLLEDWINDOW 15001
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS( wxSQLParametersDialog, wxDialog )
/*---------------------------------------------------------------------------*/
wxSQLParametersDialog::wxSQLParametersDialog()
{
   Init();
}
/*---------------------------------------------------------------------------*/
wxSQLParametersDialog::wxSQLParametersDialog(wxWindow* parent, wxWindowID id,
                                             const wxString& caption,
                                             const wxPoint& pos,
                                             const wxSize& size, long style)
{
   Init();
   Create(parent, id, caption, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxSQLParametersDialog::Create(wxWindow* parent, wxWindowID id,
                                   const wxString& caption, const wxPoint& pos,
                                   const wxSize& size, long style)
{
   SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
   wxDialog::Create( parent, id, caption, pos, size, style );

   CreateControls();
   SetIcon(wxGetApp().GetIcon(ID_ICO_SQLICON));
   Centre();
   return true;
}
/*---------------------------------------------------------------------------*/
wxSQLParametersDialog::~wxSQLParametersDialog()
{
}
/*---------------------------------------------------------------------------*/
void wxSQLParametersDialog::Init()
{
   m_ScrolledWindow = NULL;
}
/*---------------------------------------------------------------------------*/
void wxSQLParametersDialog::CreateControls()
{
   wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
   SetSizer(bSizer1);

   wxBoxSizer* bSizer2 = new wxBoxSizer(wxVERTICAL);
   bSizer1->Add(bSizer2, 1, wxGROW|wxALL, 5);

   wxStaticText* iStatic1 = new wxStaticText(this, wxID_STATIC,
                                             _("Enter the value of the parameters"),
                                             wxDefaultPosition, wxDefaultSize, 0);
   bSizer2->Add(iStatic1, 0, wxALIGN_LEFT|wxALL, 5);

   m_ScrolledWindow = new wxScrolledWindow(this, ID_SCROLLEDWINDOW,
                                           wxDefaultPosition, wxDefaultSize,
                                           wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL|wxTAB_TRAVERSAL);
   bSizer2->Add(m_ScrolledWindow, 1, wxEXPAND);
   m_ScrolledWindow->SetScrollbars(1, 1, 0, 0);
   wxBoxSizer* bSizer3 = new wxBoxSizer(wxVERTICAL);
   m_ScrolledWindow->SetSizer(bSizer3);

   m_FlexSizer = new wxFlexGridSizer(2, 2, 0, 0);
   m_FlexSizer->AddGrowableCol(1);
   bSizer3->Add(m_FlexSizer, 1, wxGROW|wxALL, 5);

   wxStdDialogButtonSizer* dBtnSizer1 = new wxStdDialogButtonSizer;

   bSizer2->Add(dBtnSizer1, 0, wxALIGN_RIGHT|wxALL, 5);
   wxButton* btnOk = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition,
                                  wxDefaultSize, 0);
   btnOk->SetDefault();
   dBtnSizer1->AddButton(btnOk);

   wxButton* btnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"),
                                      wxDefaultPosition, wxDefaultSize, 0);
   dBtnSizer1->AddButton(btnCancel);

   dBtnSizer1->Realize();
}
/*---------------------------------------------------------------------------*/
bool wxSQLParametersDialog::ShowToolTips()
{
   return true;
}
/*---------------------------------------------------------------------------*/
void wxSQLParametersDialog::AddParameter(const wxString& name,
                                         const wxString& value)
{
   wxString pName = name;

   if (pName.IsEmpty())
      pName = _("Unknow");
   if (pName.GetChar(0) == (':') || pName.GetChar(0) == ('$'))
      pName = pName.Mid(1);
   pName += (" : ");

   wxStaticText* itemStatic = new wxStaticText(m_ScrolledWindow, -1, pName,
                                               wxDefaultPosition,
                                               wxDefaultSize, 0);
   m_FlexSizer->Add(itemStatic, 0,
                    wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

   wxTextCtrl* itemText = new wxTextCtrl(m_ScrolledWindow, -1, wxEmptyString,
                                         wxDefaultPosition, wxDefaultSize, 0);
   m_FlexSizer->Add(itemText, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

   itemText->SetValue(value);
   m_PtrArray.Add(itemText);
   if (m_PtrArray.Count() == 1)
      itemText->SetFocus();
   m_ScrolledWindow->FitInside();
}
/*---------------------------------------------------------------------------*/
wxString wxSQLParametersDialog::GetParameter(size_t index)
{
   if (index < m_PtrArray.Count())
   {
      wxTextCtrl* text = (wxTextCtrl*)m_PtrArray.Item(index);
      if (text)
         return text->GetValue();
   }
   return wxEmptyString;
}
/*---------------------------------------------------------------------------*/

