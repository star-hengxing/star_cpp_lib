set_project("my c++ library")

set_version("0.0.1")

set_warnings("all")
set_languages("c++20")

if is_plat("windows") then
    set_runtimes("MD")
end

-- support utf-8 with bom on msvc
if is_host("windows") then
    add_defines("UNICODE", "_UNICODE")
    add_cxflags("/execution-charset:utf-8", "/source-charset:utf-8", {tools = {"clang_cl", "cl"}})
end

add_rules("mode.debug", "mode.releasedbg", "mode.release", "mode.minsizerel")

includes("star")

target("test")
    set_default(true)
    set_kind("binary")
    add_files("star/test/main.cpp")

    add_deps("star")

    set_rundir("$(projectdir)")

    after_build(function (target)
        local rundir = target:rundir()
        local targetfile = path.absolute(target:targetfile())
        local args = table.wrap(target:get("runargs"))
        os.execv(targetfile, args, {curdir = rundir})
    end)
target_end()
