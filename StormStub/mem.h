#pragma once

#include "types.h"

namespace Storm {
    void* SMemAlloc(size_t amount, char* logfilename, int logline, char defaultValue = 0);
    BOOL SMemFree(void* location, char* logfilename, int logline, char defaultValue = 0);
}
