
#include "RGB.h"

RGB::RGB(double red, double green, double blue) : red(red), green(green), blue(blue) {}

RGB operator-(const RGB &left, const RGB &right) {
    return {left.red - right.red, left.green - right.green, left.blue - right.blue};
}

RGB operator+(const RGB &left, const RGB &right) {
    return {left.red + right.red, left.green + right.green, left.blue + right.blue};
}

RGB operator*(const RGB &left, const double &hue) {
    return {left.red * hue, left.green * hue, left.blue * hue};
}
