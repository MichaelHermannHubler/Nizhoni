#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Nizhoni {
	class NIZHONI_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};

}


// Logger Makros

//#define NI_CORE_FATAL(...)		::Nizhoni::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define NI_CORE_ERROR(...)		::Nizhoni::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NI_CORE_WARN(...)		::Nizhoni::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NI_CORE_INFO(...)		::Nizhoni::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NI_CORE_TRACE(...)		::Nizhoni::Log::GetCoreLogger()->trace(__VA_ARGS__)

//#define NI_FATAL(...)			::Nizhoni::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define NI_ERROR(...)		::Nizhoni::Log::GetClientLogger()->error(__VA_ARGS__)
#define NI_WARN(...)		::Nizhoni::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NI_INFO(...)		::Nizhoni::Log::GetClientLogger()->info(__VA_ARGS__)
#define NI_TRACE(...)		::Nizhoni::Log::GetClientLogger()->trace(__VA_ARGS__)