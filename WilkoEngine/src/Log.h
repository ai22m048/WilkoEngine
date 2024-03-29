#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace WilkoEngine {

	class WILKO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define WE_CORE_FATAL(...)		::WilkoEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define WE_CORE_ERROR(...)		::WilkoEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WE_CORE_WARN(...)		::WilkoEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WE_CORE_INFO(...)		::WilkoEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WE_CORE_TRACE(...)		::WilkoEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define WE_FATAL(...)		::WilkoEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define WE_ERROR(...)		::WilkoEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define WE_WARN(...)		::WilkoEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WE_INFO(...)		::WilkoEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define WE_TRACE(...)		::WilkoEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
