class Player {
    public:
        Vector2 pos;
        int radius;
        Player(int screenWidth, int screenHeight, int rad) {
            pos = { (float)screenWidth/2, (float)(screenHeight/2) - (rad*2) };
            radius = rad;
        }
};