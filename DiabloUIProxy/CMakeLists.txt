cmake_minimum_required ( VERSION 3.0 )
project ( diabloui_proxy CXX )

if ( NOT MSVC )
    message( FATAL_ERROR "Project is intended to be build only under MSVC, CMake will exit." )
endif ()

option ( BUILD_DIABLOUI_TESTAPP "Build test application for diabloui" OFF )

add_library ( diabloui SHARED
    diabloui.cpp
    diabloui.h
    diabloui.def
    diabloui_orig.cpp
    diabloui_orig.h
    log.cpp
    log.h
    strconv.cpp
    strconv.h
)

target_compile_options ( diabloui
    PRIVATE /wd4996
    PRIVATE /MP
)

set_target_properties ( diabloui PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS" )
set_target_properties ( diabloui PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS" )
set_target_properties ( diabloui PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS" )
set_target_properties ( diabloui PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS" )
set_property ( TARGET diabloui APPEND PROPERTY LINK_FLAGS /NXCOMPAT:NO )

if ( BUILD_DIABLOUI_TESTAPP )
    add_executable (testapp WIN32
        test.cpp
    )

    target_include_directories (testapp
        PRIVATE .
    )

    target_link_libraries (testapp
        PRIVATE diabloui
        PRIVATE version
    )

    target_compile_options (testapp
        PRIVATE /wd4996
        PRIVATE /MP
    )
endif ()

set ( DIABLOUI_LIB diabloui PARENT_SCOPE )
