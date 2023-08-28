#include "raylib-cpp.hpp"

#include "player.h"

Player::Player(int screenWidth, int screenHeight, int rad) {
    pos = { (float)screenWidth/2, (float)(screenHeight/2) };
    radius = rad;
}

void Player::handlePlayerMovement() {
    if (IsKeyDown(KEY_D)) pos.x += 2.0f;
    if (IsKeyDown(KEY_A)) pos.x -= 2.0f;
}

void Player::renderPlayer() {
    DrawCircleV(pos, radius, MAROON);
}