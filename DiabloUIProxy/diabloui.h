/*
 *  DiabloUI proxy
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

#ifdef DIABLOUI_EXPORTS
  #define DIABLOUI_API __declspec(dllexport)
#else
  #define DIABLOUI_API __declspec(dllimport)
#endif

DIABLOUI_API void __cdecl UiInitialize();
DIABLOUI_API void __cdecl UiDestroy();

/*
 *  UiTitleDialog
 *  Show title Diablo screen for seconds
 *  Input parameters:
 *    nsec - screen demonstration time
 */
DIABLOUI_API void __stdcall UiTitleDialog(int nsec);

DIABLOUI_API void __stdcall UiCopyProtError(int a1);
DIABLOUI_API void __stdcall UiAppActivate(int a1);
DIABLOUI_API int  __stdcall UiValidPlayerName(char *a1);
DIABLOUI_API int  __stdcall UiSelHeroMultDialog(void *fninfo, void *fncreate, void *fnremove, void *fnstats, int *a5, int *a6, char *name);

/*
 *  UiSelHeroSingDialog
 *  Show the single game hero selection/creation dialog
 *  Input parameters:
 *    fninfo     : heroes info loading callback
 *    fncreate   : hero create callback
 *    fnremove   : hero delete callback
 *    fnstats    :
 *  Output parameters:
 *    a5         : hero game selection result: 1 - new game, 2 - load game
 *    name       : selected hero name
 *    difficulty : new game difficulty selection result: 0 - normal, 1 - nightmare, 2 - hell
 *  Return value: 1
 */
DIABLOUI_API int  __stdcall UiSelHeroSingDialog(void *fninfo, void *fncreate, void *fnremove, void *fnstats, int *a5, char *name, int *difficulty);
DIABLOUI_API void __stdcall UiCreditsDialog(int a1);

/*
 *  UiMainMenuDialog
 *  Show the main game menu
 *  Input parameters:
 *    name      : version string text (left bottom corner), text is limited with 59 characters, further chars will be truncated
 *    fnSound   : sound effect playing callback
 *    a4        : timeout in seconds after which the Intro movie will be demonstrated (dialog will return with a dlgResult var set to 6 - MAINMENU_ATTRACT_MODE)
 *  Output parameters:
 *    dlgResult : dialog result
 *  Return value: 1
 */
DIABLOUI_API int  __stdcall UiMainMenuDialog(char *name, int *dlgResult, void *fnSound, int a4);
DIABLOUI_API int  __stdcall UiProgressDialog(HWND window, char *msg, int a3, void *fnfunc, int a5);
DIABLOUI_API int  __cdecl UiProfileGetString();
DIABLOUI_API void __cdecl UiProfileDraw();

DIABLOUI_API void __cdecl UiProfileCallback();
DIABLOUI_API void __cdecl UiCategoryCallback();
DIABLOUI_API void __cdecl UiGetDataCallback();
DIABLOUI_API void __cdecl UiAuthCallback();
DIABLOUI_API void __cdecl UiSoundCallback();
DIABLOUI_API void __cdecl UiMessageBoxCallback();
DIABLOUI_API void __cdecl UiDrawDescCallback();
DIABLOUI_API void __cdecl UiCreateGameCallback();
DIABLOUI_API void __cdecl UiArtCallback();

DIABLOUI_API int  __stdcall UiSelectGame(int a1, _SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info, _SNETVERSIONDATA *file_info, int *a6);
DIABLOUI_API int  __stdcall UiSelectProvider(int a1, _SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info, _SNETVERSIONDATA *file_info, int *type);
DIABLOUI_API int  __stdcall UiCreatePlayerDescription(_uiheroinfo *info, int mode, char *desc);
DIABLOUI_API int  __stdcall UiSetupPlayerInfo(char *str, _uiheroinfo *info, int mode);

DIABLOUI_API void __stdcall UiLog(const char* fmt, ...);

#ifdef __cplusplus
}
#endif
