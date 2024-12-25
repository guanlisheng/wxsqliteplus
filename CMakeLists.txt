
# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.27)

if(APPLE AND NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    # If no deployment target has been set default to the minimum supported
    # OS version (this has to be set before the first project() call)
    if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
        set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0 CACHE STRING "iOS Deployment Target")
    else()
        set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10 CACHE STRING "macOS Deployment Target")
    endif()
endif()

# Name the project
project(wxSQLitePlus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Request the required wxWidgets libs
find_package(wxWidgets 3.2 REQUIRED COMPONENTS core base stc xml net adv aui html richtext)
add_library(wxWidgets INTERFACE)
target_include_directories(wxWidgets SYSTEM INTERFACE ${wxWidgets_INCLUDE_DIRS})

# Include the wxWidgets use file to initialize various settings
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

# Define a variable containing a list of source files for the project
set(SRC_FILES
    src/aboutdlg.cpp
    src/addcolumn.cpp
    src/attachdbdlg.cpp
    src/backrestdlg.cpp
    src/blobdlg.cpp
    src/createindex.cpp
    src/createtable.cpp
    src/createtrigger.cpp
    src/createview.cpp
    src/dbbook.cpp
    src/describedlg.cpp
    src/detachdbdlg.cpp
    src/dropobject.cpp
    src/encrypkeydlg.cpp
    src/filterdlg.cpp
    src/indexbook.cpp
    src/paneldata.cpp
    src/preferences.cpp
    src/sortdlg.cpp
    src/specgrid.cpp
    src/sqlbook.cpp
    src/sqleditor.cpp
    src/sqlhistory.cpp
    src/sqlite3table.cpp
    src/sqliteplusframe.cpp
    src/sqlparameters.cpp
    src/tablebook.cpp
    src/triggerbook.cpp
    src/triggerparser.cpp
    src/viewbook.cpp
    src/wxsqliteplusapp.cpp
    )

add_subdirectory(3rd)

if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES src/wxsqliteplus.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES build/wxmac.icns)
    link_libraries("-framework Security")
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} PUBLIC ${wxWidgets_LIBRARIES} wxSQLite3)
target_include_directories(${PROJECT_NAME} PUBLIC src)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/build/Info.plist.in
        RESOURCE "build/wxmac.icns"
        MACOSX_BUNDLE_ICON_FILE wxmac.icns
        MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.guanlisheng.wxsqliteplus"
        )
endif()

if(wxSQLite3_VERSION)
    message(STATUS "wxSQLite3 ${wxSQLite3_VERSION}")
endif()
message(STATUS "DB encryption  : ${WXSQLITE3_HAVE_CODEC}")
