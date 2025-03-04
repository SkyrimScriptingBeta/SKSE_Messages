add_rules("mode.debug", "mode.release")

set_languages("c++23")

add_repositories("SkyrimScripting https://github.com/SkyrimScripting/Packages.git")

mods_folders = os.getenv("SKYRIM_MODS_FOLDERS")

if mods_folders then
    mod_info.mods_folders = mods_folders
else
    print("SKYRIM_MODS_FOLDERS environment variable not set")
end

for _, game_version in ipairs(skyrim_versions) do
    add_requires("skyrim-commonlib-" .. game_version)
    add_requires("SkyrimScripting.Entrypoint", { configs = { commonlib = "skyrim-commonlib-" .. game_version } })
    add_requires("SkyrimScripting.Logging", { configs = { commonlib = "skyrim-commonlib-ae", use_log_library = true, include_repo_mrowrlib = true }})
    add_requires("_Log_")
end

for _, game_version in ipairs(skyrim_versions) do
    target("StaticLibrary-" .. game_version:upper())
        set_kind("static")
        add_files("src/*.cpp")
        add_includedirs("include", { public = true }) -- Your library's own include path
        add_packages("skyrim-commonlib-" .. game_version)
        add_packages("_Log_", "global_macro_functions", { public = true })
        add_packages("SkyrimScripting.Entrypoint", { public = true })
        add_packages("SkyrimScripting.Logging", { public = true })
        add_packages("_Log_")

    target("_SksePlugin-" .. game_version:upper())
        set_basename(mod_info.name .. "-" .. game_version:upper())
        add_files("*.cpp")
        add_packages("skyrim-commonlib-" .. game_version)
        add_rules("@skyrim-commonlib-" .. game_version .. "/plugin", {
            mod_name = mod_info.name .. " (" .. game_version:upper() .. ")",
            mods_folders = mod_info.mods_folders or "",
            mod_files = mod_info.mod_files,
            name = mod_info.name,
            version = mod_info.version,
            author = mod_info.author,
            email = mod_info.email
        })
        add_deps("StaticLibrary-" .. game_version:upper())
        add_packages("_Log_")
end
