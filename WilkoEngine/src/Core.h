#pragma once

#ifdef WE_PLATFORM_WINDOWS
	#ifdef WE_BUILD_DLL
		#define WILKO_API __declspec(dllexport)
	#else
		#define WILKO_API __declspec(dllimport)
	#endif
#else
	#error WilkoEngine only support Windows!
#endif

#ifdef WE_ENABLE_ASSERTS
	#define WE_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WE_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WE_ASSERT(x, ...)
	#define WE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)