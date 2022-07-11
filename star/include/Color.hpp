#pragma once

#include <cstdint>

using u8 = std::uint8_t;

struct Color
{
    u8 r, g, b, a;

public:
    Color() {};
    Color(u8 r, u8 g, u8 b, u8 a = 255) : r(r), g(g), b(b), a(a) {}
    Color(u8 v) : Color(v, v, v) {}
};
