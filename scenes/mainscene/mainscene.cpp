#include "raylib-cpp.hpp"

#include "mainscene.h"
#include "player.h"
#include "msmessage.h"

MSMessage mainScene(Player player, int screenWidth, int screenHeight) {
    BeginDrawing();

        ClearBackground(RAYWHITE);
		
		DrawFPS(0, 0);
		
		const char* text = "Welcome to Raft Away";
		int fontSize = 50;
		int textWidth = screenWidth - MeasureText(text, fontSize);
		int textPosWidth = textWidth / 2;
        DrawText(text, textPosWidth, (screenHeight - fontSize) / 2, fontSize, RED);

    EndDrawing();

    MSMessage msg;

    msg.changeToScene = 1;
    msg.player = player;

    return msg;
}