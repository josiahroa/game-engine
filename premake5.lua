workspace "Onyx"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Dubug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Onyx"
    location "Onyx"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/${prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"
        
        defines {
            "ONYX_PLATFORM_WINDOWS", 
            "ONYX_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        buildoptions "/utf-8"
    
    filter "configurations:Debug"
        defines "ONYX_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ONYX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ONYX_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/${prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Onyx/vendor/spdlog/include",
        "Onyx/src"
    }

    links
    {
        "Onyx"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"
        
        defines {
            "ONYX_PLATFORM_WINDOWS", 
        }

        buildoptions "/utf-8"
    
    filter "configurations:Debug"
        defines "ONYX_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ONYX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ONYX_DIST"
        optimize "On"

    


    