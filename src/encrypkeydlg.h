#ifndef _ENCRYPKEYDLG_H_
#define _ENCRYPKEYDLG_H_

#define SYMBOL_DBENCRYPTIONKEYDLG_SIZE wxSize(400, 300)
/*---------------------------------------------------------------------------*/
class wxDbEncryptionKeyDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS(wxDbEncryptionKeyDlg)
    DECLARE_EVENT_TABLE()

public:

    wxDbEncryptionKeyDlg();
    wxDbEncryptionKeyDlg(wxWindow* parent, wxWindowID id = -1,
                         const wxString& caption = _("Database Encryption Key"),
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize,
                         long style = wxDEFAULT_DIALOG_STYLE);

    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxString& caption = _("Database Encryption Key"),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE);

    ~wxDbEncryptionKeyDlg();

    wxString GetKey() const {
        return m_Key;
    }
    void SetKey(wxString value) {
        m_Key = value;
    }

protected:

    void Init();
    void CreateControls();

    static bool ShowToolTips();

private:

    wxTextCtrl* m_EdKey;

    wxString m_Key;

};
/*---------------------------------------------------------------------------*/
#endif   // _ENCRYPKEYDLG_H_
