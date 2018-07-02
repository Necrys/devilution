#pragma once

#include "../types.h"

namespace Storm {
    BOOL SNetLeaveGame(int type);
    BOOL SNetDestroy();
    BOOL SNetGetOwnerTurnsWaiting(int *turns);
    BOOL SNetDropPlayer(int playerid, DWORD flags);
    int  SNetSendServerChatCommand(const char *command);
    BOOL SNetSendMessage(unsigned int playerID, char *data, unsigned int databytes);
    BOOL SNetReceiveMessage(int *senderplayerid, BYTE **data, int *databytes);
    BOOL SNetSetBasePlayer(unsigned int a1);
    BOOL SNetGetGameInfo(int type, char *src, unsigned int length, size_t *byteswritten);
    int  SNetInitializeProvider(unsigned long, _SNETPROGRAMDATA *, _SNETPLAYERDATA *, _SNETUIDATA *, _SNETVERSIONDATA *);
    BOOL SNetCreateGame(const char *pszGameName, const char *pszGamePassword, const char *pszGameStatString, DWORD dwGameType, char *GameTemplateData, int GameTemplateSize, int playerCount, char *creatorName, char *a11, int *playerID);
    int  SNetGetProviderCaps(_SNETCAPS* pNetCaps);
    BOOL SNetGetTurnsInTransit(int *turns);
    BOOL SNetSendTurn(char* data, size_t databytes);
    BOOL SNetReceiveTurns(int a1, int arraysize, unsigned char **arraydata, unsigned int *arraydatabytes, DWORD *arrayplayerstatus);
    BOOL SNetPerformUpgrade(DWORD *upgradestatus);
    void* __stdcall SNetUnregisterEventHandler(int, void(__stdcall*)(struct _SNETEVENT *));
    void* __stdcall SNetRegisterEventHandler(int, void(__stdcall*)(struct _SNETEVENT *));

}

void initNetEmulation(const size_t packetPoolSize);
