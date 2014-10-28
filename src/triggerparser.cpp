#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "triggerparser.h"
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
#include "triggerparser.h"
/*---------------------------------------------------------------------------*/
wxCreateTrigerParserMinimal::wxCreateTrigerParserMinimal(const wxString& ddl)
{
    m_Ddl = ddl;
    m_CharPos = 0;
    Analyze();
}
/*---------------------------------------------------------------------------*/
void wxCreateTrigerParserMinimal::Analyze()
{
    wxString token, afterbefore;

    token = GetNextToken().Upper();

    if (token == ("CREATE"))
    {
        token = GetNextToken().Upper();
        if (token == ("TEMP")||token == ("TEMPORARY"))
            token = GetNextToken().Upper();
        if (token == ("TRIGGER"))
        {
            token = GetNextToken().Upper();
            if (token == ("IF"))
            {
                token = GetNextToken().Upper();
                if (token == ("NOT"))
                {
                    token = GetNextToken().Upper();
                    if (token == ("EXISTS"))
                        token = GetNextToken().Upper();
                    else
                        return;
                }
                else
                    return;
                // Get The Trigger Name
                token = GetNextToken();
            }
            token = GetNextToken().Upper();
            if (token == ("BEFORE")||token == ("AFTER"))
            {
                m_Event = token + (" ");
                token = GetNextToken().Upper();
            }
            m_Event += token;
            if (token == ("UPDATE"))
            {
                token = GetNextToken().Upper();
                if (token == ("OF"))
                {
                    m_Event += (" OF");
                    m_Column = GetNextToken();
                }
            }
            else if (token == ("INSTEAD"))
            {
                token = GetNextToken().Upper();
                if (token == ("OF"))
                {
                    m_Event = ("INSTEAD OF");
                    token = GetNextToken().Upper();
                    m_Column = token;
                    if (token == ("UPDATE"))
                    {
                        token = GetNextToken().Upper();
                        if (token == ("OF"))
                        {
                            m_Column += (" OF ");
                            m_Column += GetNextToken();
                        }
                    }
                }
            }
        }
    }
    /*
    sql-statement ::= 	CREATE [TEMP | TEMPORARY] TRIGGER [IF NOT EXISTS] trigger-name [ BEFORE | AFTER ]
    database-event ON [database-name .] table-name
    trigger-action
    sql-statement ::= 	CREATE [TEMP | TEMPORARY] TRIGGER [IF NOT EXISTS] trigger-name INSTEAD OF
    database-event ON [database-name .] view-name
    trigger-action
    database-event ::= 	DELETE | INSERT | UPDATE | UPDATE OF column-list
    */
}
/*---------------------------------------------------------------------------*/
wxString wxCreateTrigerParserMinimal::GetNextToken()
{
    wxChar c, cm;

    m_CurrentToken = wxEmptyString;
    ToStartToken();

    c = m_Ddl[m_CharPos];
    if (c == ('\'')||c == ('\"'))
    {
        cm = c;
        m_CurrentToken += GetNextChar();
        c = m_Ddl[m_CharPos];
        while (c != cm)
        {
            m_CurrentToken += GetNextChar();
            c = m_Ddl[m_CharPos];
        }
        m_CurrentToken += GetNextChar();
    }
    else
    {
        while (!CurrentCharIsBlank())
            m_CurrentToken += GetNextChar();
    }
    return m_CurrentToken;
}
/*---------------------------------------------------------------------------*/
wxChar wxCreateTrigerParserMinimal::GetNextChar()
{
    if (m_CharPos < m_Ddl.Length())
        return m_Ddl[m_CharPos++];
    return wxChar(0);
}
/*---------------------------------------------------------------------------*/
void wxCreateTrigerParserMinimal::ToStartToken()
{
    wxChar c;
    size_t l;

    l = m_Ddl.Length();
    c = m_Ddl[m_CharPos];
    while (CurrentCharIsBlank() && m_CharPos < l)
        c = m_Ddl[++m_CharPos];
}
/*---------------------------------------------------------------------------*/
bool wxCreateTrigerParserMinimal::CurrentCharIsBlank()
{
    wxChar c;
    c = m_Ddl[m_CharPos];

    return (c == (' ') || c == ('\t') || c == ('\r') || c == ('\n'));
}
/*---------------------------------------------------------------------------*/

