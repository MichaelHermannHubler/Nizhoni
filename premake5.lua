workspace "Nizhoni"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Nizhoni/vendor/GLFW/include"
IncludeDir["Glad"] = "Nizhoni/vendor/Glad/include"
IncludeDir["SoLoud"] = "Nizhoni/vendor/SoLoud/include"

include "Nizhoni/vendor/GLFW"
include "Nizhoni/vendor/Glad"
include "Nizhoni/vendor/SoLoud"

project "Nizhoni"
	location "Nizhoni"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")
	
	pchheader "nipch.h"
	pchsource "Nizhoni/src/nipch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.SoLoud}"
	}
	
	links {
		"GLFW",
		"Glad",
		"SoLoud",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"NI_PLATFORM_WINDOWS",
			"NI_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NI_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NI_DEBUG"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NI_DIST"
		buildoptions "/MD"
		optimize "On"

	--filter { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Nizhoni/vendor/spdlog/include",
		"Nizhoni/src"
	}

	links {
		"Nizhoni"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"NI_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "NI_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NI_DEBUG"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NI_DIST"
		buildoptions "/MD"
		optimize "On"

	--filter { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"
	