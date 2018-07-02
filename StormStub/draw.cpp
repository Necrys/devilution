#include "draw.h"

#include <log.h>

namespace Storm {

BOOL SDrawManualInitialize(HWND hWnd, LPDIRECTDRAW ddInterface, LPDIRECTDRAWSURFACE primarySurface, LPDIRECTDRAWSURFACE surface2, LPDIRECTDRAWSURFACE surface3, LPDIRECTDRAWSURFACE backSurface, LPDIRECTDRAWPALETTE ddPalette, HPALETTE hPalette) {
    LOG_DBG("");
    return ::SDrawManualInitialize(hWnd, ddInterface, primarySurface, surface2, surface3, backSurface, ddPalette, hPalette);
}

void SDrawMessageBox(LPCSTR text, LPCSTR caption, UINT type) {
    LOG_DBG("msg: \"%s\", title: \"%s\", flags: 0x%x", text, caption, type);
}

void SDrawDestroy() {
    LOG_DBG("");
    ::SDrawDestroy();
}

void SDrawRealizePalette() {
    LOG_DBG("");
    ::SDrawRealizePalette();
}

HWND SDrawGetFrameWindow(HWND* sdraw_framewindow) {
    HWND result = ::SDrawGetFrameWindow(sdraw_framewindow);
    LOG_DBG("sdraw_framewindow: 0x%p, result: 0x%p", sdraw_framewindow, result);
    return result;
}

BOOL SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4) {
    LOG_DBG("firstentry: %u, numentries: %u, pPalEntries: 0x%p, a4: %d", firstentry, numentries, pPalEntries, a4);
    return ::SDrawUpdatePalette(firstentry, numentries, pPalEntries, a4);
}

}