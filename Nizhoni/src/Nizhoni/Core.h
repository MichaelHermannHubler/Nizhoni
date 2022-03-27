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

#ifdef NI_ENABLE_ASSERTS
	#define NI_ASSERT(x, ...) { if(!(x)) {NI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NI_CORE_ASSERT(x, ...) { if(!(x)) {NI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NI_ASSERT(x, ...)
	#define NI_CORE_ASSERT(x, ...)
#endif

#define NI_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)