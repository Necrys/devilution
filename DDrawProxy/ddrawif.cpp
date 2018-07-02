#include "ddrawif.h"
#include "ddrawsurfaceif.h"
#include "ddrawpaletteif.h"
#include "ddraw_orig.h"

#include <log.h>

#define __CLASS__ "DirectDrawIf"

DirectDrawIf::DirectDrawIf(LPDIRECTDRAW pDD):
    m_pDD(pDD) {
}

HRESULT __stdcall DirectDrawIf::QueryInterface(const IID& riid, LPVOID* ppvObj) {
    LOG_DBG("[this:0x%p] %s(riid: %d-%d-%d-%s, ppvObj: 0x%p)", this, __FUNCTION__, riid.Data1, riid.Data2, riid.Data3, riid.Data4, ppvObj);
    return m_pDD->QueryInterface(riid, ppvObj);
}

ULONG __stdcall DirectDrawIf::AddRef() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->AddRef();
}

ULONG __stdcall DirectDrawIf::Release() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->Release();
}

HRESULT __stdcall DirectDrawIf::Compact() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->Compact();
}

HRESULT __stdcall DirectDrawIf::CreateClipper(DWORD dwFlags,
                                              LPDIRECTDRAWCLIPPER FAR* lplpDDClipper,
                                              IUnknown FAR * pUnkOuter) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);
}

HRESULT __stdcall DirectDrawIf::CreatePalette(DWORD dwFlags,
                                              LPPALETTEENTRY lpColorTable,
                                              LPDIRECTDRAWPALETTE FAR* lplpDDPalette,
                                              IUnknown FAR *pUnkOuter) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    //LOG_DBG("[this:0x%p] %s(), palette:\n%s", this, __FUNCTION__, dumpPalette(lpColorTable, 256).c_str());
    LPDIRECTDRAWPALETTE realDDP = nullptr;
    HRESULT res = m_pDD->CreatePalette(dwFlags, lpColorTable, &realDDP, pUnkOuter);
    if (res == S_OK) {
        *lplpDDPalette = new DirectDrawPaletteIf(realDDP);
    }

    return res;
}

HRESULT __stdcall DirectDrawIf::CreateSurface(LPDDSURFACEDESC lpDDSurfaceDesc,
                                              LPDIRECTDRAWSURFACE FAR *lplpDDSurface,
                                              IUnknown FAR *pUnkOuter) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);

    LPDIRECTDRAWSURFACE realDDS = nullptr;
    HRESULT res = m_pDD->CreateSurface(lpDDSurfaceDesc, &realDDS, pUnkOuter);
    if (res == S_OK) {
        *lplpDDSurface = new DirectDrawSurfaceIf(realDDS);
    }

    return res;
}

HRESULT __stdcall DirectDrawIf::DuplicateSurface(LPDIRECTDRAWSURFACE lpDDSurface,
                                                 LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->DuplicateSurface(lpDDSurface, lplpDupDDSurface);
}

HRESULT __stdcall DirectDrawIf::EnumDisplayModes(DWORD dwFlags,
                                                 LPDDSURFACEDESC lpDDSurfaceDesc,
                                                 LPVOID lpContext,
                                                 LPDDENUMMODESCALLBACK lpEnumCallback) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, lpContext, lpEnumCallback);
}

HRESULT __stdcall DirectDrawIf::EnumSurfaces(DWORD dwFlags,
                                             LPDDSURFACEDESC lpDDSD,
                                             LPVOID lpContext,
                                             LPDDENUMSURFACESCALLBACK lpEnumCallback) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->EnumSurfaces(dwFlags, lpDDSD, lpContext, lpEnumCallback);
}

HRESULT __stdcall DirectDrawIf::FlipToGDISurface() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->FlipToGDISurface();
}

HRESULT __stdcall DirectDrawIf::GetCaps(LPDDCAPS lpDDDriverCaps,
                                        LPDDCAPS lpDDHELCaps) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetCaps(lpDDDriverCaps, lpDDHELCaps);
}

HRESULT __stdcall DirectDrawIf::GetDisplayMode(LPDDSURFACEDESC lpDDSurfaceDesc) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetDisplayMode(lpDDSurfaceDesc);
}

HRESULT __stdcall DirectDrawIf::GetFourCCCodes(DWORD FAR *lpNumCodes,
                                               DWORD FAR *lpCodes) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetFourCCCodes(lpNumCodes, lpCodes);
}

HRESULT __stdcall DirectDrawIf::GetGDISurface(LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetGDISurface(lplpGDIDDSSurface);
}

HRESULT __stdcall DirectDrawIf::GetMonitorFrequency(LPDWORD lpdwFrequency) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetMonitorFrequency(lpdwFrequency);
}

HRESULT __stdcall DirectDrawIf::GetScanLine(LPDWORD lpdwScanLine) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetScanLine(lpdwScanLine);
}

HRESULT __stdcall DirectDrawIf::GetVerticalBlankStatus(LPBOOL lpbIsInVB) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->GetVerticalBlankStatus(lpbIsInVB);
}

HRESULT __stdcall DirectDrawIf::Initialize(GUID FAR *lpGUID) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->Initialize(lpGUID);
}

HRESULT __stdcall DirectDrawIf::RestoreDisplayMode() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->RestoreDisplayMode();
}

HRESULT __stdcall DirectDrawIf::SetCooperativeLevel(HWND hWnd,
                                                    DWORD dwFlags) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->SetCooperativeLevel(hWnd, dwFlags);
}

HRESULT __stdcall DirectDrawIf::SetDisplayMode(DWORD dwWidth,
                                               DWORD dwHeight,
                                               DWORD dwBpp) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->SetDisplayMode(dwWidth, dwHeight, dwBpp);
}

HRESULT __stdcall DirectDrawIf::WaitForVerticalBlank(DWORD dwFlags,
                                                     HANDLE hEvent) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDD->WaitForVerticalBlank(dwFlags, hEvent);
}
