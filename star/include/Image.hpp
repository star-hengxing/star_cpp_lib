#pragma once

#include <string_view>
#include <optional>

#include "Buffer2D.hpp"
#include "Color.hpp"

struct Image : public Buffer2D<Color>
{
public:
    enum class Type
    {
        JPG,
        PNG,
        PPM,
    };

public:
    Image() = default;
    using Buffer2D::Buffer2D;

    static std::optional<Image> read(const std::string_view& filename);

    static void write(const std::string_view& filename, Image::Type type, const u8* data, usize width, usize height);

    void write(const std::string_view& filename, Type type) const;
};
