#pragma once

#include <ddraw.h>

typedef HRESULT(WINAPI *PFNDirectDrawCreate)(GUID*, LPDIRECTDRAW*, IUnknown*);

namespace ddraw {

extern PFNDirectDrawCreate DirectDrawCreate;

bool load();
}
