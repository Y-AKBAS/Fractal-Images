#pragma once

#include <cstdint>

#pragma pack(push, 2)

struct BitmapFileInfo {
    char headerChars[2]{'B', 'M'};
    std::int32_t fileSize{};
    std::int32_t reserved{};
    std::int32_t dataOffset{};
};

#pragma pack(pop)