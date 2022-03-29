project "SoLoud"	
	kind "StaticLib"
	language "C++"
	staticruntime "On"

	targetdir ("../../Soloud/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../../Soloud/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"../../Soloud/src/audiosource/**.c*",
		"../../Soloud/src/filter/**.c*",
		"../../Soloud/src/core/**.c*"
	}
	  
	includedirs 
	{
		"../../Soloud/src/**",
		"../../Soloud/include"
	}

	filter "system:linux"
		pic "On"
		systemversion "latest"	
		defines {
			"WITH_OSS"
		}		
		files
		{
			"../../Soloud/src/backend/oss/**.c*",
		}
		includedirs
		{
			"../../Soloud/include"
		}
		

	filter "system:windows"
		systemversion "latest"
		defines {
			"WITH_WINMM"
		}
		files
		{
			"../../Soloud/src/backend/winmm/**.c*",
		}
		includedirs 
		{
			"../../Soloud/include"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
