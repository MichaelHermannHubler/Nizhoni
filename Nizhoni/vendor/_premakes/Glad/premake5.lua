project "Glad"

	kind "StaticLib"
	language "C"
	staticruntime "On"

	targetdir ("../../Glad/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../../Glad/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"../../Glad/include/glad/glad.h",
		"../../Glad/include/KHR/khrplatform.h",
		"../../Glad/src/glad.c"
	}
	
	includedirs 
	{
		"../../Glad/include"
	}

	filter "system:linux"
		pic "On"
		systemversion "latest"		

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
