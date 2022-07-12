#include <fstream>

#include <io.hpp>

std::tuple<std::unique_ptr<char[]>, usize> read_file(const std::string_view& filename)
{
    std::ifstream in(filename.data(), std::ios::in | std::ios::ate);
    if(in.fail()) return {nullptr, 0};

    const usize size = in.tellg();
    in.seekg(0, std::ios::beg);

    auto buffer = std::make_unique<char[]>(size + 1);
    in.read(buffer.get(), size);
    buffer[size] = '\0';

    in.close();
    return {std::move(buffer), size};
}
