workspace "Nizhoni"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines {
			"NI_PLATFORM_WINDOWS",
			"NI_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NI_DEBUG"
		optimize "On"

	filter "configurations:Dist"
		defines "NI_DIST"
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
		staticruntime "Off"
		systemversion "latest"

		defines {
			"NI_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "NI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NI_DEBUG"
		optimize "On"

	filter "configurations:Dist"
		defines "NI_DIST"
		optimize "On"

	--filter { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"
	