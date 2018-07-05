#include "err.h"
#include "stormstub.h"

#include <log.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

#ifndef STORMSTUB_PASSTHROUGH
static DWORD g_err = 0;
#endif

namespace Storm {
    DWORD SErrGetLastError() {
#ifdef STORMSTUB_PASSTHROUGH
        DWORD result = ::SErrGetLastError();
        SS_DBG(" -> %lu", result);
        return result;
#else
        SS_DBG("");
        return g_err;
#endif
    }

    BOOL SErrGetErrorStr(DWORD dwErrCode, char *buffer, size_t bufferchars) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SErrGetErrorStr(dwErrCode, buffer, bufferchars);
        SS_DBG("dwErrCode: %lu, buffer: 0x%p (\"%s\"), bufferchars: %u -> %d", dwErrCode, buffer, bufferchars, result);
        return result;
#else
        SS_DBG("dwErrCode: %d", dwErrCode);
        return TRUE;
#endif
    }

    void  SErrSetLastError(DWORD dwErrCode) {
        SS_DBG("dwErrCode: %lu", dwErrCode);
#ifdef STORMSTUB_PASSTHROUGH
        ::SErrSetLastError(dwErrCode);
#else
        g_err = dwErrCode;
#endif
    }
}

#ifndef STORMSTUB_PASSTHROUGH
void setLastError(const DWORD err) {
    g_err = err;
}
#endif
