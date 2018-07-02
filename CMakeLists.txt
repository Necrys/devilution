cmake_minimum_required ( VERSION 3.0 )
project ( devilution CXX )

set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# Fix static runtime library
if ( MSVC )
    foreach ( flag CMAKE_C_FLAGS
                   CMAKE_C_FLAGS_DEBUG
                   CMAKE_C_FLAGS_RELEASE
                   CMAKE_C_FLAGS_MINSIZEREL
                   CMAKE_C_FLAGS_RELWITHDEBINFO)

        if ( ${flag} MATCHES "/MD" )
            string ( REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}" )
        endif ()
        if ( ${flag} MATCHES "/MDd" )
            string ( REGEX REPLACE "/MDd" "/MTd" ${flag} "${${flag}}" )
        endif ()

    endforeach ()
endif ()

add_subdirectory ( common )
add_subdirectory ( 3rdParty/Storm/Source )
add_subdirectory ( DiabloUI )
add_subdirectory ( 3rdParty/PKWare )
add_subdirectory ( Source )

add_dependencies ( diablo common )
add_dependencies ( diablo Storm )
add_dependencies ( diablo diabloui )
add_dependencies ( diablo PKWare )
