#pragma once

#include <ddraw.h>
#include <string>

class DirectDrawPaletteIf : public IDirectDrawPalette {
public:
    DirectDrawPaletteIf(IDirectDrawPalette* pDDP);

    virtual HRESULT __stdcall QueryInterface(const IID&, LPVOID*);
    virtual ULONG   __stdcall AddRef();
    virtual ULONG   __stdcall Release();

    virtual HRESULT __stdcall GetCaps(LPDWORD) override;
    virtual HRESULT __stdcall GetEntries(DWORD, DWORD, DWORD, LPPALETTEENTRY) override;
    virtual HRESULT __stdcall Initialize(LPDIRECTDRAW, DWORD, LPPALETTEENTRY) override;
    virtual HRESULT __stdcall SetEntries(DWORD, DWORD, DWORD, LPPALETTEENTRY) override;

    IDirectDrawPalette* get();

private:
    IDirectDrawPalette* m_pDDP;
};

std::string dumpPalette(const LPPALETTEENTRY colorTable, int count);