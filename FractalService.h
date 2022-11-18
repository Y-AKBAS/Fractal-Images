#pragma once

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomInfo.h"
#include "ZoomInfoList.h"

class FractalService {
public:
    FractalService(int width, int height);

    bool handleBitmapCreation(const std::string &file, const std::shared_ptr<std::vector<ZoomInfo>> &zoomInfos);

private:

    void fillFractal();

    int findTotal();

    bool createBitmap(const std::string &file);

    void addZoomInfo(const std::shared_ptr<std::vector<ZoomInfo>> &zoomInfos);

    int width;
    int height;
    const std::unique_ptr<ZoomInfoList> zoomInfoListPtr{nullptr};
    const std::unique_ptr<Bitmap> bitMapPtr{nullptr};
    const std::unique_ptr<int[]> histogramPtr{nullptr};
    const std::unique_ptr<int[]> fractalPtr{nullptr};
};