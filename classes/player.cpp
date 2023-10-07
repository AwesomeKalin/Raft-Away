#include "raylib-cpp.hpp"

#include "player.h"
#include "terrain.h"

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
    if ((jumping == false) && checkFloor(new Terrain(), pos.x, pos.y)) fall();
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

bool Player::checkFloor(Terrain* terrain, int xpos, int ypos) {
    for (int i = 0; i <= (sizeof(terrain->platforms)/sizeof(terrain->platforms[0])); i++) {
        if (xpos > terrain->platforms[i].x || xpos < (terrain->platforms[i].x + terrain->platforms[i].width) || ypos > terrain->platforms[i].y) {
            return true;
        }
    }

    return false;
}