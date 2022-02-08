#pragma once

#ifdef CP_PLATFORM_WINDOWS
	#ifdef CP_BUILD_DLL
		#define CP_API __declspec(dllexport)
	#else
		#define CP_API __declspec(dllimport)
	#endif // CP_BUILD_DLL
#else
#error MCC only supports Windows
#endif // CP_PLATFORM_WINDOWS
