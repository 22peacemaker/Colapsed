#include "Window.h"
#include <iostream>

namespace MCC {
	void WindowError(std::string msg) {
		std::cout << "ERROR: " << std::endl;
		exit(65);
	}

	Window::Window(std::string title, int width, int height)
	{
		this->windowTitle = title;
		this->width = width;
		this->height = height;
	}

	void Window::initWindow()
	{
		initGLFW();
		initGlad();
	}
	void Window::toggleFullscreen()
	{
		if (!m_IsFullscreen)
		{
			GLFWmonitor* mon = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(mon);
			glfwDestroyWindow(m_window);
			m_window = glfwCreateWindow(mode->width, mode->height, windowTitle.c_str(), mon, nullptr);
			m_IsFullscreen = true;
		}
		else {
			glfwDestroyWindow(m_window);
			m_window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
			m_IsFullscreen = false;
		}
		glfwMakeContextCurrent(m_window);
		if (m_window == nullptr) {
			std::cout << "Error creating fullsize window" << std::endl;
		}
	}
	void Window::close()
	{
		glfwDestroyWindow(m_window);
	}
	void Window::initGLFW()
	{
		if (!glfwInit()) {
			std::cout << "GLFW not Initialized!" << std::endl;
			exit(65);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);

		if (m_window == nullptr) {
			glfwTerminate();
			WindowError("Faild to create GLFW window");
		}

		glfwMakeContextCurrent(m_window);
	}

	void Window::initGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			WindowError("Faild to initialized Glad");
		}
	}
}
