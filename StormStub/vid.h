#pragma once

#include "types.h"

namespace Storm {
    BOOL SVidInitialize(HANDLE video);
    BOOL SVidDestroy();
    BOOL SVidPlayBegin(char *filename, int arg4, int a3, int a4, int a5, int a6, HANDLE* video);
    BOOL SVidPlayContinue();
    BOOL SVidPlayEnd(HANDLE video);
}
