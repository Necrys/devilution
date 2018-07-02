#pragma once

#include "types.h"

namespace Storm {
    BOOL SNetLeaveGame(int type);
    BOOL SNetDestroy();
    BOOL SNetGetOwnerTurnsWaiting(int *turns);
    BOOL SNetDropPlayer(int playerid, DWORD flags);
    int  SNetSendServerChatCommand(const char *command);
    BOOL SNetSendMessage(unsigned int playerID, char *data, unsigned int databytes);
    BOOL SNetReceiveMessage(int *senderplayerid, BYTE **data, int *databytes);
}

void initNetEmulation(const size_t packetPoolSize);
