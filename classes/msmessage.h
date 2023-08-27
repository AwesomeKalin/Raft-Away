#ifndef MSMESSAGE_H
#define MSMESSAGE_H

#include "player.h"

class MSMessage {
    public:
        int changeToScene;
        Player player;

        MSMessage() : changeToScene(0), player(0, 0, 0) {}
};

#endif