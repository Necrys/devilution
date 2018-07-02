#include "ddraw_orig.h"

#define DDRAWLIBNAME "ddraw.orig.dll"

#define GET_FUNCTION_PTR(p, n) \
    n = (p)GetProcAddress(hModule, #n); \
    if (nullptr == n) { \
        MessageBoxA(nullptr, #n " can't be loaded", "Error", MB_OK); \
        return false; \
    }

namespace ddraw {

PFNDirectDrawCreate DirectDrawCreate = nullptr;

bool load() {
    if (DirectDrawCreate) {
        return true;
    }

    HINSTANCE hModule = LoadLibraryA(DDRAWLIBNAME);
    if (!hModule) {
        MessageBoxA(nullptr, "Failed to load " DDRAWLIBNAME, "Error", MB_OK);
        return false;
    }

    GET_FUNCTION_PTR(PFNDirectDrawCreate, DirectDrawCreate);

    return true;
}
}
