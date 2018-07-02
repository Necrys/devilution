cmake_minimum_required ( VERSION 3.0 )
project ( stormstub CXX )

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
    stormstub.h
)

target_link_libraries ( stormstub
    PRIVATE
    common
)

target_include_directories ( stormstub
    PRIVATE
    ${COMMON_LIB_INCLUDE}
    ${STORM_LIB_INCLUDE}
)

set ( STORMSTUB_LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE )
