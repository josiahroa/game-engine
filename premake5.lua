workspace "Onyx"
    architecture "x64"

    configurations
    {
        "Dubug",
        "Release",
        "Dist"
    }

outputdir = ""

project "Onyx"
    location "Onyx"
    kind "SharedLib"
    language "C++"

    targetDir ("bin/")

ONYX_PLATFORM_WINDOWS;ONYX_BUILD_DLL