#include "Application.h"

#include "Event/Input.h"

#include <iostream>

namespace MCC {

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		m_Window = Window("test", 1280, 720);
		s_Instance = this;

		Run();
	}
	void Application::Run()
	{
		int counter = 0;
		m_Window.initWindow();
		glViewport(0, 0, 1280, 720);
		while (!glfwWindowShouldClose(m_Window.GetNativeWindow())) {
			glClearColor(250.0f / 250.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(m_Window.GetNativeWindow());
			glfwPollEvents();
		}
	}

	void Application::Close()
	{
		m_Window.close();
		m_Running = false;
	}
}
