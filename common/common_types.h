#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef WIN32_LEAN_AND_MEAN

struct _SNETPROGRAMDATA {
    int   size;
    char* programname;
    char* programdescription;
    int   programid;
    int   versionid;
    int   reserved1;
    int   maxplayers;
    int   multi_seed;
    void* initdata;
    int   initdatabytes;
    void* reserved2;
    int   optcategorybits;
    int   reserved3;
    int   reserved4;
    int   languageid;
};

struct _SNETPLAYERDATA {
    int   size;
    char* playername;
    char* playerdescription;
    int   field_C;
};

struct _SNETUIDATA {
    int  size;
    int  uiflags;
    HWND parentwindow;
    void(__cdecl *artcallback)();
    void(__cdecl *authcallback)();
    void(__cdecl *createcallback)();
    void(__cdecl *drawdesccallback)();
    void(__cdecl *selectedcallback)();
    void(__cdecl *messageboxcallback)();
    void(__cdecl *soundcallback)();
    void(__cdecl *statuscallback)();
    void(__cdecl *getdatacallback)();
    void(__cdecl *categorycallback)();
    void(__cdecl *field_34)();
    void(__cdecl *field_38)();
    void(__cdecl *profilecallback)();
    int profilegetstring;
    void(__cdecl *profiledraw)();
    void(__cdecl *selecthero)();
    void(__cdecl *createhero)();
};

struct _SNETVERSIONDATA {
    int   size;
    char* versionstring;
    char* executablefile;
    char* originalarchivefile;
    char* patcharchivefile;
};

struct _SNETCAPS {
    int size;
    int flags;
    int maxmessagesize;
    int maxqueuesize;
    int maxplayers;
    int bytessec;
    int latencyms;
    int defaultturnssec;
    int defaultturnsintransit;
};

struct _SNETEVENT {
    int   eventid;
    int   playerid;
    void* data;
    int   databytes;
};

#define STORM_ERROR_INVALID_PLAYER               0x8510006a
#define STORM_ERROR_NO_MESSAGES_WAITING          0x8510006b
#define STORM_ERROR_GAME_TERMINATED              0x85100069
#define STORM_ERROR_NOT_IN_GAME                  0x85100070
#define STORM_ERROR_REQUIRES_UPGRADE             0x85100077
