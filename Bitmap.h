#pragma once

#include <string>
#include <memory>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

class Bitmap {
public:
    Bitmap();

    Bitmap(int width, int height);

    bool write(const std::string &fileName);

    void setPixel(const int &x, const int &y, const std::uint8_t &red,
                  const std::uint8_t &green, const std::uint8_t &blue);

    virtual ~Bitmap();

private:
    int height{};
    int width{};
    std::unique_ptr<std::uint8_t[]> pixelPtr{nullptr};
};