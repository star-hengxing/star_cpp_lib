#pragma once

#include <iostream>
#include <memory>
#include <tuple>

#include "basic_type.hpp"
#include "marco.hpp"

auto read_file(const char* filename) -> std::tuple<std::unique_ptr<char[]>, usize>;

template <typename... Args>
auto println(const Args&... args) -> void
{
    ((std::cout << args << '\n'), ...);
}

template <typename... Args>
auto print(const Args&... args) -> void
{
    ((std::cout << args << ' '), ...);
}
