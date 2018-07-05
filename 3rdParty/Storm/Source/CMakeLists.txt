cmake_minimum_required ( VERSION 3.0 )
project ( Storm CXX )

if ( MSVC )

    set ( STORM_SRC
        storm.cpp
        storm.def
    )

    add_library ( Storm SHARED ${STORM_SRC} )

    set_target_properties ( Storm PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( Storm PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( Storm PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( Storm PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS" )

    set_target_properties ( Storm PROPERTIES PREFIX "" )
    set_target_properties ( Storm PROPERTIES OUTPUT_NAME "Storm" )
    set_target_properties ( Storm PROPERTIES SUFFIX ".dll" )

    set ( STORM_LIB Storm PARENT_SCOPE )

elseif ( MINGW )

    set ( STORM_LIB_OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/Storm.lib"
    )

    add_custom_command ( OUTPUT ${STORM_LIB_OUTPUT}
        COMMAND dlltool -d ${CMAKE_CURRENT_SOURCE_DIR}/storm_gcc.def -D ${CMAKE_CURRENT_SOURCE_DIR}/../../../Storm.dll -l ${STORM_LIB_OUTPUT}
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/storm_gcc.def"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../../../Storm.dll"
        COMMENT "Creating Storm.lib"
        VERBATIM
    )

    add_custom_target ( Storm DEPENDS ${STORM_LIB_OUTPUT} )

    set ( STORM_LIB ${CMAKE_CURRENT_BINARY_DIR}/Storm.lib PARENT_SCOPE )

endif ()

set ( STORM_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE )
set ( STORM_LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE )