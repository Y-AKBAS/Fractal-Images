#pragma once

struct ZoomInfo {
    int x{0};
    int y{0};
    double scale{0.0};

    ZoomInfo(int x, int y, double scale) : x(x), y(y), scale(scale) {}
};