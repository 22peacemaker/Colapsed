#include "Input.h"
#include <tuple>

#include "../Application.h"

namespace MCC {
	bool Input::isKeyPressed(int keyCode)
	{
		GLFWwindow* window = Application::Get().GetWindow().GetNativeWindow();
		auto state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool Input::isKeyDown(int keyCode)
	{
		GLFWwindow* window = Application::Get().GetWindow().GetNativeWindow();
		auto state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS;
	}

	bool Input::isKeyReleased(int keyCode)
	{
		GLFWwindow* window = Application::Get().GetWindow().GetNativeWindow();
		auto state = glfwGetKey(window, keyCode);
		return state == GLFW_RELEASE;
	}

	std::tuple<float, float> Input::getMousePosition()
	{
		GLFWwindow* window = Application::Get().GetWindow().GetNativeWindow();
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { xpos, ypos };
	}

	float Input::getMouseX()
	{
		auto [xpos, ypos] = getMousePosition();
		return xpos;
	}

	float Input::getMouseY()
	{
		auto [xpos, ypos] = getMousePosition();
		return ypos;
	}

}
