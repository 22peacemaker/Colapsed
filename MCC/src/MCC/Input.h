#pragma once

#include "Core.h"

#include <GLFW/glfw3.h>

namespace CP {
	class CP_API Input {
	public:
		static bool isKeyPressed(int keyCode);
		static bool isKeyDown(int keyCode);
		static bool isKeyReleased(int keyCode);

		static bool isKeyPressed(std::string bindName);
		static bool isKeyDown(std::string bindName);
		static bool isKeyReleased(std::string bindName);

		static std::tuple<float, float> getMousePosition();
		
		static float getMouseX();
		static float getMouseY();
	private:
	};
}
