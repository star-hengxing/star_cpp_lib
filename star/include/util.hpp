#pragma once

#include <source_location>
#include <iostream>
#include <ranges>

#include <range.hpp>

#ifdef NDEBUG
#define dbg(expr) ((void)0)
#else
#define dbg(expr) std::cout<< '[' << std::source_location::current().file_name() << ':'<< std::source_location::current().line() << "] " << #expr << " = " << expr << '\n';
#endif // NDEBUG

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
