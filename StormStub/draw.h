#pragma once

#include "types.h"

struct IDirectDraw;
struct IDirectDrawSurface;
struct IDirectDrawPalette;

namespace Storm {
    BOOL SDrawManualInitialize(HWND hWnd, IDirectDraw* ddInterface, IDirectDrawSurface* primarySurface, IDirectDrawSurface* surface2, IDirectDrawSurface* surface3, IDirectDrawSurface* backSurface, IDirectDrawPalette* ddPalette, HPALETTE hPalette);
    void SDrawMessageBox(char* msg, char* title, UINT type);
    void SDrawDestroy();
    void SDrawRealizePalette();
    HWND SDrawGetFrameWindow(HWND* sdraw_framewindow);
    BOOL SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4);
}
