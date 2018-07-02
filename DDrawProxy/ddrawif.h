#pragma once

#include <ddraw.h>

class DirectDrawIf : public IDirectDraw {
public:
    DirectDrawIf(LPDIRECTDRAW pDD);

    virtual HRESULT __stdcall QueryInterface(const IID&, LPVOID*);
    virtual ULONG   __stdcall AddRef();
    virtual ULONG   __stdcall Release();

    virtual HRESULT __stdcall Compact();
    virtual HRESULT __stdcall CreateClipper(DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR *);
    virtual HRESULT __stdcall CreatePalette(DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR *);
    virtual HRESULT __stdcall CreateSurface( LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR *, IUnknown FAR *);
    virtual HRESULT __stdcall DuplicateSurface(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR *);
    virtual HRESULT __stdcall EnumDisplayModes(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK);
    virtual HRESULT __stdcall EnumSurfaces(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK);
    virtual HRESULT __stdcall FlipToGDISurface();
    virtual HRESULT __stdcall GetCaps(LPDDCAPS, LPDDCAPS);
    virtual HRESULT __stdcall GetDisplayMode(LPDDSURFACEDESC);
    virtual HRESULT __stdcall GetFourCCCodes( LPDWORD, LPDWORD);
    virtual HRESULT __stdcall GetGDISurface(LPDIRECTDRAWSURFACE FAR *);
    virtual HRESULT __stdcall GetMonitorFrequency(LPDWORD);
    virtual HRESULT __stdcall GetScanLine(LPDWORD);
    virtual HRESULT __stdcall GetVerticalBlankStatus(LPBOOL);
    virtual HRESULT __stdcall Initialize(GUID FAR *);
    virtual HRESULT __stdcall RestoreDisplayMode();
    virtual HRESULT __stdcall SetCooperativeLevel(HWND, DWORD);
    virtual HRESULT __stdcall SetDisplayMode(DWORD, DWORD, DWORD);
    virtual HRESULT __stdcall WaitForVerticalBlank(DWORD, HANDLE);

private:
    LPDIRECTDRAW m_pDD;
};