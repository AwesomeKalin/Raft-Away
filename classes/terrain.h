#include "platform.h"

#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
    public:
        Platform platforms[3] = { Platform(600, 270, 300, 30), Platform(50, 270, 300, 30), Platform(0, 410, 1280, 30) };
        
    Terrain() {}
};

#endif