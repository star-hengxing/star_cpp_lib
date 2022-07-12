#pragma once

#include <cstdlib>
#include <iostream>
#include <string_view>
#include <tuple>

using usize = std::size_t;

std::tuple<std::unique_ptr<char[]>, usize> read_file(const std::string_view& filename);

template <typename... Args>
void println(const Args&... args)
{
    ((std::cout << args << '\n'), ...);
}

template <typename... Args>
void print(const Args&... args)
{
    ((std::cout << args << ' '), ...);
}
