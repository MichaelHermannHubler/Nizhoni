#pragma once

#ifdef NI_PLATFORM_WINDOWS
	#ifdef NI_BUILD_DLL
		#define NIZHONI_API __declspec(dllexport)
	#else 
		#define NIZHONI_API __declspec(dllimport)
	#endif //  NI_BUILD_DLL
#else
	#error NIZHONI only supports Windows
#endif

#define BIT(x) (1 << x)