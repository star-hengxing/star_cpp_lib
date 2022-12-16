#pragma once

#include <iostream>

#include "range.hpp"

inline void debug_marco(const char* path, int line, const char* function, const char* expr, const auto& value)
{
    printf("[%s:%d] %s: %s = ", path, line, function, expr);
    std::cout << value << std::endl;
}

#define dbg(expr) debug_marco(__FILE__, __LINE__, __PRETTY_FUNCTION__, #expr, expr)

template <std::ranges::range Container1, std::ranges::range Container2, std::copy_constructible Function>
void map(const Container1& src, Container2& dst, Function f)
{
    std::ranges::transform(src.begin(), src.end(), dst.begin(), f);
    // std::ranges::copy(std::views::transform(src, f), dst.begin());
}

template <typename T>
void for_each(usize size, T fn)
{
    if constexpr(std::is_void_v<decltype(fn())>)
    {
        for([[maybe_unused]] auto _ : range(size))
        {
            fn();
        }
    }
}

template <typename T>
concept not_void = !std::is_void_v<T>;

template <typename T> requires
requires(T fn) { { fn() } -> not_void; }
constexpr auto arithmetic_mean(usize size, T fn)
{
    decltype(fn()) sum = 0;
    for([[maybe_unused]] auto _ : range(size))
    {
        sum += fn();
    }
    return sum / size;
}
