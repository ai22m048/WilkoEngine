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