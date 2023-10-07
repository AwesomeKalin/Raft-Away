#include "raylib-cpp.hpp"

#include <ostream>

#include "terrainrender.h"
#include "terrain.h"

void renderTerrain(Terrain* terrain) {

    for (int i = 0; i <= (sizeof(terrain->platforms)/sizeof(terrain->platforms[0])); i++) {
        DrawRectangle(terrain->platforms[i].x, terrain->platforms[i].y, terrain->platforms[i].width, terrain->platforms[i].height, YELLOW);
    }
}