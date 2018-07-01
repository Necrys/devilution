/*
 *  Original API access
 */

#pragma once

#include "types.h"

/*
 *  Prototypes
 */

typedef void (*PFNUIINITIALIZEPROC) ();
typedef void (*PFNUIDESTROYPROC) ();

typedef void (CALLBACK *PFNUITITLEDIALOGPROC) (int);
typedef void (CALLBACK *PFNUICOPYPROTERRORPROC) (int);
typedef void (CALLBACK *PFNUIAPPACTIVATEPROC) (int);
typedef int  (CALLBACK *PFNUIVALIDPLAYERNAMEPROC) (char*);
typedef int  (CALLBACK *PFNUISELHEROMULTDIALOGPROC) (void*, void*, void*, void*, int*, int*, char*);
typedef int  (CALLBACK *PFNUISELHEROSINGDIALOGPROC) (void*, void*, void*, void*, int*, char*, int*);
typedef void (CALLBACK *PFNUICREDITSDIALOGPROC) (int);
typedef int  (CALLBACK *PFNUIMAINMENUDIALOGPROC) (char*, int*, void*, int);
typedef int  (CALLBACK *PFNUIPROGRESSDIALOGPROC) (HWND, char*, int, void*, int);

typedef int  (*PFNUIPROFILEGETSTRINGPROC) ();
typedef void (*PFNUIPROFILEDRAWPROC) ();

typedef void (*PFNUIPROFILECALLBACKPROC) ();
typedef void (*PFNUICATEGORYCALLBACKPROC) ();
typedef void (*PFNUIGETDATACALLBACKPROC) ();
typedef void (*PFNUIAUTHCALLBACKPROC) ();
typedef void (*PFNUISOUNDCALLBACKPROC) ();
typedef void (*PFNUIMESSAGEBOXCALLBACKPROC) ();
typedef void (*PFNUIDRAWDESCCALLBACKPROC) ();
typedef void (*PFNUICREATEGAMECALLBACKPROC) ();
typedef void (*PFNUIARTCALLBACKPROC) ();

typedef int  (CALLBACK *PFNUISELECTGAMEPROC) (int, _SNETPROGRAMDATA*, _SNETPLAYERDATA*, _SNETUIDATA*, _SNETVERSIONDATA*, int*);
typedef int  (CALLBACK *PFNUISELECTPROVIDERPROC) (int, _SNETPROGRAMDATA*, _SNETPLAYERDATA*, _SNETUIDATA*, _SNETVERSIONDATA*, int*);
typedef int  (CALLBACK *PFNUICREATEPLAYERDESCRIPTIONPROC) (_uiheroinfo*, int, char*);
typedef int  (CALLBACK *PFNUISETUPPLAYERINFOPROC) (char*, _uiheroinfo*, int);

/*
 *  Function pointers
 */
namespace Original {
extern PFNUIINITIALIZEPROC UiInitialize;
extern PFNUIDESTROYPROC UiDestroy;

extern PFNUITITLEDIALOGPROC UiTitleDialog;
extern PFNUICOPYPROTERRORPROC UiCopyProtError;
extern PFNUIAPPACTIVATEPROC UiAppActivate;
extern PFNUIVALIDPLAYERNAMEPROC UiValidPlayerName;
extern PFNUISELHEROMULTDIALOGPROC UiSelHeroMultDialog;
extern PFNUISELHEROSINGDIALOGPROC UiSelHeroSingDialog;
extern PFNUICREDITSDIALOGPROC UiCreditsDialog;
extern PFNUIMAINMENUDIALOGPROC UiMainMenuDialog;
extern PFNUIPROGRESSDIALOGPROC UiProgressDialog;

extern PFNUIPROFILEGETSTRINGPROC UiProfileGetString;
extern PFNUIPROFILEDRAWPROC UiProfileDraw;

extern PFNUIPROFILECALLBACKPROC UiProfileCallback;
extern PFNUICATEGORYCALLBACKPROC UiCategoryCallback;
extern PFNUIGETDATACALLBACKPROC UiGetDataCallback;
extern PFNUIAUTHCALLBACKPROC UiAuthCallback;
extern PFNUISOUNDCALLBACKPROC UiSoundCallback;
extern PFNUIMESSAGEBOXCALLBACKPROC UiMessageBoxCallback;
extern PFNUIDRAWDESCCALLBACKPROC UiDrawDescCallback;
extern PFNUICREATEGAMECALLBACKPROC UiCreateGameCallback;
extern PFNUIARTCALLBACKPROC UiArtCallback;

extern PFNUISELECTGAMEPROC UiSelectGame;
extern PFNUISELECTPROVIDERPROC UiSelectProvider;
extern PFNUICREATEPLAYERDESCRIPTIONPROC UiCreatePlayerDescription;
extern PFNUISETUPPLAYERINFOPROC UiSetupPlayerInfo;

bool Load();

}
