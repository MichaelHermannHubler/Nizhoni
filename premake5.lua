workspace "Nizhoni"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["ImGui"] = "Nizhoni/vendor/ImGui"

include "Nizhoni/vendor/_premakes/GLFW"
include "Nizhoni/vendor/_premakes/Glad"
include "Nizhoni/vendor/_premakes/SoLoud"
include "Nizhoni/vendor/_premakes/ImGui"

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
		"%{IncludeDir.SoLoud}",
		"%{IncludeDir.ImGui}"
	}
	
	links {
		"GLFW",
		"Glad",
		"SoLoud",
		"ImGui",
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
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
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
		"%{prj.name}/src/**.cpp",
		"%{IncludeDir.SoLoud}"
	}

	includedirs {
		"Nizhoni/vendor/spdlog/include",
		"Nizhoni/vendor/SoLoud/include",
		"Nizhoni/src",
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

		postbuildcommands {
			("{COPYDIR} ../Sandbox/Data ../bin/" .. outputdir .. "/Sandbox/Data")
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
	