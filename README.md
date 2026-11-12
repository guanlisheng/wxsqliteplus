wxSQLitePlus
============

A cross-platform, open-source SQLite database browser and SQL client.

The SQL workspace provides syntax-highlighted editing, one-click statement and
script execution, query-plan inspection, and tabbed results and output. Grid
results can be copied or exported as UTF-8 CSV from the context menu.
Toolbars, object navigation and dialogs use a consistent scalable icon set
where supported, with the original icons retained as a fallback on platforms
without SVG bitmap support.
Explore tables and views through their columns, data, foreign keys, indexes,
triggers, and DDL. Filter and sort table data, inspect BLOB values, copy query
results, or export grids as CSV. Search database objects across attached
databases and reopen recent files without storing encryption keys.

Open encrypted SQLite databases using the supported wxSQLite3 codecs. MMEX
`.mmb` and `.emb` files are supported when their encryption format matches an
available codec; the database remains local and the key is never saved.

Visit the [wxSQLitePlus product page](https://wxsqliteplus.guanlisheng.com/) or
[download a release](https://github.com/guanlisheng/wxsqliteplus/releases/latest).
wxSQLitePlus is distributed under the [GNU GPL v3](LICENSE).

[![Build status](https://ci.appveyor.com/api/projects/status/rxj2gomqw0iii3n1/branch/master?svg=true)](https://ci.appveyor.com/project/guanlisheng/wxsqliteplus)

## Building

The project uses CMake 3.27 or newer, a C++20 compiler, and wxWidgets 3.3
with the core, base, stc, xml, net, adv, aui, html, and richtext components.
Initialize the wxSQLite3 submodule before configuring:

```sh
git submodule update --init --recursive
cmake -S . -B build
cmake --build build --config Release
```

On macOS and Linux, if CMake cannot find wxWidgets, specify its configuration
tool with `-DwxWidgets_CONFIG_EXECUTABLE="$(which wx-config)"`. On Windows,
configure CMake with a wxWidgets installation compatible with the selected
compiler and architecture.

The legacy Autotools/Bakefile build files have been removed. The existing
Visual Studio project files are retained, but have not been verified against
the current dependencies.

## Contributing

1. Fork it!
2. Clone it to your local machine: `git clone your-repo`
3. Update submodule code: `git submodule update --init`
4. Create your feature branch: `git checkout -b my-new-feature`
5. Commit your changes: `git commit -m 'Add some feature'`
6. Push to the branch: `git push origin my-new-feature`
7. Submit a pull request :D

## Make a donation
1. Do a donate at my Ripple address: `rUY7DvWqNnSYCYiVr986W71tuaKtDCMNz3` 
2. [![PayPal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=guanlisheng%40gmail%2ecom&lc=US&item_name=wxSqlitePlus&no_note=0&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest)

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=guanlisheng/wxsqliteplus&type=Date)](https://star-history.com/#guanlisheng/wxsqliteplus&Date)
