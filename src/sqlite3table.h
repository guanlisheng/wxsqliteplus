#ifndef _SQLITE3TABLE_H_
#define _SQLITE3TABLE_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "sqlite3table.h"
#endif
/*---------------------------------------------------------------------------*/
#include <wx/wxsqlite3.h>
#include <wx/grid.h>
#include <wx/dynarray.h>
/*---------------------------------------------------------------------------*/
#ifdef WXMAKINGDLL_WXSQLITE3TABLE
    #define WXDLLIMPEXP_SQLITE3TABLE WXEXPORT
#elif defined(WXUSINGDLL_WXSQLITE3TABLE)
    #define WXDLLIMPEXP_SQLITE3TABLE WXIMPORT
#else // not making nor using DLL
    #define WXDLLIMPEXP_SQLITE3TABLE
#endif
/*---------------------------------------------------------------------------*/
class wxSQLite3TableColumn;
WX_DEFINE_ARRAY(wxSQLite3TableColumn*, wxArraySQLite3TableColumn);
/*---------------------------------------------------------------------------*/
class SQLite3HookForCount : public wxSQLite3Hook
{
   public:

      virtual void UpdateCallback(wxUpdateType type,
                                  const wxString& database,
                                  const wxString& table,
                                  wxLongLong rowid)
      {
         switch (type)
         {
            case SQLITE_DELETE:
               m_NbRowDeleted++;
               break;
            case SQLITE_INSERT:
               m_NbRowInserted++;
               break;
            case SQLITE_UPDATE:
               m_NbRowUpdated++;
               break;
         }
      }

      void Clear()
      {
         m_NbRowUpdated = m_NbRowDeleted = m_NbRowInserted = 0;
      }

      int GetNbRowUpdated(){return m_NbRowUpdated;}
      int GetNbRowDeleted(){return m_NbRowDeleted;}
      int GetNbRowInserted(){return m_NbRowInserted;}

   private:

      int m_NbRowUpdated;
      int m_NbRowDeleted;
      int m_NbRowInserted;
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE OddRowsGridCellAttrProvider : public wxGridCellAttrProvider
{
   public:

      OddRowsGridCellAttrProvider(wxColour colour);
      virtual ~OddRowsGridCellAttrProvider();

      virtual wxGridCellAttr *GetAttr(int row, int col,
                                      wxGridCellAttr::wxAttrKind  kind) const;

   private:

      wxGridCellAttr *m_attrForOddRows;
      wxColour m_OddColour;
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridEmptyTable : public wxGridTableBase
{
   public:

      wxGridEmptyTable(){}

      int GetNumberRows(){return 0;}
      int GetNumberCols(){return 0;}
      wxString GetValue(int row, int col) {return wxEmptyString;}

      void SetValue(int , int , const wxString&) { /* ignore */ }
      bool IsEmptyCell(int , int) {return true;}
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridSQLite3TableBase : public wxGridTableBase
{
   public:

      wxGridSQLite3TableBase();

      virtual ~wxGridSQLite3TableBase();

      virtual int GetNumberRows() {return m_NumberRows;}
      virtual int GetNumberCols() {return m_NumberCols;}
      virtual bool IsEmptyCell(int row, int col);
      virtual wxString GetValue(int row, int col);
      virtual void SetValue(int row, int col, const wxString& value);
      virtual wxString GetColLabelValue(int col);
      virtual wxString GetTypeName(int row, int col);

      virtual void SetView(wxGrid* grid);

      void AdaptColumnsSize();

      void SetFloatWidth(int value){m_FloatWidth = value;}
      int GetFloatWidth() const {return m_FloatWidth;}
      void SetFloatPrecision(int value){m_FloatPrecision = value;}
      int GetFloatPrecision() const {return m_FloatPrecision;}

   protected:

      void Init();

      int m_CharWidth;
      int m_NumberRows;
      int m_NumberCols;
      int m_FloatWidth;
      int m_FloatPrecision;
      wxArraySQLite3TableColumn m_ArrayColumn;

      virtual void PopulateArray(wxSQLite3ResultSet* resultSet);

};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridSQLite3Table : public wxGridSQLite3TableBase
{
   public:

      wxGridSQLite3Table(wxSQLite3ResultSet* resultSet);
      wxGridSQLite3Table(wxSQLite3Database* db, const wxString& tablename,
                         const wxString& base = wxEmptyString);

      bool GetBlob(size_t row, size_t col, wxMemoryBuffer*& buffer);

   protected:

      wxString m_TableName;

      wxSQLite3ResultSet GetResultSet(wxSQLite3Database* db,
                                      const wxString& base = wxEmptyString);
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridTblIndexesTable : public wxGridSQLite3TableBase
{
   public:

      wxGridTblIndexesTable(wxSQLite3Database* db, const wxString& tablename,
                            const wxString& base = wxEmptyString);

      virtual wxString GetTypeName(int row, int col);
      virtual wxString GetValue(int row, int col);

   protected:

      wxSQLite3ResultSet GetResultSet(wxSQLite3Database* db,
                                      const wxString& tablename,
                                      const wxString& base = wxEmptyString);
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridTblColumnsTable : public wxGridSQLite3TableBase
{
   public:

      wxGridTblColumnsTable(wxSQLite3Database* db, const wxString& tablename,
                            const wxString& base = wxEmptyString);

      virtual wxString GetTypeName(int row, int col);
      virtual wxString GetValue(int row, int col);

   protected:

      wxSQLite3ResultSet GetResultSet(wxSQLite3Database* db,
                                      const wxString& tablename,
                                      const wxString& base = wxEmptyString);
};
/*---------------------------------------------------------------------------*/
class WXDLLIMPEXP_SQLITE3TABLE wxGridTriggerTable : public wxGridSQLite3TableBase
{
   public:

      wxGridTriggerTable(wxSQLite3Database* db, const wxString& tablename,
                         const wxString& base = wxEmptyString);

   protected:

      virtual void PopulateArray(wxSQLite3ResultSet* resultSet);
      wxSQLite3ResultSet GetResultSet(wxSQLite3Database* db,
                                      const wxString& tablename,
                                      const wxString& base = wxEmptyString);

};
/*---------------------------------------------------------------------------*/
extern wxGridEmptyTable g_EmptyTable;
/*---------------------------------------------------------------------------*/
#endif // _SQLITE3TABLE_H_


