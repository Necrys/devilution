#include "err.h"

#include <log.h>

static DWORD g_err = 0;

namespace Storm {
    DWORD SErrGetLastError() {
        LOG_DBG("");
        return g_err;
    }
}

void setLastError(const DWORD err) {
    g_err = err;
}