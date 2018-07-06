#include "reg.h"
#include "stormstub.h"

#include <log.h>

#include <cstring>
#include <cassert>

namespace Storm {

BOOL SRegLoadValue(const char *keyname, const char *valuename, BYTE flags, int *value) {
    assert(keyname && valuename && value);
    // TODO: refactor with config read-write
    if (0 == strcmp(keyname, "Diablo")) {
        if (0 == strcmp(valuename, "Intro")) {
            return TRUE;
        } else if (0 == strcmp(valuename, "Gamma Correction")) {
            return FALSE;
        } else if (0 == strcmp(valuename, "Color Cycling")) {
            return FALSE;
        } else if (0 == strcmp(valuename, "Sound Volume")) {
            return FALSE;
        } else if (0 == strcmp(valuename, "Music Volume")) {
            return FALSE;
        }
    }

    SS_WRN("Unknown pair: keyname: \"%s\", valuename: \"%s\"", keyname, valuename);

    return FALSE;
}

BOOL SRegSaveValue(const char *keyname, const char *valuename, BYTE flags, DWORD result) {
    assert(keyname && valuename);
    SS_DBG("Save pair: keyname: \"%s\", valuename: \"%s\" = %d", keyname, valuename, result);
    return TRUE;
}

BOOL SRegLoadString(const char *keyname, const char *valuename, BYTE flags, char *buffer, size_t buffersize) {
    assert(keyname && valuename && buffer);

    if (0 == strcmp(keyname, "Archives")) {
        if (0 == strcmp(valuename, "DiabloCD")) {
            strncpy(buffer, "G:\\", buffersize);
            return TRUE;
        }
    }

    LOG_WRN("Unknown pair: keyname: \"%s\", valuename: \"%s\"", keyname, valuename);

    return FALSE;
}

BOOL SRegSaveString(const char *keyname, const char *valuename, BYTE flags, char *string) {
    assert(keyname && valuename);
    SS_DBG("Save pair: keyname: \"%s\", valuename: \"%s\" = \"%s\"", keyname, valuename, string);
    return TRUE;
}

BOOL SRegLoadData(const char *keyname, const char *valuename, int size, LPBYTE lpData, BYTE flags, LPDWORD lpcbData) {
    assert(keyname && valuename && lpData && lpcbData);
    
    SS_WRN("Unknown pair: keyname: \"%s\", valuename: \"%s\"", keyname, valuename);

    return FALSE;
}

BOOL SRegSaveData(const char *keyname, const char *valuename, int size, LPBYTE lpData, DWORD cbData) {
    assert(keyname && valuename && lpData);

    SS_DBG("Save pair: keyname: \"%s\", valuename: \"%s\", %d bytes, lpData: 0x%p, cbData: %ul", keyname, valuename, size, lpData, cbData);

    return TRUE;
}

}
