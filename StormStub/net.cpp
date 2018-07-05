#include "net.h"
#include "err.h"
#include "stormstub.h"

#include <log.h>
#include <common_types.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

#include <cassert>

#ifndef STORMSTUB_PASSTHROUGH
#include <queue>
#include <vector>

template <typename SizeT, size_t PacketSize>
struct NetPacketT {
    const size_t MaxSize = PacketSize - sizeof(SizeT);

    SizeT         databytes = (SizeT(0) - 1);
    unsigned char data[PacketSize - sizeof(SizeT)];

    void setFree() {
        databytes = SizeT(0) - 1;
    }

    bool isFree() {
        //SS_DBG("[packet:0x%p] databytes: %d", this, databytes);
        return databytes == (SizeT)(SizeT(0) - 1);
    }
};

using NetPacket = NetPacketT<unsigned char, 256>;

std::queue<NetPacket*> g_packetQueue;
std::vector<NetPacket> g_packetPool;

NetPacket* getFreePacket() {
  //SS_DBG("packetPoolSize: %d", g_packetPool.size());
  for (auto& p : g_packetPool) {
    if (p.isFree()) {
      return &p;
    }
  }

  // TODO: make a safe reallocation
  assert(false);
  return nullptr;
}

void initNetEmulation(const size_t packetPoolSize) {
    LOG_INF("packetPoolSize: %d", packetPoolSize);
    g_packetPool.resize(packetPoolSize);
}
#else
void initNetEmulation(const size_t packetPoolSize) {

}
#endif

namespace Storm {
    BOOL SNetLeaveGame(int type) {
        SS_DBG("type: %d", type);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetLeaveGame(type);
#else
        return FALSE;
#endif
    }

    BOOL SNetDestroy() {
        SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetDestroy();
#else
        return FALSE;
#endif
    }

    BOOL SNetGetOwnerTurnsWaiting(int* turns) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SNetGetOwnerTurnsWaiting(turns);
        SS_DBG("turns: %d -> %d", *turns, result);
        return result;
#else
        SS_DBG("");
        return FALSE;
#endif
    }

    BOOL SNetDropPlayer(int playerid, DWORD flags) {
        SS_DBG("playerid: %d, flags: 0x%x", playerid, flags);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetDropPlayer(playerid, flags);
#else
        return FALSE;
#endif
    }

    int SNetSendServerChatCommand(const char *command) {
        SS_DBG("command: \"%s\"", command);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetSendServerChatCommand(command);
#else
        return 0;
#endif
    }

    const char* dump(char* data, int size) {
        static int bufferSize = 256;
        static char* buffer = new char[bufferSize];

        if (size * 3 > bufferSize) {
            bufferSize = (size * 4) + 1;
            delete[] buffer;
            buffer = new char[bufferSize];
        }

        int b = 0;
        int p = 0;
        for (int i = 0; i < size; ++i) {
            assert (buffer + p < buffer + bufferSize);
            sprintf(buffer + p, "%02X", data[i]);
            p += 2;
            assert(buffer + p < buffer + bufferSize);
            if (b == 8) {
                *(buffer + p) = '\n';
                b = 0;
            } else {
                *(buffer + p) = ' ';
                ++b;
            }
            ++p;
        }

        assert(buffer + p < buffer + bufferSize);
        *(buffer + p) = 0;

        return buffer;
    }

    BOOL SNetSendMessage(unsigned int playerID, char *data, unsigned int databytes) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SNetSendMessage(playerID, data, databytes);
        SS_DBG("playerID: %d, data: 0x%p, size: %u -> %d", playerID, data, databytes, result);
        if (data && databytes > 0) {
            SS_DBG("data:\n%s", dump(data, databytes));
        }

        return result;
#else
        if (playerID == 0) {
            auto packet = getFreePacket();
            assert(databytes <= packet->MaxSize);
            memcpy(packet->data, data, databytes);
            packet->databytes = databytes;
            g_packetQueue.push(packet);
        }

        return TRUE;
#endif
    }

    BOOL SNetReceiveMessage(int *senderplayerid, BYTE **data, int *databytes) {
#ifdef STORMSTUB_PASSTHROUGH
      BOOL result = ::SNetReceiveMessage(senderplayerid, (char**)data, databytes);
      SS_DBG("senderplayerid: %d, data: 0x%p, databytes: %u -> %d", *senderplayerid, *data, *databytes, result);
      if (result && *data && *databytes > 0) {
          SS_DBG("data:\n%s", dump((char*)*data, *databytes));
      }
      return result;
#else
      // There must be another way to return packets to the free pool
      static NetPacket* prevPacket = nullptr;
      if (prevPacket) {
          prevPacket->setFree();
          prevPacket = nullptr;
      }

      if (g_packetQueue.empty()) {
          setLastError(STORM_ERROR_NO_MESSAGES_WAITING);
          *senderplayerid = -1;
          *data = nullptr;
          *databytes = 0;
          return FALSE;
      }

      auto packet = g_packetQueue.front();
      g_packetQueue.pop();
      prevPacket = packet;
      *senderplayerid = 0;
      *data = packet->data;
      *databytes = packet->databytes;

      return TRUE;
#endif
    }

    BOOL SNetSetBasePlayer(unsigned int a1) {
        SS_DBG("a1: %u", a1);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetSetBasePlayer(a1);
#else
        return TRUE;
#endif
    }

    BOOL SNetGetGameInfo(int type, char *src, unsigned int length, size_t *byteswritten) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SNetGetGameInfo(type, src, length, byteswritten);
        SS_DBG("type: %d, src: %s, length: %u, byteswritten: %d", type, src, length, *byteswritten);
        return result;
#else
        SS_DBG("");
        strcpy(src, "local");
        *byteswritten = 6;
        return TRUE;
#endif
    }

    void dumpNetProgramData(const _SNETPROGRAMDATA* program) {
        SS_DBG("program (0x%p):\n"
            "size: %d\n"
            "programname: %s\n"
            "programdescription: %s\n"
            "programid: %d\n"
            "versionid: %d\n"
            "reserved1: %d\n"
            "maxplayers: %d\n"
            "multi_seed: %d\n"
            "initdata: 0x%p\n"
            "initdatabytes: %d\n"
            "reserved2: 0x%p\n"
            "optcategorybits: %d\n"
            "reserved3: %d\n"
            "reserved4: %d\n"
            "languageid: %d",
            program, program->size, program->programname, program->programdescription,
            program->programid, program->versionid, program->reserved1, program->maxplayers,
            program->multi_seed, program->initdata, program->initdatabytes, program->reserved2,
            program->optcategorybits, program->reserved3, program->reserved4, program->languageid);
    }

    void dumpNetPlayerData(const _SNETPLAYERDATA* player) {
        SS_DBG("player (0x%p):\n"
            "size: %d\n"
            "playername: %s\n"
            "playerdescription: %s\n"
            "field_C: %d",
            player, player->size, player->playername, player->playerdescription, player->field_C);
    }

    void dumpNetUIData(const _SNETUIDATA* ui) {
        SS_DBG("ui (0x%p):\n"
            "size: %d\n"
            "uiflags: %d\n"
            "parentwindow: 0x%p\n"
            "profilegetstring: %d",
            ui, ui->size, ui->uiflags, ui->parentwindow, ui->profilegetstring);
    }

    void dumpNetVersionData(const _SNETVERSIONDATA* version) {
        SS_DBG("version: (0x%p):\n"
            "size: %d\n"
            "versionstring: %s\n"
            "executablefile: %s\n"
            "originalarchivefile: %s\n"
            "patcharchivefile: %s",
            version, version->size, version->versionstring, version->executablefile,
            version->originalarchivefile, version->patcharchivefile);
    }

    int SNetInitializeProvider(unsigned long a1, _SNETPROGRAMDATA* program, _SNETPLAYERDATA* player, _SNETUIDATA* ui, _SNETVERSIONDATA* version) {
        SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetInitializeProvider(a1, program, player, ui, version);
#else
        dumpNetProgramData(program);
        dumpNetPlayerData(player);
        dumpNetUIData(ui);
        dumpNetVersionData(version);

        return ::SNetInitializeProvider(a1, program, player, ui, version);
#endif
    }

    BOOL SNetCreateGame(const char *pszGameName,
                        const char *pszGamePassword,
                        const char *pszGameStatString,
                        DWORD dwGameType,
                        char *GameTemplateData,
                        int GameTemplateSize,
                        int playerCount,
                        char *creatorName,
                        char *a11,
                        int *playerID) {
        SS_DBG("pszGameName: %s, pszGamePassword: %s, pszGameStatString: %s, dwGameType: %ul, GameTemplateData: %s, "
            "GameTemplateSize: %d, playerCount: %d, creatorName: %s, a11: %s, playerID: %d",
            pszGameName, pszGamePassword, pszGameStatString, dwGameType, GameTemplateData, GameTemplateSize,
            playerCount, creatorName, a11, *playerID);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetCreateGame(pszGameName, pszGamePassword, pszGameStatString, dwGameType, GameTemplateData, GameTemplateSize,
            playerCount, creatorName, a11, playerID);
#else
        return TRUE;
#endif
    }

    void dumpNetCaps(const _SNETCAPS* caps) {
        SS_DBG("caps (0x%p):\n"
            "size: %d\n"
            "flags: %d\n"
            "maxmessagesize: %d\n"
            "maxqueuesize: %d\n"
            "maxplayers: %d\n"
            "bytessec: %d\n"
            "latencyms: %d\n"
            "defaultturnssec: %d\n"
            "defaultturnsintransit: %d",
            caps, caps->size, caps->flags, caps->maxmessagesize, caps->maxqueuesize, caps->maxplayers,
            caps->bytessec, caps->latencyms, caps->defaultturnssec, caps->defaultturnsintransit);
    }

    int SNetGetProviderCaps(_SNETCAPS* pNetCaps) {
        SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
        int result = ::SNetGetProviderCaps(pNetCaps);
        SS_DBG("result: %d", result);
        dumpNetCaps(pNetCaps);
        return result;
#else
        pNetCaps->maxmessagesize = 496;
        pNetCaps->maxqueuesize = 16;
        pNetCaps->maxplayers = 1;
        pNetCaps->bytessec = 3145728;
        pNetCaps->latencyms = 0;
        pNetCaps->defaultturnssec = 30;
        pNetCaps->defaultturnsintransit = 0;

        return 1;
#endif
    }

    BOOL SNetGetTurnsInTransit(int *turns) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SNetGetTurnsInTransit(turns);
        SS_DBG("turns: %d -> %d", *turns, result);
        return result;
#else
        SS_DBG("");
        *turns = 0;
        return TRUE;
#endif
    }

    BOOL SNetSendTurn(char* data, size_t databytes) {
#ifdef STORMSTUB_PASSTHROUGH
        SS_DBG("data:\n%s\n", dump(data, databytes));
        BOOL result = ::SNetSendTurn(data, databytes);
        SS_DBG("result: %d", result);
        return result;
#else
        return TRUE;
#endif
    }

    BOOL SNetReceiveTurns(int a1, int arraysize, unsigned char **arraydata, unsigned int *arraydatabytes, DWORD *arrayplayerstatus) {
#ifdef STORMSTUB_PASSTHROUGH
      int* pPlayerStatus = reinterpret_cast<int*>(arrayplayerstatus);
      int* pArrayData = reinterpret_cast<int*>(*arraydata);

      BOOL result = ::SNetReceiveTurns(a1, arraysize, arraydata, arraydatabytes, arrayplayerstatus);

      pArrayData = reinterpret_cast<int*>(*arraydata);
      SS_DBG("a1: %d, arraysize: %d, arraydata (0x%p): [%d, %d, %d, %d], arraydatabytes: [%d, %d, %d, %d], arrayplayerstatus: [%d, %d, %d, %d]",
          a1, arraysize, pArrayData, pArrayData[0], pArrayData[1], pArrayData[2], pArrayData[3],
          arraydatabytes[0], arraydatabytes[1], arraydatabytes[2], arraydatabytes[3],
          pPlayerStatus[0], pPlayerStatus[1], pPlayerStatus[2], pPlayerStatus[3]
      );
      return result;
#else
      static unsigned long turncount = 0;
      ++turncount;
      *arraydata = (unsigned char*)&turncount;
      return TRUE;
#endif
    }

    BOOL SNetPerformUpgrade(DWORD *upgradestatus) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SNetPerformUpgrade(upgradestatus);
        SS_DBG("upgradestatus: %ul, result: %d", *upgradestatus, result);
        return result;
#else
        SS_DBG("");
        return TRUE;
#endif
    }

    void* __stdcall SNetUnregisterEventHandler(int a1, void(__stdcall* func)(struct _SNETEVENT *)) {
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetUnregisterEventHandler(a1, func);
#else
        SS_DBG("");
        return (void*)1;
#endif
    }

    void* __stdcall SNetRegisterEventHandler(int a1, void(__stdcall* func)(struct _SNETEVENT *)) {
#ifdef STORMSTUB_PASSTHROUGH
        return ::SNetRegisterEventHandler(a1, func);
#else
        SS_DBG("");
        return (void*)1;
#endif
    }

}
