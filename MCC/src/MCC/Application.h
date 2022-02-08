#pragma once

#include "Window.h"

#include "Core.h"
#include "Log.h"
namespace CP {
	class CP_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void Close();

		Window& GetWindow() { return m_Window; };

		static Application& Get() { return *s_Instance; };

	private:
		Window m_Window;
		bool m_Running = true;
		static Application* s_Instance;
	};

	// To be defined in the client
	void CpInit();
	Application* CreateApplication();
}

