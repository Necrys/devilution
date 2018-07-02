#pragma once

#include "types.h"

namespace Storm {
    DWORD SErrGetLastError();
}

void setLastError(const DWORD err);