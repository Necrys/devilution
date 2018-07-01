cmake_minimum_required ( VERSION 3.0 )
project ( diabloui CXX )

if ( MSVC )

    set ( DIABLOUI_SRC ${DIABLOUI_SRC}
        diabloui.cpp
        diabloui.def
    )

    add_library ( diabloui SHARED ${DIABLOUI_SRC} )

    set_target_properties ( diabloui PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diabloui PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diabloui PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diabloui PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS" )

    set_target_properties ( diabloui PROPERTIES PREFIX "" )
    set_target_properties ( diabloui PROPERTIES OUTPUT_NAME "diabloui" )
    set_target_properties ( diabloui PROPERTIES SUFFIX ".dll" )

    set ( DIABLOUI_LIB diabloui PARENT_SCOPE )

elseif ( MINGW )

    set (DIABLOUI_LIB_OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/diabloui.lib"
    )

    add_custom_command ( OUTPUT ${DIABLOUI_LIB_OUTPUT}
        COMMAND dlltool -d ${CMAKE_CURRENT_SOURCE_DIR}/diabloui_gcc.def -D ${CMAKE_CURRENT_SOURCE_DIR}/../diabloui.dll -l ${DIABLOUI_LIB_OUTPUT}
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/diabloui_gcc.def"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../diabloui.dll"
        COMMENT "Creating diabloui.lib"
        VERBATIM
    )

    add_custom_target (diabloui DEPENDS ${DIABLOUI_LIB_OUTPUT})

    set (DIABLOUI_LIB ${CMAKE_CURRENT_BINARY_DIR}/diabloui.lib PARENT_SCOPE)

endif ()

set (DIABLOUI_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
