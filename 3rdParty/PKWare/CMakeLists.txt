cmake_minimum_required ( VERSION 3.0 )
project ( PKWare CXX )

set ( PKWARE_SRC
    explode.cpp
    implode.cpp
)

add_library ( PKWare STATIC ${PKWARE_SRC} )

set ( PKWARE_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE )
set ( PKWARE_LIB PKWare PARENT_SCOPE )
