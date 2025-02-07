#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Onyx {
	class ONYX_API Log
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
#define NX_CORE_TRACE(...) ::Onyx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NX_CORE_INFO(...)  ::Onyx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NX_CORE_WARN(...)  ::Onyx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NX_CORE_ERROR(...) ::Onyx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NX_CORE_FATAL(...) ::Onyx::Log::GetCoreLoggeR()->fatal(__VA_ARGS__)

// Client log macros
#define NX_TRACE(...) ::Onyx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NX_INFO(...)  ::Onyx::Log::GetClientLogger()->info(__VA_ARGS__)
#define NX_WARN(...)  ::Onyx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NX_ERROR(...) ::Onyx::Log::GetClientLogger()->error(__VA_ARGS__)
#define NX_FATAL(...) ::Onyx::Log::GetClientLoggeR()->fatal(__VA_ARGS__)