
#include <iostream>
#include "FractalService.h"

int main() {

    const int width = 1620;
    const int height = 1020;

    const auto fractalServicePtr = std::make_unique<FractalService>(width, height);
    const std::shared_ptr<std::vector<ZoomInfo>> zoomInfos = std::make_shared<std::vector<ZoomInfo>>();
    zoomInfos->push_back({width / 2, height / 2, 4.0 / width});

    const std::string finalMessage = fractalServicePtr->handleBitmapCreation("Test.bmp", zoomInfos) ? "SUCCESS"
                                                                                                    : "FAILED";
    std::cout << finalMessage << std::endl;
    return 0;
}
