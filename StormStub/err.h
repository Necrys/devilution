#pragma once

#include "types.h"

namespace Storm {
    DWORD SErrGetLastError();
    BOOL  SErrGetErrorStr(DWORD dwErrCode, char *buffer, size_t bufferchars);
    void  SErrSetLastError(DWORD dwErrCode = NO_ERROR);
}

#ifndef STORMSTUB_PASSTHROUGH
void setLastError(const DWORD err);
#endif
