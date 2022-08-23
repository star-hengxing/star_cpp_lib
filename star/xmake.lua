add_requires("stb", "lz4 1.9.3")

add_includedirs("include", {public = true})

target("basic")
    set_kind("static")
    add_files("src/io.cpp")

target("image")
    set_kind("static")
    add_files("src/image.cpp")
    add_packages("stb")

    if is_os("windows") then
        add_defines("_CRT_SECURE_NO_WARNINGS")
    end

target("compression")
    set_kind("static")
    add_files("src/Asset/*.cpp")
    add_packages("lz4")

target("star")
    set_kind("static")
    add_deps("basic", "image", "compression")