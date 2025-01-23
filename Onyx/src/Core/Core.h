#pragma once

#ifdef ONYX_PLATFORM_WINDOWS
	#ifdef ONYX_BUILD_DLL
		#define ONYX_API __declspec(dllexport)
    #else
		#define ONYX_API __declspec(dllimport)
	#endif

#else
	#error Onyx only supports Windows!

#endif