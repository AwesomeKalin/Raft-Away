#include "raylib-cpp.hpp"

#include <iostream>

#include "player.h"
#include "mainscene.h"
#include "msmessage.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 1280;
int screenHeight = 720;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(int stateMan);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib::Window window(screenWidth, screenHeight, "Raft Away!");
    SetTargetFPS(60);

    // 0 for Main Menu, 1 for Main Game
    int stateMan = 1;

    // Setup Player
    Player player(screenWidth, screenHeight, 50);

    // Setup Camera
    Camera2D camera = { 0 };
    camera.target = player.pos;
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        if (stateMan == 1) {
            MSMessage msg = mainScene(player, screenWidth, screenHeight, camera);
            player = msg.player;
            camera = msg.camera;
        }
    }

    return 0;
}
