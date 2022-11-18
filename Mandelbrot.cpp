
#include "Mandelbrot.h"
#include <complex>

Mandelbrot::Mandelbrot() {}

Mandelbrot::~Mandelbrot() {}

int Mandelbrot::getIterations(const double &x, const double &y) {

    const std::complex<double> coordinate(x, y);
    std::complex<double> axis{0};
    int iterations = 0;

    while (iterations < NUMBER_OF_ITERATIONS) {
        axis = axis * axis + coordinate;

        if (std::abs(axis) > 2) {
            break;
        }

        ++iterations;
    }
    return iterations;
}
