#include <fstream>

#include <star/io.hpp>

auto read_file(const char* filename) -> std::tuple<std::unique_ptr<char[]>, usize>
{
    std::ifstream in(filename, std::ios::in | std::ios::ate);
    if (in.fail())
    {
        return {nullptr, 0};
    }

    const usize size = in.tellg();
    in.seekg(0, std::ios::beg);

    auto buffer = std::unique_ptr<char[]>(new char[size]);
    in.read(buffer.get(), size);

    in.close();
    return {std::move(buffer), size};
}
