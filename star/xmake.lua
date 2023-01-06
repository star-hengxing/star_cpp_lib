option("image")
    set_default(false)
    set_showmenu(true)
    set_description("Enable image component (default: false)")
option_end()

if has_config("image") then
    add_requires("stb")
end

add_includedirs("include", {public = true})

target("star")
    set_kind("$(kind)")
    add_files("src/io.cpp")
    if has_config("image") then
        add_files("src/image.cpp")
        add_packages("stb")
        if is_host("windows") then
            add_defines("_CRT_SECURE_NO_WARNINGS")
        end
    end

    if is_kind("shared") and is_plat("windows") then
        add_rules("utils.symbols.export_all", {export_classes = true})
    end
target_end()
