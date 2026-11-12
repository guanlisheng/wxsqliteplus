#ifndef WXSQLITEPLUS_MODERNICONS_H
#define WXSQLITEPLUS_MODERNICONS_H

#include "sqliteplusdef.h"

#ifdef wxHAS_SVG
namespace
{
#define ICON(body) \
    "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"20\" height=\"20\" viewBox=\"0 0 20 20\">" \
    "<g fill=\"none\" stroke=\"#3979b5\" stroke-width=\"1.6\" stroke-linecap=\"round\" stroke-linejoin=\"round\">" \
    body "</g></svg>"
#define TABLE_SHAPE "<rect x=\"2.5\" y=\"3.5\" width=\"15\" height=\"13\" rx=\"1\"/><path d=\"M2.5 8h15M8 8v8.5M13 8v8.5\"/>"
#define VIEW_SHAPE "<path d=\"M2 10s3-4.5 8-4.5 8 4.5 8 4.5-3 4.5-8 4.5S2 10 2 10z\"/><circle cx=\"10\" cy=\"10\" r=\"2\"/>"
#define INDEX_SHAPE "<path d=\"M4 3v14M9 3v14M14 3v14M2 6h14M2 11h14M2 16h14\"/>"
#define TRIGGER_SHAPE "<path d=\"M11 2 5 11h4l-1 7 7-10h-4z\"/>"
#define DATABASE_SHAPE "<ellipse cx=\"10\" cy=\"4.5\" rx=\"6\" ry=\"2.5\"/><path d=\"M4 4.5v10.5c0 1.4 2.7 2.5 6 2.5s6-1.1 6-2.5V4.5M4 9.5c0 1.4 2.7 2.5 6 2.5s6-1.1 6-2.5\"/>"
#define ADD_BADGE "<circle cx=\"15\" cy=\"15\" r=\"4\" fill=\"#21834a\" stroke=\"white\"/><path d=\"M15 13v4m-2-2h4\" stroke=\"white\"/>"
#define DROP_BADGE "<circle cx=\"15\" cy=\"15\" r=\"4\" fill=\"#c64343\" stroke=\"white\"/><path d=\"M13 15h4\" stroke=\"white\"/>"
#define TEMP_BADGE "<circle cx=\"15\" cy=\"15\" r=\"3\" fill=\"#b76a16\" stroke=\"white\"/>"

const char* ModernIconSvg(int id)
{
    switch (id)
    {
    case ID_BMP_ADD: return ICON("<path d=\"M10 3v14M3 10h14\"/>");
    case ID_BMP_REMOVE: return ICON("<path d=\"M3 10h14\"/>");
    case ID_BMP_COLUP:
    case ID_BMP_UP: return ICON("<path d=\"M10 17V3M5 8l5-5 5 5\"/>");
    case ID_BMP_COLDOWN:
    case ID_BMP_DOWN: return ICON("<path d=\"M10 3v14M5 12l5 5 5-5\"/>");
    case ID_BMP_FIRST: return ICON("<path d=\"M3 4h14M5 13l5-5 5 5\"/>");
    case ID_BMP_LAST: return ICON("<path d=\"M3 16h14M5 7l5 5 5-5\"/>");
    case ID_BMP_LEFT:
    case ID_BMP_LEFTARROW1: return ICON("<path d=\"M15 10H4m5-5-5 5 5 5\"/>");
    case ID_BMP_RIGHT:
    case ID_BMP_RIGHTARROW1: return ICON("<path d=\"M5 10h11m-5-5 5 5-5 5\"/>");
    case ID_BMP_ALLTOLEFT:
    case ID_BMP_LEFTARROW2: return ICON("<path d=\"M3 4v12m7-11-5 5 5 5m6-10-5 5 5 5\"/>");
    case ID_BMP_ALLTORIGHT:
    case ID_BMP_RIGHTARROW2: return ICON("<path d=\"M17 4v12M4 5l5 5-5 5m6-10 5 5-5 5\"/>");
    case ID_BMP_DBNEW: return ICON(DATABASE_SHAPE ADD_BADGE);
    case ID_BMP_OPENDB: return ICON("<path d=\"M2 6V4h6l2 2h7v3M2 6v10h15l2-7H5L2 16\"/>");
    case ID_BMP_ATTACH: return ICON("<path d=\"M8 12.5 13.5 7a2.1 2.1 0 0 0-3-3L4.5 10a3.5 3.5 0 0 0 5 5l6-6a1.8 1.8 0 0 0-2.5-2.5l-5.5 5.5\"/>");
    case ID_BMP_COMPACTDB: return ICON(DATABASE_SHAPE "<path d=\"M7 8h6M10 6v4\"/>");
    case ID_BMP_REFRESH: return ICON("<path d=\"M16 7a6.5 6.5 0 0 0-11-2L3 7m0-4v4h4m-3 6a6.5 6.5 0 0 0 11 2l2-2m0 4v-4h-4\"/>");
    case ID_BMP_UNDO: return ICON("<path d=\"M8 5 3 9l5 4M3 9h9a4 4 0 0 1 4 4v2\"/>");
    case ID_BMP_REDO: return ICON("<path d=\"m12 5 5 4-5 4m5-4H8a4 4 0 0 0-4 4v2\"/>");
    case ID_BMP_CUT: return ICON("<circle cx=\"5\" cy=\"5\" r=\"2\"/><circle cx=\"5\" cy=\"15\" r=\"2\"/><path d=\"m7 6 9 10M7 14 16 4\"/>");
    case ID_BMP_COPY: return ICON("<rect x=\"7\" y=\"6\" width=\"10\" height=\"11\" rx=\"1\"/><path d=\"M13 6V3H4v11h3\"/>");
    case ID_BMP_PASTE: return ICON("<rect x=\"5\" y=\"4\" width=\"11\" height=\"13\" rx=\"1\"/><path d=\"M8 4V2.5h5V4M8 9h5m-5 3h5\"/>");
    case ID_BMP_CLEAR: return ICON("<path d=\"M4 5h12M7 5V3h6v2m-8 0 1 12h8l1-12M8 8v6m4-6v6\"/>");
    case ID_BMP_RUNSQL: return ICON("<path fill=\"#21834a\" stroke=\"#21834a\" d=\"M5 3.5v13L16 10z\"/>");
    case ID_BMP_RUNSCRIPT: return ICON("<path d=\"M3 2.5h9v4M3 2.5v15h7M5.5 6h4m-4 3h4\"/><path fill=\"#21834a\" stroke=\"#21834a\" d=\"M12 9v8l6-4z\"/>");
    case ID_BMP_EXPLAIN: return ICON("<circle cx=\"8\" cy=\"8\" r=\"5\"/><path d=\"m12 12 5 5M6 8h4\"/>");
    case ID_BMP_STARTTRANSACT: return ICON("<circle cx=\"10\" cy=\"10\" r=\"7\"/><path d=\"M10 6v8M6 10h8\"/>");
    case ID_BMP_STOPTRANSACT: return ICON("<circle cx=\"10\" cy=\"10\" r=\"7\"/><path d=\"M7 7h6v6H7z\"/>");
    case ID_BMP_COMMIT: return ICON("<circle cx=\"10\" cy=\"10\" r=\"7\"/><path stroke=\"#21834a\" d=\"m6.5 10 2.5 2.5 4.5-5\"/>");
    case ID_BMP_ROLLBACK: return ICON("<circle cx=\"10\" cy=\"10\" r=\"7\"/><path stroke=\"#c64343\" d=\"m7 7 6 6m0-6-6 6\"/>");
    case ID_BMP_AUTOTRANSACT: return ICON("<circle cx=\"10\" cy=\"10\" r=\"7\"/><path d=\"M7 13 10 6l3 7m-5-2h4\"/>");
    case ID_BMP_TABLECREATE: return ICON(TABLE_SHAPE ADD_BADGE);
    case ID_BMP_TABLEDROP: return ICON(TABLE_SHAPE DROP_BADGE);
    case ID_BMP_VIEWCREATE: return ICON(VIEW_SHAPE ADD_BADGE);
    case ID_BMP_VIEWDROP: return ICON(VIEW_SHAPE DROP_BADGE);
    case ID_BMP_INDEXECREATE: return ICON(INDEX_SHAPE ADD_BADGE);
    case ID_BMP_INDEXEDROP: return ICON(INDEX_SHAPE DROP_BADGE);
    case ID_BMP_TRIGGERCREATE: return ICON(TRIGGER_SHAPE ADD_BADGE);
    case ID_BMP_TRIGGERDROP: return ICON(TRIGGER_SHAPE DROP_BADGE);
    case ID_BMP_INDEXE: return ICON(INDEX_SHAPE);
    case ID_BMP_INDEXE_TMP: return ICON(INDEX_SHAPE TEMP_BADGE);
    case ID_BMP_INDEXES: return ICON("<path d=\"M6 2v13M11 2v13M16 2v13M4 5h14M4 10h14M2 18h14\"/>");
    case ID_BMP_TABLE: return ICON(TABLE_SHAPE);
    case ID_BMP_TABLE_TMP: return ICON(TABLE_SHAPE TEMP_BADGE);
    case ID_BMP_TABLES: return ICON("<rect x=\"4\" y=\"2\" width=\"14\" height=\"12\" rx=\"1\"/><path d=\"M4 6h14M9 6v8M2 6v11h13\"/>");
    case ID_BMP_TRIGGER2: return ICON(TRIGGER_SHAPE);
    case ID_BMP_TRIGGER2_TMP: return ICON(TRIGGER_SHAPE TEMP_BADGE);
    case ID_BMP_TRIGGERS2: return ICON("<path d=\"M8 2 3 10h4l-1 7 5-8M14 3l-3 5h4l-2 8 4-6\"/>");
    case ID_BMP_VIEW: return ICON(VIEW_SHAPE);
    case ID_BMP_VIEW_TMP: return ICON(VIEW_SHAPE TEMP_BADGE);
    case ID_BMP_VIEWS: return ICON("<path d=\"M2 10s3-4.5 8-4.5 8 4.5 8 4.5-3 4.5-8 4.5S2 10 2 10z\"/><circle cx=\"10\" cy=\"10\" r=\"2\"/><path d=\"M5 3h10\"/>");
    case ID_BMP_LOG: return ICON("<path d=\"M4 2.5h9l3 3v12H4zM13 2.5v3h3M7 9h6m-6 3h6m-6 3h4\"/>");
    case ID_BMP_DATABASE: return ICON(DATABASE_SHAPE);
    case ID_BMP_FIELD:
    case ID_BMP_FIELD2: return ICON("<rect x=\"4\" y=\"2.5\" width=\"12\" height=\"15\" rx=\"1\"/><path d=\"M8 3v14M11 6h2m-2 4h2m-2 4h2\"/>");
    case ID_BMP_FILTER: return ICON("<path d=\"M2.5 4h15L12 10v5l-4 2v-7z\"/>");
    case ID_BMP_SORT: return ICON("<path d=\"M5 3v14m-3-3 3 3 3-3M11 5h6m-6 4h4m-4 4h2\"/>");
    default: return nullptr;
    }
}

#undef TEMP_BADGE
#undef DROP_BADGE
#undef ADD_BADGE
#undef DATABASE_SHAPE
#undef TRIGGER_SHAPE
#undef INDEX_SHAPE
#undef VIEW_SHAPE
#undef TABLE_SHAPE
#undef ICON
}
#endif

#endif
