workspace "WilkoEngine"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "WilkoEngine/vendor/GLFW/include"

include "WilkoEngine/vendor/GLFW"

project "WilkoEngine"
	location "WilkoEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wepch.h"
	pchsource "WilkoEngine/src/wepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WE_PLATFORM_WINDOWS",
			"WE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"WilkoEngine/vendor/spdlog/include",
		"WilkoEngine/src"
	}

	links
	{
		"WilkoEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WE_DIST"
		optimize "On"
