#ifndef MSMESSAGE_H
#define MSMESSAGE_H

#include "player.h"

class MSMessage {
    public:
        int changeToScene;
        Player player;
        Camera2D camera;

        MSMessage() : changeToScene(0), player(0, 0, 0), camera{0} {}
};

#endif