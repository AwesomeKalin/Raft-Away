#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Vector2 pos;
        int radius;
        bool jumping = false;
        int GRAVITY = 1;
        int jumpSpeed = 0;
        int preJumpY;
        int floorPos;
        Player(int screenWidth, int screenHeight, int rad);
        void handlePlayerMovement();
        void renderPlayer();
        void jump();
        void fall();
};

#endif