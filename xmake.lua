set_project("my c++ library")

set_version("0.0.1")

set_warnings("all")
set_languages("c++20")

if is_os("windows") then
    set_toolchains("clang-cl")
    set_runtimes("MD")
else
    set_toolchains("clang")
end

add_rules("mode.debug", "mode.releasedbg", "mode.release", "mode.minsizerel")

includes("star")

target("test")
    set_default(true)
    set_kind("binary")
    add_files("star/test/main.cpp")

    add_deps("basic")

    set_rundir("$(projectdir)")

    before_run(function ()
        os.exec("xmake build -w test")
    end)