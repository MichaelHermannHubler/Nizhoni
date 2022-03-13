#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nizhoni {
	class NIZHONI_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		static inline int i_Core_Loglevel = 0;
		static inline int i_Client_Loglevel = 0;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		static inline int GetCoreLogLevel() { return i_Core_Loglevel; }
		static inline int GetClientLogLevel() { return i_Client_Loglevel; }

		static void SetCoreLogLevel(int i) { i_Core_Loglevel = i; }
		static void SetClientLogLevel(int i) { i_Client_Loglevel = i; }
	};

}


// Log Level Makros

#define NI_SET_CORE_LOGLEVEL(x)	::Nizhoni::Log::SetCoreLogLevel(x)
#define NI_SET_LOGLEVEL(x)		::Nizhoni::Log::SetClientLogLevel(x)

#define NI_LOG_LEVEL_CRITICAL	4
#define NI_LOG_LEVEL_ERROR		3
#define NI_LOG_LEVEL_WARN		2
#define NI_LOG_LEVEL_INFO		1
#define NI_LOG_LEVEL_TRACE		0

// Logger Makros

#define NI_CORE_CRITICAL(...)	::Nizhoni::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define NI_CORE_ERROR(...)		if(::Nizhoni::Log::GetCoreLogLevel() <= 3){ ::Nizhoni::Log::GetCoreLogger()->error(__VA_ARGS__); }
#define NI_CORE_WARN(...)		if(::Nizhoni::Log::GetCoreLogLevel() <= 2){ ::Nizhoni::Log::GetCoreLogger()->warn(__VA_ARGS__); }
#define NI_CORE_INFO(...)		if(::Nizhoni::Log::GetCoreLogLevel() <= 1){ ::Nizhoni::Log::GetCoreLogger()->info(__VA_ARGS__); }
#define NI_CORE_TRACE(...)		if(::Nizhoni::Log::GetCoreLogLevel() == 0){ ::Nizhoni::Log::GetCoreLogger()->trace(__VA_ARGS__); }

#define NI_CRITICAL(...)		::Nizhoni::Log::GetClientLogger()->critical(__VA_ARGS__)
#define NI_ERROR(...)			if(::Nizhoni::Log::GetClientLogLevel() <= 3){ ::Nizhoni::Log::GetClientLogger()->error(__VA_ARGS__); }
#define NI_WARN(...)			if(::Nizhoni::Log::GetClientLogLevel() <= 2){ ::Nizhoni::Log::GetClientLogger()->warn(__VA_ARGS__); }
#define NI_INFO(...)			if(::Nizhoni::Log::GetClientLogLevel() <= 1){ ::Nizhoni::Log::GetClientLogger()->info(__VA_ARGS__); }
#define NI_TRACE(...)			if(::Nizhoni::Log::GetClientLogLevel() == 0){ ::Nizhoni::Log::GetClientLogger()->trace(__VA_ARGS__); }
