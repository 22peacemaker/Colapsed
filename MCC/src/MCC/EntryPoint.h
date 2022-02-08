#pragma once
#pragma once

#include "Application.h"
#include "Log.h"
#ifdef CP_PLATFORM_WINDOWS
extern CP::Application* CP::CreateApplication();

int main(int argc, char** argv) {
	
	CP::CpInit();

	auto app = CP::CreateApplication();
	app->Run();
	delete app;
}

#endif // CP_PLATFORM_WINDOWS

