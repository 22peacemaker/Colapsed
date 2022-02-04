#pragma once

#include <string>

#include "gfx/Window.h"

namespace MCC {
	class Application
	{
	public:
		Application();
		void Run();
		void Close();

		Window& GetWindow() { return m_Window; };

		static Application& Get() { return *s_Instance; };

	private:
		Window m_Window;
		bool m_Running = true;
		static Application* s_Instance;
	};
}

