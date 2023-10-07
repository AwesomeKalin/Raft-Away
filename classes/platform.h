#ifndef PLATFORM_H
#define PLATFORM_H

class Platform {
    public:
        int x;
        int y;
        int width;
        int height;

    Platform(int x1, int y1, int width1, int height1) : x(0), y(0), width(0), height(0) {
        x = x1;
        y = y1;
        width = width1;
        height = height1;
    }
};

#endif