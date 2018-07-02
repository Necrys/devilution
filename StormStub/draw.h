#pragma once

#include <storm.h>

namespace Storm {
    BOOL SDrawManualInitialize(HWND hWnd, LPDIRECTDRAW ddInterface, LPDIRECTDRAWSURFACE primarySurface, LPDIRECTDRAWSURFACE surface2, LPDIRECTDRAWSURFACE surface3, LPDIRECTDRAWSURFACE backSurface, LPDIRECTDRAWPALETTE ddPalette, HPALETTE hPalette);
    void SDrawMessageBox(LPCSTR msg, LPCSTR title, UINT type);
    void SDrawDestroy();
    void SDrawRealizePalette();
    HWND SDrawGetFrameWindow(HWND* sdraw_framewindow);
    BOOL SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4);
}
