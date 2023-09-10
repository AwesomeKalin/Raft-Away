#include "raylib-cpp.hpp"

#include "player.h"

Player::Player(int screenWidth, int screenHeight, int rad) {
    pos = { (float)screenWidth/2, (float)(screenHeight/2) };
    radius = rad;
    preJumpY = pos.y;
    floorPos = pos.y;
}

void Player::handlePlayerMovement() {
    if (IsKeyDown(KEY_D)) pos.x += 2.0f;
    if (IsKeyDown(KEY_A)) pos.x -= 2.0f;
    if ((IsKeyDown(KEY_SPACE)) || (jumping == true)) jump();
    if ((jumping == false) & ((pos.x < 50) || (pos.x > 350))) fall();
}

void Player::renderPlayer() {
    DrawCircleV(pos, radius, MAROON);
}

void Player::jump() {
    if (!jumping) {
        jumping = true;
        preJumpY = pos.y;
        jumpSpeed = 20;
    }

    pos.y -= jumpSpeed;
    jumpSpeed -= GRAVITY;

    if (pos.y >= floorPos & jumpSpeed < 0) {
        pos.y = floorPos;
        jumpSpeed = 0;
        jumping = false;
    }

    if (pos.x > 50 & pos.x < 350) {
        floorPos = 220;
    } else {
        floorPos = 360;
    }
}

void Player::fall() {
    if (pos.x > 50 & pos.x < 350) {
        floorPos = 220;
    } else {
        floorPos = 360;
    }

    jumpSpeed -= GRAVITY;
    pos.y -= jumpSpeed;

    if (pos.y >= floorPos & jumpSpeed < 0) {
        pos.y = floorPos;
        jumpSpeed = 0;
    }
}