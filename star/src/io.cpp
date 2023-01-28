#include <fstream>

#include <star/io.hpp>

NAMESPACE_BEGIN(io)
NAMESPACE_BEGIN(file)

auto read(const char* filename) -> std::tuple<Box<char[]>, usize>
{
    std::ifstream in(filename, std::ios::in | std::ios::ate);
    if (in.fail())
    {
        return {nullptr, 0};
    }

    const usize size = in.tellg();
    in.seekg(0, std::ios::beg);

    auto buffer = Box<char[]>(new char[size]);
    in.read(buffer.get(), size);

    in.close();
    return {std::move(buffer), size};
}

NAMESPACE_END(file)
NAMESPACE_END(io)
