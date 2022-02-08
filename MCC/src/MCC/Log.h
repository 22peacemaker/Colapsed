#pragma once


#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace CP {
	class CP_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define MCC_CORE_TRACE(...) ::CP::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MCC_CORE_INFO(...)  ::CP::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MCC_CORE_WARN(...)  ::CP::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MCC_CORE_ERROR(...) ::CP::Log::GetCoreLogger()->error(__VA_ARGS__)

#define MCC_TRACE(...)      ::CP::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MCC_INFO(...)       ::CP::Log::GetClientLogger()->info(__VA_ARGS__)
#define MCC_WARN(...)       ::CP::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MCC_ERROR(...)      ::CP::Log::GetClientLogger()->error(__VA_ARGS__)