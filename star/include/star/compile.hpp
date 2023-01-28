#pragma once

#include <string>

#include "marco.hpp"

NAMESPACE_BEGIN(compile)

constexpr auto concat(auto... strings) -> std::string
{
    return (std::string{strings} + ...);
}

NAMESPACE_END(compile)
