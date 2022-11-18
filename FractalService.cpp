
#include "FractalService.h"
#include <cmath>

FractalService::FractalService(int width, int height)
        : width(width), height(height),
          zoomInfoListPtr(std::make_unique<ZoomInfoList>(width, height)),
          bitMapPtr(std::make_unique<Bitmap>(width, height)),
          histogramPtr(new int[Mandelbrot::NUMBER_OF_ITERATIONS]{}),
          fractalPtr(new int[width * height]{}) {}

bool FractalService::handleBitmapCreation(const std::string &file,
                                          const std::shared_ptr<std::vector<ZoomInfo>> &zoomInfos) {
    this->addZoomInfo(zoomInfos);
    this->fillFractal();
    return this->createBitmap(file);
}

void FractalService::addZoomInfo(const std::shared_ptr<std::vector<ZoomInfo>> &zoomInfos) {
    for (const auto &zoomInfo: *zoomInfos) {
        zoomInfoListPtr->add(std::make_shared<ZoomInfo>(zoomInfo));
    }
}

void FractalService::fillFractal() {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            const auto pair = zoomInfoListPtr->doZoom(x, y);
            int iterations = Mandelbrot::getIterations(pair.first, pair.second);
            fractalPtr[y * width + x] = iterations;
            if (iterations != Mandelbrot::NUMBER_OF_ITERATIONS) {
                histogramPtr[iterations]++;
            }
        }
    }
}

bool FractalService::createBitmap(const std::string &file) {
    const int total = findTotal();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            std::uint8_t red{};
            std::uint8_t green{};
            std::uint8_t blue{};

            const int iterations = fractalPtr[y * width + x];
            if (iterations != Mandelbrot::NUMBER_OF_ITERATIONS) {
                double hue{0.0};
                for (int i = 0; i < iterations; ++i) {
                    hue += (static_cast<double>(histogramPtr[i])) / total;
                }
                green = static_cast<std::uint8_t>(std::pow(255.0, hue));
            }
            bitMapPtr->setPixel(x, y, red, green, blue);
        }
    }

    return bitMapPtr->write(file);
}

int FractalService::findTotal() {
    int total{0};
    for (int i = 0; i < Mandelbrot::NUMBER_OF_ITERATIONS; ++i) {
        total += histogramPtr[i];
    }
    return total;
}
