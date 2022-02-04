#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace MCC {
	class Window
	{
	public:
		Window(std::string title = "MCC", int width = 1280, int height = 720);
		void initWindow();
		void toggleFullscreen();
		void close();

		inline GLFWwindow* GetNativeWindow() const { return m_window; };

	private:
		GLFWwindow* m_window;
		std::string windowTitle;
		int width;
		int height;

		bool m_IsFullscreen = false;

		void initGLFW();
		void initGlad();
	};

}
