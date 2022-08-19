set_project("my c++ library")

set_version("0.0.1")

add_rules("mode.debug", "mode.release")

set_toolchains("clang")
set_languages("c++20")

includes("star")

target("main")
    set_kind("binary")
    add_files("star/main.cpp")
    add_deps("star")

    set_rundir("$(projectdir)")

    before_run(function ()
        os.exec("xmake build -w main")
    end)