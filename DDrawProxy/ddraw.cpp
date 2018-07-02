#include "ddraw_orig.h"
#include "ddrawif.h"

#include <log.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef WIN32_LEAN_AND_MEAN

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        Log::instance().init("ddrawproxy.log");
        if (!ddraw::load()) {
            LOG_ERR("Failed to load original ddraw.dll");
            return FALSE;
        }
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

HRESULT WINAPI DirectDrawCreate(GUID* lpGUID, LPDIRECTDRAW* lplpDD, IUnknown* pUnkOuter ) {
    LOG_DBG("(lpGUID: 0x%p, lplpDD: 0x%p, pUnkOuter: 0x%p)", lpGUID, lplpDD, pUnkOuter);
    LPDIRECTDRAW realDD = nullptr;
    HRESULT res = ddraw::DirectDrawCreate(lpGUID, &realDD, pUnkOuter);
    if (res == S_OK && realDD) {
        *lplpDD = new DirectDrawIf(realDD);
    }

    return res;
}
