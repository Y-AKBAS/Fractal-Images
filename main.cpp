
#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include <math.h>

int main() {
    const int width = 1620;
    const int height = 980;

    double min = 99999;
    double max = -min;

    const auto bitMapPtr = std::make_unique<Bitmap>(width, height);
    const std::unique_ptr<int[]> histogramPtr(new int[Mandelbrot::NUMBER_OF_ITERATIONS]{});
    const std::unique_ptr<int[]> fractalPtr(new int[width * height]{});

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double xFractal = (x - width / 2.0 - 240) * 2.0 / height;
            double yFractal = (y - height / 2.0) * 2.0 / height;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            fractalPtr[y * width + x] = iterations;
            if (iterations != Mandelbrot::NUMBER_OF_ITERATIONS) {
                histogramPtr[iterations]++;
            }
        }
    }

    int total{0};
    for (int i = 0; i < Mandelbrot::NUMBER_OF_ITERATIONS; ++i) {
        total += histogramPtr[i];
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            std::uint8_t red{};
            std::uint8_t green{};
            std::uint8_t blue{};

            const int iterations = fractalPtr[y * width + x];
            if (iterations != Mandelbrot::NUMBER_OF_ITERATIONS){

                double hue{0.0};
                for (int i = 0; i < iterations; ++i) {
                    hue += (static_cast<double>(histogramPtr[i])) / total;
                }
                green = std::pow(255, hue);
            }

            bitMapPtr->setPixel(x, y, red, green, blue);
        }
    }

    std::cout << std::boolalpha << "is written: " << bitMapPtr->write("Test.bmp") << std::endl;
    return 0;
}
