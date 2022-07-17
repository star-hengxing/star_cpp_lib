#pragma once

#include <cstdlib>
#include <iostream>
#include <tuple>

using usize = std::size_t;

std::tuple<std::unique_ptr<char[]>, usize> read_file(const char* filename);

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
