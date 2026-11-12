# wxSQLitePlus v0.5.0

This release improves the SQL workspace and database navigation with a refreshed
set of scalable interface icons.

## Highlights

- Search tables, views, indexes, triggers, and columns across open and attached
  databases. Press Enter or use Next to cycle through matches.
- Export grid data as UTF-8 CSV using the grid's context menu.
- Run statements and scripts and inspect SQLite EXPLAIN output from the SQL editor
  toolbar.
- Use refreshed icons throughout toolbars, database navigation, and dialogs.
  Original icons remain available as a fallback where SVG is unsupported.
- Fixed Enter-key search in the macOS native search control.
- Reopen recently used databases from File > Open Recent. Only database paths
  are remembered; encryption keys are never stored.
- Added MMEX `.mmb` and `.emb` filters to the open and attach database dialogs.
- Improved Explore's Columns view with readable schema labels, clearer
  constraint/default values, and column-aware actions to copy a name or SELECT
  template and jump to that column in Data.
- Clarified row count, read-only status, and active filters/sorting in the Data
  view; added a one-click action to clear filtering and sorting.
- Added a product landing page at the configured GitHub Pages domain.

## Build requirements

- wxWidgets 3.3 and a C++20 compiler are required for the CMake build.
- The bundled wxSQLite3 dependency is updated to 4.10.6.
