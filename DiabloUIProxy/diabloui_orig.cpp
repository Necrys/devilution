#include "diabloui_orig.h"
#include "log.h"

#define GET_FUNCTION_PTR(p, n) \
    n = (p)GetProcAddress(hModule, #n); \
    if (nullptr == n) { \
        MessageBoxA(nullptr, #n " can't be loaded", "Error", MB_OK); \
        return false; \
    }

namespace Original {
PFNUIINITIALIZEPROC UiInitialize = nullptr;
PFNUIDESTROYPROC UiDestroy = nullptr;

PFNUITITLEDIALOGPROC UiTitleDialog = nullptr;
PFNUICOPYPROTERRORPROC UiCopyProtError = nullptr;
PFNUIAPPACTIVATEPROC UiAppActivate = nullptr;
PFNUIVALIDPLAYERNAMEPROC UiValidPlayerName = nullptr;
PFNUISELHEROMULTDIALOGPROC UiSelHeroMultDialog = nullptr;
PFNUISELHEROSINGDIALOGPROC UiSelHeroSingDialog = nullptr;
PFNUICREDITSDIALOGPROC UiCreditsDialog = nullptr;
PFNUIMAINMENUDIALOGPROC UiMainMenuDialog = nullptr;
PFNUIPROGRESSDIALOGPROC UiProgressDialog = nullptr;

PFNUIPROFILEGETSTRINGPROC UiProfileGetString = nullptr;
PFNUIPROFILEDRAWPROC UiProfileDraw = nullptr;

PFNUIPROFILECALLBACKPROC UiProfileCallback = nullptr;
PFNUICATEGORYCALLBACKPROC UiCategoryCallback = nullptr;
PFNUIGETDATACALLBACKPROC UiGetDataCallback = nullptr;
PFNUIAUTHCALLBACKPROC UiAuthCallback = nullptr;
PFNUISOUNDCALLBACKPROC UiSoundCallback = nullptr;
PFNUIMESSAGEBOXCALLBACKPROC UiMessageBoxCallback = nullptr;
PFNUIDRAWDESCCALLBACKPROC UiDrawDescCallback = nullptr;
PFNUICREATEGAMECALLBACKPROC UiCreateGameCallback = nullptr;
PFNUIARTCALLBACKPROC UiArtCallback = nullptr;

PFNUISELECTGAMEPROC UiSelectGame = nullptr;
PFNUISELECTPROVIDERPROC UiSelectProvider = nullptr;
PFNUICREATEPLAYERDESCRIPTIONPROC UiCreatePlayerDescription = nullptr;
PFNUISETUPPLAYERINFOPROC UiSetupPlayerInfo = nullptr;

#define DIABLOUILIBNAME "diabloui.orig.dll"

bool Load() {
    if (UiInitialize) {
        return true;
    }

    HINSTANCE hModule = LoadLibraryA(DIABLOUILIBNAME);
    if (!hModule) {
        MessageBoxA(nullptr, "Failed to load " DIABLOUILIBNAME, "Error", MB_OK);
        return false;
    }

    GET_FUNCTION_PTR (PFNUIINITIALIZEPROC, UiInitialize);
    GET_FUNCTION_PTR (PFNUIDESTROYPROC, UiDestroy);

    GET_FUNCTION_PTR (PFNUITITLEDIALOGPROC, UiTitleDialog);
    GET_FUNCTION_PTR (PFNUICOPYPROTERRORPROC, UiCopyProtError);
    GET_FUNCTION_PTR (PFNUIAPPACTIVATEPROC, UiAppActivate);
    GET_FUNCTION_PTR (PFNUIVALIDPLAYERNAMEPROC, UiValidPlayerName);
    GET_FUNCTION_PTR (PFNUISELHEROMULTDIALOGPROC, UiSelHeroMultDialog);
    GET_FUNCTION_PTR (PFNUISELHEROSINGDIALOGPROC, UiSelHeroSingDialog);
    GET_FUNCTION_PTR (PFNUICREDITSDIALOGPROC, UiCreditsDialog);
    GET_FUNCTION_PTR (PFNUIMAINMENUDIALOGPROC, UiMainMenuDialog);
    GET_FUNCTION_PTR (PFNUIPROGRESSDIALOGPROC, UiProgressDialog);

    GET_FUNCTION_PTR (PFNUIPROFILEGETSTRINGPROC, UiProfileGetString);
    GET_FUNCTION_PTR (PFNUIPROFILEDRAWPROC, UiProfileDraw);

    GET_FUNCTION_PTR (PFNUIPROFILECALLBACKPROC, UiProfileCallback);
    GET_FUNCTION_PTR (PFNUICATEGORYCALLBACKPROC, UiCategoryCallback);
    GET_FUNCTION_PTR (PFNUIGETDATACALLBACKPROC, UiGetDataCallback);
    GET_FUNCTION_PTR (PFNUIAUTHCALLBACKPROC, UiAuthCallback);
    GET_FUNCTION_PTR (PFNUISOUNDCALLBACKPROC, UiSoundCallback);
    GET_FUNCTION_PTR (PFNUIMESSAGEBOXCALLBACKPROC, UiMessageBoxCallback);
    GET_FUNCTION_PTR (PFNUIDRAWDESCCALLBACKPROC, UiDrawDescCallback);
    GET_FUNCTION_PTR (PFNUICREATEGAMECALLBACKPROC, UiCreateGameCallback);
    GET_FUNCTION_PTR (PFNUIARTCALLBACKPROC, UiArtCallback);

    GET_FUNCTION_PTR (PFNUISELECTGAMEPROC, UiSelectGame);
    GET_FUNCTION_PTR (PFNUISELECTPROVIDERPROC, UiSelectProvider);
    GET_FUNCTION_PTR (PFNUICREATEPLAYERDESCRIPTIONPROC, UiCreatePlayerDescription);
    GET_FUNCTION_PTR (PFNUISETUPPLAYERINFOPROC, UiSetupPlayerInfo);

    LOG("Original API successfully loaded");

    return true;
}

}