wxSqlitePlus
============

A cross-platform, open-source, easy-to-use SQLite database browser or client.

The SQL workspace provides syntax-highlighted editing, one-click statement and
script execution, query-plan inspection, and tabbed results and output. Grid
results can be copied or exported as UTF-8 CSV from the context menu.
Toolbars, object navigation and dialogs use a consistent scalable icon set
where supported, with the original icons retained as a fallback on platforms
without SVG bitmap support.
Use the database structure search to find tables, views, indexes, triggers and
columns across attached databases. Press Enter or click Next to cycle through
matches; use Window > Find database object to focus the search.

Encryption method is now upon [wxSQLite3](https://github.com/utelle/wxsqlite3) and compatible with 
1. [Money Manager EX](https://moneymanagerex.org/)
    - [MMEX4iOS](https://github.com/moneymanagerex/mmex-ios)
    - [MMEX4Android](https://github.com/moneymanagerex/android-money-manager-ex/)
    - [MMEX4Destkop](https://github.com/moneymanagerex/moneymanagerex)
3. [SQLCipher](https://www.zetetic.net/sqlcipher/)
4. [SQLite Studio](https://github.com/pawelsalawa/sqlitestudio/wiki/Official_plugins#dbsqlitewx)
5. [DB Browser for SQLite](https://github.com/sqlitebrowser/sqlitebrowser/wiki/Encrypted-Databases)

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
