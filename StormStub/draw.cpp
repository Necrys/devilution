#include "draw.h"
#include "stormstub.h"

#include <log.h>
#include <common_types.h>

#include <ddraw.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

namespace Storm {

BOOL SDrawManualInitialize(HWND hWnd, LPDIRECTDRAW ddInterface, LPDIRECTDRAWSURFACE primarySurface, LPDIRECTDRAWSURFACE surface2, LPDIRECTDRAWSURFACE surface3, LPDIRECTDRAWSURFACE backSurface, LPDIRECTDRAWPALETTE ddPalette, HPALETTE hPalette) {
    SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
    return ::SDrawManualInitialize(hWnd, ddInterface, primarySurface, surface2, surface3, backSurface, ddPalette, hPalette);
#else
    return ::SDrawManualInitialize(hWnd, ddInterface, primarySurface, surface2, surface3, backSurface, ddPalette, hPalette);
#endif
}

void SDrawMessageBox(char* text, char* caption, UINT type) {
    SS_DBG("msg: \"%s\", title: \"%s\", flags: 0x%x", text, caption, type);
#ifdef STORMSTUB_PASSTHROUGH
    ::SDrawMessageBox(text, caption, type);
#else
#endif
}

void SDrawDestroy() {
    SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
    ::SDrawDestroy();
#else
    ::SDrawDestroy();
#endif
}

void SDrawRealizePalette() {
    SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
    ::SDrawRealizePalette();
#else
    ::SDrawRealizePalette();
#endif
}

HWND SDrawGetFrameWindow(HWND* sdraw_framewindow) {
#ifdef STORMSTUB_PASSTHROUGH
    SS_DBG("");
    return ::SDrawGetFrameWindow(sdraw_framewindow);
#else
    HWND result = ::SDrawGetFrameWindow(sdraw_framewindow);
    SS_DBG("sdraw_framewindow: 0x%p, result: 0x%p", sdraw_framewindow, result);
    return result;
#endif
}

BOOL SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4) {
    SS_DBG("firstentry: %u, numentries: %u, pPalEntries: 0x%p, a4: %d", firstentry, numentries, pPalEntries, a4);
#ifdef STORMSTUB_PASSTHROUGH
    return ::SDrawUpdatePalette(firstentry, numentries, pPalEntries, a4);
#else
    return ::SDrawUpdatePalette(firstentry, numentries, pPalEntries, a4);
#endif
}

}
