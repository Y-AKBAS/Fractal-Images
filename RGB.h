
#pragma once

struct RGB {
    double red;
    double green;
    double blue;

    RGB(double red, double green, double blue);
};

RGB operator-(const RGB &left, const RGB &right);
RGB operator+(const RGB &left, const RGB &right);
RGB operator*(const RGB &left, const double &hue);
