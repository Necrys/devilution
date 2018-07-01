#include "strconv.h"
#include "log.h"

const char* ReasonToString(const DWORD dwReason) {
    static const char* strProcessAttach = "DLL_PROCESS_ATTACH";
    static const char* strThreadAttach = "DLL_THREAD_ATTACH";
    static const char* strProcessDetach = "DLL_PROCESS_DETACH";
    static const char* strThreadDetach = "DLL_THREAD_DETACH";
    static const char* strUnknown = "UNKNOWN";

    switch (dwReason) {
    case DLL_PROCESS_ATTACH: return strProcessAttach;
    case DLL_THREAD_ATTACH: return strThreadAttach;
    case DLL_PROCESS_DETACH: return strProcessDetach;
    case DLL_THREAD_DETACH: return strThreadDetach;
    default: return strUnknown;
    }
}

const char* MainMenuResultToString(const int iResult) {
    static const char* strSingleplayer = "Single player";
    static const char* strMultiplayer = "Multiplayer";
    static const char* strReplayIntro = "Replay Intro";
    static const char* strCredits = "Show Credits";
    static const char* strExit = "Quit Diablo";
    static const char* strAttractMode = "Attract Mode (Replay Intro)";
    static const char* strUnknown = "UNKNOWN";

    switch (iResult) {
    case 1: return strSingleplayer;
    case 2: return strMultiplayer;
    case 3: return strReplayIntro;
    case 4: return strCredits;
    case 5: return strExit;
    case 6: return strAttractMode;
    default: return strUnknown;
    }
}

/*
_uiheroinfo*   next;
char           name[16];
unsigned short level;
unsigned char  heroclass;
unsigned char  herorank;
unsigned short strength;
unsigned short magic;
unsigned short dexterity;
unsigned short vitality;
int            gold;
int            hassaved;
int            spawned;
*/

void DumpUiHeroInfo(const _uiheroinfo* info) {
    if (!info) {
        Log::instance().printf("info: (null)");
        return;
    }

    Log::instance().printf("info: 0x%p\n\t\t\t\t"
        "next: 0x%p\n\t\t\t\t"
        "name: %s\n\t\t\t\t"
        "level: %u\n\t\t\t\t"
        "heroclass: %u\n\t\t\t\t"
        "herorank: %u\n\t\t\t\t"
        "strength: %u\n\t\t\t\t"
        "magic: %u\n\t\t\t\t"
        "dexterity: %u\n\t\t\t\t"
        "vitality: %u\n\t\t\t\t"
        "gold: %u\n\t\t\t\t"
        "hassaved: %u\n\t\t\t\t"
        "spawned: %u\n\t\t\t\t",
        info, info->next, info->name, info->level, info->heroclass, info->herorank,
        info->strength, info->magic, info->dexterity, info->vitality, info->gold,
        info->hassaved, info->spawned
    );
}