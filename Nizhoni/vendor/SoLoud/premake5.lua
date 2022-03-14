project "SoLoud"
	kind "StaticLib"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/audiosource/**.c*",
		"src/filter/**.c*",
		"src/core/**.c*"
	}
	  
	includedirs 
	{
		"src/**",
		"include"
	}

	filter "system:linux"
		pic "On"
		systemversion "latest"	
		defines {
			"WITH_OSS"
		}		
		files
		{
			"src/backend/oss/**.c*",
		}
		includedirs
		{
			"include"
		}
		

	filter "system:windows"
		systemversion "latest"
		defines {
			"WITH_WINMM"
		}
		files
		{
			"src/backend/winmm/**.c*",
		}
		includedirs 
		{
			"include"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
