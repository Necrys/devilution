#define DIABLOUI_EXPORTS
#include "diabloui.h"
#include "diabloui_orig.h"
#include "log.h"
#include "strconv.h"

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) {
    LOG("hModule: 0x%x, dwReason: %s ( 0x%x ), lpReserved: 0x%p", hModule, ReasonToString(dwReason), dwReason, lpReserved);
    switch (dwReason) {
		case DLL_PROCESS_ATTACH:
        if (!Original::Load()) {
            return FALSE;
        }
        break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

void __cdecl UiInitialize() {
    LOG("%s()", __FUNCTION__);
  Original::UiInitialize();
}

void __cdecl UiDestroy() {
    LOG("%s()", __FUNCTION__);
    Original::UiDestroy();
}

void __stdcall UiTitleDialog(int nsec) {
    LOG("%s(%d)", __FUNCTION__, nsec);
    Original::UiTitleDialog(nsec);
}

void __stdcall UiCopyProtError(int a1) {
    LOG("%s(%d)", __FUNCTION__, a1);
    Original::UiCopyProtError(a1);
}

void __stdcall UiAppActivate(int a1) {
    LOG("%s(%d)", __FUNCTION__, a1);
    Original::UiAppActivate(a1);
}

int __stdcall UiValidPlayerName(char *a1) {
    LOG("%s(%s)", __FUNCTION__, a1);
    int result = Original::UiValidPlayerName(a1);
    LOG("%s(%s) DONE -> ", __FUNCTION__, a1, result);
    return result;
}

int __stdcall UiSelHeroMultDialog(void *fninfo, void *fncreate, void *fnremove, void *fnstats, int *a5, int *a6, char *name) {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiSelHeroMultDialog(fninfo, fncreate, fnremove, fnstats, a5, a6, name);
    LOG("%s() DONE -> ", __FUNCTION__, result);
    return result;
}

typedef void( __stdcall *AddHeroInfoCallback ) ( _uiheroinfo* );
typedef bool( __stdcall *SetHeroesInfoCallback ) ( AddHeroInfoCallback );
typedef bool( __stdcall *CreateSaveCallback ) ( _uiheroinfo* );
SetHeroesInfoCallback pOrigSetHeroesInfoCallback = nullptr;
AddHeroInfoCallback pOrigAddHeroInfoCallback = nullptr;
CreateSaveCallback pOrigCreateSaveCallback = nullptr;

void __stdcall AddHeroInfo(_uiheroinfo* info) {
    LOG("%s(info: 0x%p), orig: 0x%p", __FUNCTION__, info, pOrigAddHeroInfoCallback);
    DumpUiHeroInfo(info);
    if (pOrigAddHeroInfoCallback) {
        pOrigAddHeroInfoCallback(info);
    }
}

bool __stdcall SetHeroesInfo(AddHeroInfoCallback callback) {
    LOG("%s(callback: 0x%p), orig: 0x%p", __FUNCTION__, callback, pOrigSetHeroesInfoCallback);
    if (pOrigSetHeroesInfoCallback) {
        pOrigAddHeroInfoCallback = callback;
        bool result = pOrigSetHeroesInfoCallback(AddHeroInfo);
        pOrigAddHeroInfoCallback = nullptr;
        return result;
    }

    return false; // ????
}

bool __stdcall CreateSave(_uiheroinfo* info) {
    LOG("%s(info: 0x%p), orig: 0x%p", __FUNCTION__, info, pOrigCreateSaveCallback);
    DumpUiHeroInfo(info);
    if (pOrigCreateSaveCallback) {
        return pOrigCreateSaveCallback(info);
    }

    return false; // ????
}

int __stdcall UiSelHeroSingDialog(void *fninfo, void *fncreate, void *fnremove, void *fnstats, int *a5, char *name, int *difficulty) {
    LOG("%s()", __FUNCTION__);
    pOrigSetHeroesInfoCallback = reinterpret_cast<SetHeroesInfoCallback>(fninfo);
    pOrigCreateSaveCallback = reinterpret_cast<CreateSaveCallback>(fncreate);
    int result = Original::UiSelHeroSingDialog(reinterpret_cast<void*>(SetHeroesInfo), fncreate, fnremove, fnstats, a5, name, difficulty);
    pOrigCreateSaveCallback = nullptr;
    pOrigSetHeroesInfoCallback = nullptr;
    LOG("%s() DONE -> %d, a5: %d, name: %s, difficulty: %d", __FUNCTION__, result, *a5, name, *difficulty);
    return result;
}

void __stdcall UiCreditsDialog(int a1) {
    LOG("%s()", __FUNCTION__);
    Original::UiCreditsDialog(a1);
}

int __stdcall UiMainMenuDialog(char *name, int *dlgResult, void *fnSound, int a4) {
    LOG("%s()", __FUNCTION__);

    static char* versionOverride = "diabloui proxied (Necrys, 2018) test test test test test te";

    int result = Original::UiMainMenuDialog(versionOverride, dlgResult, fnSound, a4);
    LOG("%s() DONE -> %d, dlgResult: %s ( %d )", __FUNCTION__, result, MainMenuResultToString(*dlgResult), *dlgResult);
    return result;
}

int __stdcall UiProgressDialog(HWND window, char *msg, int a3, void *fnfunc, int a5) {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiProgressDialog(window, msg, a3, fnfunc, a5);
    LOG("%s() DONE -> %d", __FUNCTION__, result);
    return result;
}

int __cdecl UiProfileGetString() {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiProfileGetString();

    // somehow it returns pointer to string "profile/sex"
    char* pStrResult = reinterpret_cast<char*>(result);

    LOG("%s() DONE -> %d (%s)", __FUNCTION__, result, pStrResult);
    return result;
}

void __cdecl UiProfileDraw() {
    LOG("%s()", __FUNCTION__);
    Original::UiProfileDraw();
}

void __cdecl UiProfileCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiProfileCallback();
}

void __cdecl UiCategoryCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiCategoryCallback();
}

void __cdecl UiGetDataCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiGetDataCallback();
}

void __cdecl UiAuthCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiAuthCallback();
}

void __cdecl UiSoundCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiSoundCallback();
}

void __cdecl UiMessageBoxCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiMessageBoxCallback();
}

void __cdecl UiDrawDescCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiDrawDescCallback();
}

void __cdecl UiCreateGameCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiCreateGameCallback();
}

void __cdecl UiArtCallback() {
    LOG("%s()", __FUNCTION__);
    Original::UiArtCallback();
}

int __stdcall UiSelectGame(int a1, _SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info, _SNETVERSIONDATA *file_info, int *a6) {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiSelectGame(a1, client_info, user_info, ui_info, file_info, a6);
    LOG("%s() DONE -> %d", __FUNCTION__, result);
    return result;
}

int __stdcall UiSelectProvider(int a1, _SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info, _SNETVERSIONDATA *file_info, int *type) {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiSelectProvider(a1, client_info, user_info, ui_info, file_info, type);
    LOG("%s() DONE -> %d", __FUNCTION__, result);
    return result;
}

int __stdcall UiCreatePlayerDescription(_uiheroinfo *info, int mode, char *desc) {
    LOG("%s()", __FUNCTION__);
    int result = Original::UiCreatePlayerDescription(info, mode, desc);
    LOG("%s() DONE -> %d", __FUNCTION__, result);
    return result;
}

int __stdcall UiSetupPlayerInfo(char *str, _uiheroinfo *info, int mode) {
    LOG("%s(str: %s, info: 0x%p, mode: %d)", __FUNCTION__, info, mode);
    DumpUiHeroInfo(info);
    int result = Original::UiSetupPlayerInfo(str, info, mode);
    LOG("%s() DONE -> %d, str: \"%s\"", __FUNCTION__, result, str);
    return result;
}
