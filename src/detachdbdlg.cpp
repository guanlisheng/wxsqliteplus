#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "detachdbdlg.h"
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
#include "detachdbdlg.h"
#include "wxsqliteplusapp.h"
/*---------------------------------------------------------------------------*/
#define ID_DATABASESLIST 15001
/*---------------------------------------------------------------------------*/
IMPLEMENT_DYNAMIC_CLASS(wxDetachDbDlg, wxDialog)

BEGIN_EVENT_TABLE(wxDetachDbDlg, wxDialog)
    EVT_BUTTON(wxID_OK, wxDetachDbDlg::OnOkClick)
END_EVENT_TABLE()
/*---------------------------------------------------------------------------*/
wxDetachDbDlg::wxDetachDbDlg()
{
    Init();
}
/*---------------------------------------------------------------------------*/
wxDetachDbDlg::wxDetachDbDlg(wxWindow* parent, wxWindowID id,
                             const wxString& caption, const wxPoint& pos,
                             const wxSize& size, long style)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}
/*---------------------------------------------------------------------------*/
bool wxDetachDbDlg::Create(wxWindow* parent, wxWindowID id,
                           const wxString& caption, const wxPoint& pos,
                           const wxSize& size, long style)
{
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create(parent, id, caption, pos, size, style);

    CreateControls();
    SetIcon(wxGetApp().GetIcon(ID_ICO_DATABASE));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
    return true;
}
/*---------------------------------------------------------------------------*/
wxDetachDbDlg::~wxDetachDbDlg()
{
}
/*---------------------------------------------------------------------------*/
void wxDetachDbDlg::SetDatabase(wxSQLite3Database* db, const wxString& base)
{
    wxSQLite3ResultSet dbQRY;
    wxString alias;

    m_Db = db;
    if (!m_Db||!m_Db->IsOpen())
        m_Db = NULL;
    else
    {
        try
        {
            dbQRY = m_Db->ExecuteQuery(ToUTF8(("PRAGMA database_list;")));
            while (dbQRY.NextRow())
            {
                alias = dbQRY.GetString(1);
                if (alias != ("main") && alias != ("temp"))
                {
                    m_DataBasesList->Append(alias);
                }
            }
            m_DataBasesList->SetStringSelection(base);
        }
        catch(wxSQLite3Exception& ex)
        {
            wxGetApp().ShowError("SetDatabase", ex);
        }
        dbQRY.Finalize();
    }
}
/*---------------------------------------------------------------------------*/
void wxDetachDbDlg::Init()
{
    m_DataBasesList = NULL;
    m_Db = NULL;
}
/*---------------------------------------------------------------------------*/
void wxDetachDbDlg::CreateControls()
{
    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    SetSizer(bSizer1);

    wxStaticText* sText1 = new wxStaticText(this, wxID_STATIC, _("Databases :"),
                                            wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(sText1, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString DbListStr;
    m_DataBasesList = new wxListBox(this, ID_DATABASESLIST, wxDefaultPosition,
                                    wxSize(250, 100), DbListStr, wxLB_EXTENDED);
    bSizer1->Add(m_DataBasesList, 0, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* dlgBtnSizer1 = new wxStdDialogButtonSizer;

    bSizer1->Add(dlgBtnSizer1, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* btnOk = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition,
                                   wxDefaultSize, 0);
    btnOk->SetDefault();
    dlgBtnSizer1->AddButton(btnOk);

    wxButton* btnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"),
                                       wxDefaultPosition, wxDefaultSize, 0);
    dlgBtnSizer1->AddButton(btnCancel);

    dlgBtnSizer1->Realize();
}
/*---------------------------------------------------------------------------*/
int wxDetachDbDlg::GetAliasList(wxArrayString& aliaslist)
{
    wxArrayInt selections;
    int count;

    aliaslist.Clear();

    count = m_DataBasesList->GetSelections(selections);
    for (int i = 0; i < count; i++)
        aliaslist.Add(m_DataBasesList->GetString(selections[i]));
    return count;
}
/*---------------------------------------------------------------------------*/
bool wxDetachDbDlg::ShowToolTips()
{
    return true;
}
/*---------------------------------------------------------------------------*/
void wxDetachDbDlg::OnOkClick(wxCommandEvent& event)
{
    event.Skip();
}
/*---------------------------------------------------------------------------*/

