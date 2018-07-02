#include "net.h"
#include "err.h"

#include <log.h>

#include <storm.h>

#include <cassert>
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
        LOG_DBG("[packet:0x%p] databytes: %d", this, databytes);
        return databytes == (SizeT)(SizeT(0) - 1);
    }
};

using NetPacket = NetPacketT<unsigned char, 256>;

std::queue<NetPacket*> g_packetQueue;
std::vector<NetPacket> g_packetPool;

void initNetEmulation(const size_t packetPoolSize) {
    LOG_INF("packetPoolSize: %d", packetPoolSize);
    g_packetPool.resize(packetPoolSize);
}

NetPacket* getFreePacket() {
    LOG_DBG("packetPoolSize: %d", g_packetPool.size());
    for (auto& p : g_packetPool) {
        if (p.isFree()) {
            return &p;
        }
    }

    // TODO: make a safe reallocation
    assert(false);
    return nullptr;
}

namespace Storm {
    BOOL SNetLeaveGame(int type) {
        LOG_DBG("type: %d", type);
        return FALSE;
    }

    BOOL SNetDestroy() {
        LOG_DBG("");
        return FALSE;
    }

    BOOL SNetGetOwnerTurnsWaiting(int* turns) {
        LOG_DBG("");
        return FALSE;
    }

    BOOL SNetDropPlayer(int playerid, DWORD flags) {
        LOG_DBG("playerid: %d, flags: 0x%x", playerid, flags);
        return FALSE;
    }

    int SNetSendServerChatCommand(const char *command) {
        LOG_DBG("command: \"%s\"", command);
        return 0;
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
        if (playerID == 0) {
            auto packet = getFreePacket();
            assert(databytes <= packet->MaxSize);
            memcpy(packet->data, data, databytes);
            packet->databytes = databytes;
            g_packetQueue.push(packet);
        }

        return TRUE;
        /*
        BOOL result = ::SNetSendMessage(playerID, data, databytes);
        LOG_DBG("playerID: %d, data: 0x%p, size: %u -> %d", playerID, data, databytes, result);
        if (data && databytes > 0) {
            LOG_DBG("data:\n%s", dump(data, databytes));
        }
        
        return result;
        */
    }

    BOOL SNetReceiveMessage(int *senderplayerid, BYTE **data, int *databytes) {
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

        /*
        BOOL result = ::SNetReceiveMessage(senderplayerid, (char**)data, databytes);
        LOG_DBG("senderplayerid: %d, data: 0x%p, databytes: %u -> %d", *senderplayerid, *data, *databytes, result);
        if (result && *data && *databytes > 0) {
            LOG_DBG("data:\n%s", dump((char*)*data, *databytes));
        }
        return result;
        */
    }
}
