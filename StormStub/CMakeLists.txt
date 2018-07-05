cmake_minimum_required ( VERSION 3.0 )
project ( stormstub CXX )

option ( STORMSTUB_USE_STORM "Include Storm headers and link library" OFF )
option ( STORMSTUB_PASSTHROUGH "Forward Storm calls to the original dll without stub (If ON, will force STORMSTUB_USE_STORM to be ON)" ON )
option ( STORMSTUB_LOGGER "Log every Storm call" ON )

if ( STORMSTUB_LOGGER )
set ( COMPILE_DEFS
	${COMPILE_DEFS}
	STORMSTUB_LOGGER
)
endif ()

if ( STORMSTUB_PASSTHROUGH )
set ( COMPILE_DEFS
	${COMPILE_DEFS}
	STORMSTUB_PASSTHROUGH
)
set ( STORMSTUB_USE_STORM ON )
endif ()

if ( STORMSTUB_USE_STORM )
set ( COMPILE_DEFS
	${COMPILE_DEFS}
	STORMSTUB_USE_STORM
)
set ( INCLUDE_DIRS
	${INCLUDE_DIRS}
	${STORM_LIB_INCLUDE}
)
set ( LINK_LIBS
	${LINK_LIBS}
	Storm
)
endif ()

add_library ( stormstub STATIC
    reg.cpp
    reg.h
    vid.cpp
    vid.h
    draw.h
    draw.cpp
    net.h
    net.cpp
    err.h
    err.cpp
	storm.cpp
	mpq.h
	mpq.cpp
	mem.h
	mem.cpp
	str.h
	str.cpp
    stormstub.h
)

target_compile_definitions ( stormstub PRIVATE
	${COMPILE_DEFS}
)

target_link_libraries ( stormstub
    PRIVATE
    common
	${LINK_LIBS}
)

target_include_directories ( stormstub
    PRIVATE
    ${COMMON_LIB_INCLUDE}
    ${INCLUDE_DIRS}
)

set ( STORMSTUB_LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE )
