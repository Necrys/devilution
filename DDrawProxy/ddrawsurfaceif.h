#pragma once

#include <ddraw.h>

class DirectDrawSurfaceIf : public IDirectDrawSurface {
public:
    DirectDrawSurfaceIf(IDirectDrawSurface* pDDS);
    
    virtual HRESULT __stdcall QueryInterface(const IID&, LPVOID*);
    virtual ULONG   __stdcall AddRef();
    virtual ULONG   __stdcall Release();

    virtual HRESULT __stdcall AddAttachedSurface(LPDIRECTDRAWSURFACE) override;
    virtual HRESULT __stdcall AddOverlayDirtyRect(LPRECT) override;
    virtual HRESULT __stdcall Blt(LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDBLTFX) override;
    virtual HRESULT __stdcall BltBatch(LPDDBLTBATCH, DWORD, DWORD) override;
    virtual HRESULT __stdcall BltFast(DWORD, DWORD, LPDIRECTDRAWSURFACE, LPRECT, DWORD) override;
    virtual HRESULT __stdcall DeleteAttachedSurface(DWORD, LPDIRECTDRAWSURFACE) override;
    virtual HRESULT __stdcall EnumAttachedSurfaces(LPVOID, LPDDENUMSURFACESCALLBACK) override;
    virtual HRESULT __stdcall EnumOverlayZOrders(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) override;
    virtual HRESULT __stdcall Flip(LPDIRECTDRAWSURFACE, DWORD) override;
    virtual HRESULT __stdcall GetAttachedSurface(LPDDSCAPS, LPDIRECTDRAWSURFACE FAR *) override;
    virtual HRESULT __stdcall GetBltStatus(DWORD) override;
    virtual HRESULT __stdcall GetCaps(LPDDSCAPS) override;
    virtual HRESULT __stdcall GetClipper(LPDIRECTDRAWCLIPPER FAR*) override;
    virtual HRESULT __stdcall GetColorKey(DWORD, LPDDCOLORKEY) override;
    virtual HRESULT __stdcall GetDC(HDC FAR *) override;
    virtual HRESULT __stdcall GetFlipStatus(DWORD) override;
    virtual HRESULT __stdcall GetOverlayPosition(LPLONG, LPLONG) override;
    virtual HRESULT __stdcall GetPalette(LPDIRECTDRAWPALETTE FAR*) override;
    virtual HRESULT __stdcall GetPixelFormat(LPDDPIXELFORMAT) override;
    virtual HRESULT __stdcall GetSurfaceDesc(LPDDSURFACEDESC) override;
    virtual HRESULT __stdcall Initialize(LPDIRECTDRAW, LPDDSURFACEDESC) override;
    virtual HRESULT __stdcall IsLost() override;
    virtual HRESULT __stdcall Lock(LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) override;
    virtual HRESULT __stdcall ReleaseDC(HDC) override;
    virtual HRESULT __stdcall Restore() override;
    virtual HRESULT __stdcall SetClipper(LPDIRECTDRAWCLIPPER) override;
    virtual HRESULT __stdcall SetColorKey(DWORD, LPDDCOLORKEY) override;
    virtual HRESULT __stdcall SetOverlayPosition(LONG, LONG) override;
    virtual HRESULT __stdcall SetPalette(LPDIRECTDRAWPALETTE) override;
    virtual HRESULT __stdcall Unlock(LPVOID) override;
    virtual HRESULT __stdcall UpdateOverlay(LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDOVERLAYFX) override;
    virtual HRESULT __stdcall UpdateOverlayDisplay(DWORD) override;
    virtual HRESULT __stdcall UpdateOverlayZOrder(DWORD, LPDIRECTDRAWSURFACE) override;

private:
    IDirectDrawSurface* m_pDDS;
};
