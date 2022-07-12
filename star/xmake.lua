add_requires("stb")

if is_os("windows") then
    add_defines("_CRT_SECURE_NO_WARNINGS")
    -- add_cxflags("/utf-8")
end

target("star")
    set_kind("static")
    add_includedirs("include", {public = true})
    add_files("src/*.cpp")
    add_packages("stb")