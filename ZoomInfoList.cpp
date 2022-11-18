
#include "ZoomInfoList.h"

ZoomInfoList::ZoomInfoList(int width, int height)
        : width(width), height(height), zoomInfos(std::make_shared<std::vector<std::shared_ptr<ZoomInfo>>>()) {}

void ZoomInfoList::add(const std::shared_ptr<ZoomInfo> &&zoomInfoPtr) {
    this->zoomInfos->push_back(zoomInfoPtr);

    this->xCenter += (zoomInfoPtr->x - this->width / 2) * this->scale;
    this->yCenter += (zoomInfoPtr->y - this->height / 2) * this->scale;

    this->scale *= zoomInfoPtr->scale;
}

std::pair<double, double> ZoomInfoList::doZoom(const int &x, const int &y) const {
    const double xFractal = (x - this->width / 2 - 200) * this->scale + this->xCenter;
    const double yFractal = (y - this->height / 2) * this->scale + this->yCenter;

    return {xFractal, yFractal};
}
