cmake_minimum_required ( VERSION 3.0 )
project ( diablo CXX )

if ( MINGW )
    # TODO: get rid of all warnings listed here. See issue #2
    set ( DIABLO_COMPILE_FLAGS
        -fpermissive
        -Wno-write-strings
        -Wno-int-to-pointer-cast
        -Wno-stringop-overflow
        -Wno-overflow
        -Wno-multichar
        -Wno-aggressive-loop-optimizations
        -mwindows
        #-Wall
        #-Werror
    )
elseif ( MSVC )
    # TODO: get rid of all warnings listed here. See issue #1
    set ( DIABLO_COMPILE_FLAGS
        /wd4996
        /wd4267
        /wd4302
        /wd4739
        /wd4334
        /wd4477
        /MP
        #/WX
    )
endif ()

set ( DIABLO_SRC
    appfat.cpp
    automap.cpp
    capture.cpp
    codec.cpp
    control.cpp
    cursor.cpp
    dead.cpp
    debug.cpp
    diablo.cpp
    doom.cpp
    drlg_l1.cpp
    drlg_l2.cpp
    drlg_l3.cpp
    drlg_l4.cpp
    dthread.cpp
    dx.cpp
    effects.cpp
    encrypt.cpp
    engine.cpp
    error.cpp
    fault.cpp
    gamemenu.cpp
    gendung.cpp
    gmenu.cpp
    help.cpp
    init.cpp
    interfac.cpp
    inv.cpp
    items.cpp
    lighting.cpp
    loadsave.cpp
    logging.cpp
    mainmenu.cpp
    minitext.cpp
    missiles.cpp
    monster.cpp
    movie.cpp
    mpqapi.cpp
    msg.cpp
    msgcmd.cpp
    multi.cpp
    nthread.cpp
    objects.cpp
    pack.cpp
    palette.cpp
    path.cpp
    pfile.cpp
    player.cpp
    plrmsg.cpp
    portal.cpp
    quests.cpp
    restrict.cpp
    scrollrt.cpp
    setmaps.cpp
    sha.cpp
    sound.cpp
    spells.cpp
    stores.cpp
    sync.cpp
    textdat.cpp
    themes.cpp
    tmsg.cpp
    town.cpp
    towners.cpp
    track.cpp
    trigs.cpp
    wave.cpp
    world.cpp
)

if ( MSVC )
    set ( DIABLO_HEADERS
        appfat.h
        automap.h
        capture.h
        codec.h
        control.h
        cursor.h
        dead.h
        debug.h
        diablo.h
        doom.h
        drlg_l1.h
        drlg_l2.h
        drlg_l3.h
        drlg_l4.h
        dthread.h
        dx.h
        effects.h
        encrypt.h
        engine.h
        error.h
        fault.h
        gamemenu.h
        gendung.h
        gmenu.h
        help.h
        init.h
        interfac.h
        inv.h
        items.h
        lighting.h
        loadsave.h
        logging.h
        mainmenu.h
        minitext.h
        missiles.h
        monster.h
        movie.h
        mpqapi.h
        msg.h
        msgcmd.h
        multi.h
        nthread.h
        objects.h
        pack.h
        palette.h
        path.h
        pfile.h
        player.h
        plrmsg.h
        portal.h
        quests.h
        restrict.h
        scrollrt.h
        setmaps.h
        sha.h
        sound.h
        spells.h
        stores.h
        sync.h
        textdat.h
        themes.h
        tmsg.h
        town.h
        towners.h
        track.h
        trigs.h
        wave.h
        world.h
        ../defs.h
        ../enums.h
        ../resource.h
        ../structs.h
        ../types.h
    )
    
    #set ( DIABLO_RESOURCES
    #    ../Diablo.rc
    #    ../Diablo.ico
    #)
    source_group ( "Header Files" FILES ${DIABLO_HEADERS} )
    source_group ( "Source Files" FILES ${DIABLO_SRC} )
    #source_group ( "Resource Files" FILES ${DIABLO_RESOURCES} )

    set ( DIABLO_SRC
        ${DIABLO_SRC}
        ${DIABLO_HEADERS}
    #    ${DIABLO_RESOURCES}
    )
endif ()

link_directories (
    ${STORM_LIB_DIR}
    ${DIABLOUI_LIB_DIR}
    ${PKWARE_LIB_DIR}
)

add_executable ( diablo ${DIABLO_SRC} )

target_include_directories ( diablo
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${COMMON_LIB_INCLUDE}
)

if ( MSVC )
    set_target_properties ( diablo PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diablo PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diablo PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS" )
    set_target_properties ( diablo PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS" )
    set_property ( TARGET diablo APPEND PROPERTY LINK_FLAGS /NXCOMPAT:NO)
endif ()

target_compile_options ( diablo
    PRIVATE ${DIABLO_COMPILE_FLAGS}
)

target_link_libraries ( diablo
    PRIVATE ${STORM_LIB}
    PRIVATE ${DIABLOUI_LIB}
    PRIVATE ${PKWARE_LIB}
    PRIVATE common
    PRIVATE gdi32
    PRIVATE version
)
