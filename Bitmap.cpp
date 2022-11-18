
#include "Bitmap.h"
#include <fstream>

Bitmap::Bitmap() = default;

Bitmap::~Bitmap() = default;

bool Bitmap::write(const std::string &fileName) {
    const auto fileHeader = std::make_unique<BitmapFileInfo>();
    const auto infoHeader = std::make_unique<BitmapInfoHeader>();

    size_t headerSizes = sizeof(*fileHeader) + sizeof(*infoHeader);
    fileHeader->fileSize = headerSizes + width * height * 3;
    fileHeader->dataOffset = headerSizes;

    infoHeader->height = height;
    infoHeader->width = width;

    const auto filePtr = std::make_unique<std::fstream>(fileName, std::ios::out | std::ios::binary);

    if (!filePtr->is_open()) {
        return false;
    }

    filePtr->write(reinterpret_cast<char *>(fileHeader.get()), sizeof(*fileHeader));
    filePtr->write(reinterpret_cast<char *>(infoHeader.get()), sizeof(*infoHeader));
    filePtr->write(reinterpret_cast<char *>(pixelPtr.get()), width * height * 3);

    filePtr->close();
    return true;
}

void Bitmap::setPixel(const int &x, const int &y, const uint8_t &red, const uint8_t &green, const uint8_t &blue) {

    uint8_t *ptr = pixelPtr.get();
    ptr += (y * 3) * width + (x * 3);

    ptr[0] = blue;
    ptr[1] = green;
    ptr[2] = red;
}

Bitmap::Bitmap(int width, int height) : width(width), height(height),
                                        pixelPtr{std::make_unique<std::uint8_t[]>(width * height * 3)} {}
