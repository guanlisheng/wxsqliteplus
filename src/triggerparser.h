#ifndef _TRIGGERPARSER_H_
#define _TRIGGERPARSER_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "triggerparser.h"
#endif
/*---------------------------------------------------------------------------*/
class wxCreateTrigerParserMinimal
{
public:

    wxCreateTrigerParserMinimal(const wxString& ddl);

    wxString GetEvent() const {
        return m_Event;
    }
    wxString GetColumn() const {
        return m_Column;
    }

private:

    wxString m_Ddl;
    wxString m_Event;
    wxString m_Column;
    wxString m_CurrentToken;
    size_t m_CharPos;

    void Analyze();
    wxString GetNextToken();
    wxChar GetNextChar();
    void ToStartToken();
    bool CurrentCharIsBlank();
};
/*---------------------------------------------------------------------------*/
#endif   // _TRIGGERPARSER_H_

