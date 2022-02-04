#pragma once

#include <GLFW/glfw3.h>
#include <vector>

namespace MCC {
	class Input {
	public:
		static bool isKeyPressed(int keyCode);
		static bool isKeyDown(int keyCode);
		static bool isKeyReleased(int keyCode);

		static std::tuple<float, float> getMousePosition();
		
		static float getMouseX();
		static float getMouseY();
	private:
	};
}
