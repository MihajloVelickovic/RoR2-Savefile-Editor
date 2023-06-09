cmake_minimum_required(VERSION 3.26)
project(RoR2_Editor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

if(APPLE)
    message("x64-osx used")
    set(WX-TYPE x64-osx)
elseif(UNIX)
    message("x64-linux used")
    set(WX_TYPE x64-linux)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    message("x64-mingw-static used")
    set(WX_TYPE x64-mingw-static)
elseif (MSVC)
    message("x64-windows-static used")
    set(WX_TYPE x64-windows-static)
endif()

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(wxWidgets_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${WX_TYPE}/share/wxwidgets)
set(NanoSVG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${WX_TYPE}/share/NanoSVG)

find_package(wxWidgets CONFIG REQUIRED core base xml)

if(wxWidgets_FOUND)
    add_executable(main src/main.cpp
                        src/app.cpp
                        src/mainframe.cpp
                        src/achievementframe.cpp
                        src/achievement.cpp
                        src/clickabletext.cpp)
    target_link_libraries(main PRIVATE wx::core wx::base wx::xml)
    target_include_directories(main PRIVATE ${wxWidgets_INCLUDE_DIRECTORIES})
    target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()