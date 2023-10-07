#include "raylib-cpp.hpp"

#include <cstring>

#include "mainscene.h"
#include "player.h"
#include "msmessage.h"
#include "terrainrender.h"

MSMessage mainScene(Player player, int screenWidth, int screenHeight, Camera2D camera) {
    player.handlePlayerMovement();
    camera.target = player.pos;

    BeginDrawing();

        ClearBackground(SKYBLUE);

        BeginMode2D(camera);

            player.renderPlayer();
            renderTerrain(new Terrain());

        EndMode2D();

        char xpos[11];
        snprintf(xpos, sizeof xpos, "%f", player.pos.x);

        char ypos[11];
        snprintf(ypos, sizeof ypos, "%f", player.pos.y);

        char xtext[11] = "Player X: ";
        char ytext[11] = "Player Y: ";
		
		char text1[22];
        char text2[22];

        strcpy(text1, xtext);
        strcat(text1, xpos);

        strcpy(text2, ytext);
        strcat(text2, ypos);

		int fontSize = 50;
		int textWidth = screenWidth - MeasureText(text1, fontSize);
		int textPosWidth = textWidth / 2;
        DrawText(text1, 0, 0, fontSize, RED);

        DrawText(text2, 0, fontSize, fontSize, GREEN);

    EndDrawing();

    MSMessage msg;

    msg.changeToScene = 1;
    msg.player = player;
    msg.camera = camera;

    return msg;
}