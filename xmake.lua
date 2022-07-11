set_project("my c++ library")

add_requires("stb")

set_toolchains("clang")
set_languages("c++20")

if is_os("windows") then
    add_defines("_CRT_SECURE_NO_WARNINGS")
    -- add_cxflags("/utf-8")
end

target("star")
    set_kind("static")
    add_includedirs("star/include", {public = true})
    add_files("star/src/*.cpp")
    add_packages("stb")

target("main")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("star")

    set_rundir("$(projectdir)")

    before_run(function ()
        os.exec("xmake build -w main")
    end)