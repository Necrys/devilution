cmake_minimum_required ( VERSION 3.0 )
project ( commonlib CXX )

add_library ( common STATIC
    log.cpp
    log.h
	common_types.h
)

set ( COMMON_LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE )