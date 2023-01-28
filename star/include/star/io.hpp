#pragma once

#include <iostream>
#include <tuple>

#include "basic_type.hpp"
#include "marco.hpp"
#include "Box.hpp"

NAMESPACE_BEGIN(io)

NAMESPACE_BEGIN(file)

auto read(const char* filename) -> std::tuple<Box<char[]>, usize>;

NAMESPACE_END(file)

auto println(const auto&... args) -> void
{
    ((std::cout << args << '\n'), ...);
}

auto print(const auto&... args) -> void
{
    auto i = sizeof...(args);
    const auto delim = [&i] { i -= 1; return (i != 0) ? " " : ""; };
    ((std::cout << args << delim()), ...);
}

NAMESPACE_END(io)
