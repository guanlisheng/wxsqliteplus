#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "encrypkeydlg.h"
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
#include "encrypkeydlg.h"
/*---------------------------------------------------------------------------*/
#define ID_KEY       15001
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS(wxDbEncryptionKeyDlg, wxDialog)

BEGIN_EVENT_TABLE(wxDbEncryptionKeyDlg, wxDialog)
END_EVENT_TABLE()
/*---------------------------------------------------------------------------*/
wxDbEncryptionKeyDlg::wxDbEncryptionKeyDlg()
{
    Init();
}
/*---------------------------------------------------------------------------*/
wxDbEncryptionKeyDlg::wxDbEncryptionKeyDlg(wxWindow* parent, wxWindowID id,
        const wxString& caption,
        const wxPoint& pos,
        const wxSize& size, long style)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxDbEncryptionKeyDlg::Create(wxWindow* parent, wxWindowID id,
                                  const wxString& caption, const wxPoint& pos,
                                  const wxSize& size, long style)
{
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create(parent, id, caption, pos, size, style);

    CreateControls();
    if (GetSizer())
        GetSizer()->SetSizeHints(this);
    Centre();
    return true;
}
/*---------------------------------------------------------------------------*/
wxDbEncryptionKeyDlg::~wxDbEncryptionKeyDlg()
{
}
/*---------------------------------------------------------------------------*/
void wxDbEncryptionKeyDlg::Init()
{
    m_EdKey = NULL;
}
/*---------------------------------------------------------------------------*/
void wxDbEncryptionKeyDlg::CreateControls()
{
    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    SetSizer(bSizer1);

    wxStaticText* sText1 = new wxStaticText(this, wxID_STATIC,
                                            _("Enter encryption key (let empty for no encryption)"),
                                            wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(sText1, 0, wxALIGN_LEFT|wxALL, 5);

    m_EdKey = new wxTextCtrl(this, ID_KEY, wxEmptyString, wxDefaultPosition,
                             wxSize(250, -1), wxTE_PASSWORD);
    bSizer1->Add(m_EdKey, 0, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* dlgBtnSizer1 = new wxStdDialogButtonSizer;

    bSizer1->Add(dlgBtnSizer1, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* btnOk = new wxButton(this, wxID_OK, _("&OK"),
                                   wxDefaultPosition, wxDefaultSize, 0);
    btnOk->SetDefault();
    dlgBtnSizer1->AddButton(btnOk);

    wxButton* btnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"),
                                       wxDefaultPosition, wxDefaultSize, 0);
    dlgBtnSizer1->AddButton(btnCancel);

    dlgBtnSizer1->Realize();

    // Set validators
    m_EdKey->SetValidator(wxTextValidator(wxFILTER_NONE, &m_Key));

    m_EdKey->SetFocus();
}
/*---------------------------------------------------------------------------*/
bool wxDbEncryptionKeyDlg::ShowToolTips()
{
    return true;
}
/*---------------------------------------------------------------------------*/
