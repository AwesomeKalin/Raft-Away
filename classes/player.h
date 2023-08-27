#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Vector2 pos;
        int radius;
        Player(int screenWidth, int screenHeight, int rad);
};

#endif