#pragma once

#include <vector>
#include <memory>
#include "ZoomInfo.h"

class ZoomInfoList {
public:
    ZoomInfoList(int width, int height);

    void add(const std::shared_ptr<ZoomInfo> &&zoomInfoPtr);

    [[nodiscard]] std::pair<double, double> doZoom(const int &x, const int &y) const;

private:
    double xCenter{};
    double yCenter{};
    double scale{1.0};

    int width{};
    int height{};
    const std::shared_ptr<std::vector<std::shared_ptr<ZoomInfo>>> zoomInfos{};
};
