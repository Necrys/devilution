#include "ddrawpaletteif.h"
#include "log.h"
#include "ddraw_orig.h"

#include <sstream>
#include <iomanip>

#define __CLASS__ "DirectDrawPaletteIf"

DirectDrawPaletteIf::DirectDrawPaletteIf(IDirectDrawPalette* pDDP) :
    m_pDDP(pDDP) {
}

HRESULT __stdcall DirectDrawPaletteIf::QueryInterface(const IID& riid, LPVOID* ppvObj) {
    LOG_DBG("[this:0x%p] %s(riid: %d-%d-%d-%s, ppvObj: 0x%p)", this, __FUNCTION__, riid.Data1, riid.Data2, riid.Data3, riid.Data4, ppvObj);
    return m_pDDP->QueryInterface(riid, ppvObj);
}

ULONG __stdcall DirectDrawPaletteIf::AddRef() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDP->AddRef();
}

ULONG __stdcall DirectDrawPaletteIf::Release() {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDP->Release();
}

HRESULT __stdcall DirectDrawPaletteIf::GetCaps(LPDWORD lpdwCaps) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    return m_pDDP->GetCaps(lpdwCaps);
}

HRESULT __stdcall DirectDrawPaletteIf::GetEntries(DWORD dwFlags,
                                                  DWORD dwBase,
                                                  DWORD dwNumEntries,
                                                  LPPALETTEENTRY lpEntries) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    HRESULT hr = m_pDDP->GetEntries(dwFlags, dwBase, dwNumEntries, lpEntries);
    //LOG_DBG("[this:0x%p] %s(), palette:\n%s", this, __FUNCTION__, dumpPalette(lpEntries, dwNumEntries).c_str());
    return hr;
}

HRESULT __stdcall DirectDrawPaletteIf::Initialize(LPDIRECTDRAW lpDD,
                                                  DWORD dwFlags,
                                                  LPPALETTEENTRY lpDDColorTable) {
    LOG_DBG("[this:0x%p] %s()", this, __FUNCTION__);
    //LOG_DBG("[this:0x%p] %s(), palette:\n%s", this, __FUNCTION__, dumpPalette(lpDDColorTable, 256).c_str());
    return m_pDDP->Initialize(lpDD, dwFlags, lpDDColorTable);
}

HRESULT __stdcall DirectDrawPaletteIf::SetEntries(DWORD dwFlags,
                                                  DWORD dwStartingEntry,
                                                  DWORD dwCount,
                                                  LPPALETTEENTRY lpEntries) {
    LOG_DBG("[this:0x%p] %s(dwFlags: %d, dwStartingEntry: %d, dwCount: %d, lpEntries: 0x%p)", this, __FUNCTION__, dwFlags, dwStartingEntry, dwCount, lpEntries);
    //LOG_DBG("[this:0x%p] %s(), palette:\n%s", this, __FUNCTION__, dumpPalette(lpEntries, dwCount).c_str());
    return m_pDDP->SetEntries(dwFlags, dwStartingEntry, dwCount, lpEntries);
}

IDirectDrawPalette* DirectDrawPaletteIf::get() {
    return m_pDDP;
}

std::string dumpPalette(const LPPALETTEENTRY colorTable, int count) {
    std::stringstream ss;

    for (int i = 0; i < count; ++i) {
        const PALETTEENTRY& pal = *(colorTable + i);
        ss << "[" << std::setw(3) << i << "]: { red: " << (int)pal.peRed << ", green: " << (int)pal.peGreen << ", blue: " << (int)pal.peBlue << ", flags: " << (int)pal.peFlags << "}" << std::endl;
    }

    return ss.str();
}