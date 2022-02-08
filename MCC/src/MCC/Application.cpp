#include "MCCpch.h"
#include "Application.h"

#include "Input.h"
#include "InputController.h"

#include "Log.h"

namespace CP {

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		m_Window = Window("test", 1280, 720);
		s_Instance = this;
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		int counter = 0;
		m_Window.initWindow();
		MCC_CORE_INFO("ENTER MAIN LOOP");
		glViewport(0, 0, 1280, 720);
		while (!glfwWindowShouldClose(m_Window.GetNativeWindow())) {
			glClearColor(250.0f / 250.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(m_Window.GetNativeWindow());
			glfwPollEvents();
		}
		Close();
	}

	void Application::Close()
	{
		m_Window.close();
		m_Running = false;
	}
}
