#pragma once

#include <string_view>
#include <array>

template <const std::string_view&... strings>
struct join
{
    static constexpr auto impl() noexcept
    {
        constexpr auto size = (strings.size() + ... + 0);
        std::array<char, size + 1> array;
        auto append = [i = 0, &array](const auto& s) mutable {
            for (auto c : s)
                array[i++] = c;
        };

        (append(strings), ...);
        array[size] = '\0';
        return array;
    }

    static constexpr auto array = impl();

    static constexpr std::string_view value{array.data(), array.size() - 1};
};

template <const std::string_view&... strings>
static constexpr auto join_v = join<strings...>::value;
