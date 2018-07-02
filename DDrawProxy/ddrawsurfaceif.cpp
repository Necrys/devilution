#include "ddrawsurfaceif.h"
#include "ddrawpaletteif.h"
#include "log.h"
#include "ddraw_orig.h"

#define __CLASS__ "DirectDrawSurfaceIf"

DirectDrawSurfaceIf::DirectDrawSurfaceIf(IDirectDrawSurface* pDDS):
    m_pDDS(pDDS) {
}

HRESULT __stdcall DirectDrawSurfaceIf::QueryInterface(const IID& riid, LPVOID* ppvObj) {
    LOG_DBG("[this:0x%p] %s(riid: %d-%d-%d-%s, ppvObj: 0x%p)", this, __FUNCTION__, riid.Data1, riid.Data2, riid.Data3, riid.Data4, ppvObj);
    return m_pDDS->QueryInterface(riid, ppvObj);
}

ULONG __stdcall DirectDrawSurfaceIf::AddRef() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->AddRef();
}

ULONG __stdcall DirectDrawSurfaceIf::Release() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Release();
}

HRESULT __stdcall DirectDrawSurfaceIf::AddAttachedSurface(LPDIRECTDRAWSURFACE lpDDSAttachedSurface) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->AddAttachedSurface(lpDDSAttachedSurface);
}

HRESULT __stdcall DirectDrawSurfaceIf::AddOverlayDirtyRect(LPRECT lpRect) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->AddOverlayDirtyRect(lpRect);
}

HRESULT __stdcall DirectDrawSurfaceIf::Blt(LPRECT lpDestRect,
                                           LPDIRECTDRAWSURFACE lpDDSrcSurface,
                                           LPRECT lpSrcRect,
                                           DWORD dwFlags,
                                           LPDDBLTFX lpDDBltFX) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Blt(lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFX);
}

HRESULT __stdcall DirectDrawSurfaceIf::BltBatch(LPDDBLTBATCH lpDDBltBatch,
                                                DWORD dwCount,
                                                DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->BltBatch(lpDDBltBatch, dwCount, dwFlags);
}

HRESULT __stdcall DirectDrawSurfaceIf::BltFast(DWORD dwX,
                                               DWORD dwY,
                                               LPDIRECTDRAWSURFACE lpDDSrcSurface,
                                               LPRECT lpSrcRect,
                                               DWORD dwTrans) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);
}

HRESULT __stdcall DirectDrawSurfaceIf::DeleteAttachedSurface(DWORD dwFlags,
                                                             LPDIRECTDRAWSURFACE lpDDSAttachedSurface) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);
}

HRESULT __stdcall DirectDrawSurfaceIf::EnumAttachedSurfaces(LPVOID lpContext,
                                                            LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->EnumAttachedSurfaces(lpContext, lpEnumSurfacesCallback);
}

HRESULT __stdcall DirectDrawSurfaceIf::EnumOverlayZOrders(DWORD dwFlags,
                                                          LPVOID lpContext,
                                                          LPDDENUMSURFACESCALLBACK lpfnCallback) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->EnumOverlayZOrders(dwFlags, lpContext, lpfnCallback);
}

HRESULT __stdcall DirectDrawSurfaceIf::Flip(LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride,
                                            DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Flip(lpDDSurfaceTargetOverride, dwFlags);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetAttachedSurface(LPDDSCAPS lpDDSCaps,
                                                          LPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetBltStatus(DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetBltStatus(dwFlags);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetCaps(LPDDSCAPS lpDDSCaps) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetCaps(lpDDSCaps);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetClipper(LPDIRECTDRAWCLIPPER FAR * lplpDDClipper) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetClipper(lplpDDClipper);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetColorKey(DWORD dwFlags,
                                                   LPDDCOLORKEY lpDDColorKey) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetColorKey(dwFlags, lpDDColorKey);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetDC(HDC FAR *lphDC) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetDC(lphDC);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetFlipStatus(DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetFlipStatus(dwFlags);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetOverlayPosition(LPLONG lplX,
                                                          LPLONG lplY) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetOverlayPosition(lplX, lplY);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetPalette(LPDIRECTDRAWPALETTE* lplpDDPalette) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetPalette(lplpDDPalette);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetPixelFormat(lpDDPixelFormat);
}

HRESULT __stdcall DirectDrawSurfaceIf::GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->GetSurfaceDesc(lpDDSurfaceDesc);
}

HRESULT __stdcall DirectDrawSurfaceIf::Initialize(LPDIRECTDRAW lpDD,
                                                  LPDDSURFACEDESC lpDDSurfaceDesc) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Initialize(lpDD, lpDDSurfaceDesc);
}

HRESULT __stdcall DirectDrawSurfaceIf::IsLost() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->IsLost();
}

HRESULT __stdcall DirectDrawSurfaceIf::Lock(LPRECT lpDestRect,
                                            LPDDSURFACEDESC lpDDSurfaceDesc,
                                            DWORD dwFlags,
                                            HANDLE hEvent) {
    //LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);
}

HRESULT __stdcall DirectDrawSurfaceIf::ReleaseDC(HDC hDC) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->ReleaseDC(hDC);
}

HRESULT __stdcall DirectDrawSurfaceIf::Restore() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Restore();
}

HRESULT __stdcall DirectDrawSurfaceIf::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->SetClipper(lpDDClipper);
}

HRESULT __stdcall DirectDrawSurfaceIf::SetColorKey(DWORD dwFlags,
                                                   LPDDCOLORKEY lpDDColorKey) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->SetColorKey(dwFlags, lpDDColorKey);
}

HRESULT __stdcall DirectDrawSurfaceIf::SetOverlayPosition(LONG lX,
                                                          LONG lY) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->SetOverlayPosition(lX, lY);
}

HRESULT __stdcall DirectDrawSurfaceIf::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);

    HRESULT hr;
    DirectDrawPaletteIf* pal = dynamic_cast<DirectDrawPaletteIf*>(lpDDPalette);
    if (pal) {
        hr = m_pDDS->SetPalette(pal->get());
    } else {
        LOG_WRN("[this:0x%p] %s() unknown palette interface was found: 0x%p", this, __FUNCTION__, lpDDPalette);
        hr = m_pDDS->SetPalette(lpDDPalette);
    }

    return hr;
}

HRESULT __stdcall DirectDrawSurfaceIf::Unlock(LPVOID lpSurfaceData) {
    //LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->Unlock(lpSurfaceData);
}

HRESULT __stdcall DirectDrawSurfaceIf::UpdateOverlay(LPRECT lpSrcRect,
                                                     LPDIRECTDRAWSURFACE lpDDDestSurface,
                                                     LPRECT lpDestRect,
                                                     DWORD dwFlags,
                                                     LPDDOVERLAYFX lpDDOverlayFx) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->UpdateOverlay(lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx);
}

HRESULT __stdcall DirectDrawSurfaceIf::UpdateOverlayDisplay(DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->UpdateOverlayDisplay(dwFlags);
}

HRESULT __stdcall DirectDrawSurfaceIf::UpdateOverlayZOrder(DWORD dwFlags,
                                                           LPDIRECTDRAWSURFACE lpDDSReference) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDS->UpdateOverlayZOrder(dwFlags, lpDDSReference);
}
