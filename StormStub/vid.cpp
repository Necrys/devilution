#include "vid.h"
#include "stormstub.h"

#include <log.h>

#include <cstring>

namespace Storm {

BOOL SVidInitialize(HANDLE video) {
    SS_DBG("video: 0x%p", video);
    return TRUE;
}

BOOL SVidDestroy() {
    SS_DBG("");
    return TRUE;
}

BOOL SVidPlayBegin(char *filename, int arg4, int a3, int a4, int a5, int a6, HANDLE* video) {
    SS_DBG("filename: %s", filename);
    static void* handle;
    *video = handle;
    return TRUE;
}

BOOL SVidPlayContinue() {
    SS_DBG("");
    return FALSE;
}

BOOL SVidPlayEnd(HANDLE video) {
    SS_DBG("");
    return TRUE;
}

}