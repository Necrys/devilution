cmake_minimum_required ( VERSION 3.0 )
project ( DirectDrawProxy CXX )

if ( NOT MSVC )
    message( FATAL_ERROR "Project is intended to be build only under MSVC, CMake will exit." )
endif ()

add_library ( ddraw SHARED
    ddraw.cpp
    ddraw.def
    ddraw_orig.cpp
    ddraw_orig.h
    ddrawif.h
    ddrawif.cpp
    ddrawsurfaceif.h
    ddrawsurfaceif.cpp
    ddrawpaletteif.h
    ddrawpaletteif.cpp
)

target_compile_options ( ddraw
    PRIVATE
    /MP
)

set_target_properties ( ddraw PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS" )
set_target_properties ( ddraw PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS" )
set_target_properties ( ddraw PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS" )
set_target_properties ( ddraw PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS" )

target_link_libraries ( ddraw
    common
)

target_include_directories ( ddraw
	PRIVATE
	${COMMON_LIB_INCLUDE}
)