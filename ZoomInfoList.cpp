
#include <iostream>
#include "ZoomInfoList.h"
#include <memory>

ZoomInfoList::ZoomInfoList(int width, int height)
        : width(width), height(height), zoomInfos(std::make_shared<std::vector<std::shared_ptr<ZoomInfo>>>()) {}

void ZoomInfoList::add(const std::shared_ptr<ZoomInfo> &&zoomInfoPtr) {
    zoomInfos->push_back(zoomInfoPtr);

    xCenter += (zoomInfoPtr->x - this->width / 2) * this->scale;
    yCenter += (zoomInfoPtr->y - this->height / 2) * this->scale;

    this->scale *= zoomInfoPtr->scale;
    std::cout << xCenter << yCenter << scale << std::endl;
}

std::pair<double, double> ZoomInfoList::doZoom(const int &x, const int &y) {
    return std::pair<double, double>();
}
