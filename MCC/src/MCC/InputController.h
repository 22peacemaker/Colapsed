#pragma once


#include "Core.h"


namespace CP {

	struct KeyBind
	{
		std::string bindName;
		int Keycode;
		bool isActive;
	};

	class InputController
	{
	public:
		static void addKeyBind(const std::string name,const int keycode);
		static void removeKeyBind(const std::string name);
		
		static void activateKeyBind(const std::string name);
		static void deactivateKeyBind(const std::string name);
		static void toggleKeyBind(const std::string name);

		static int getByName(const std::string name);
	private:
		static std::vector<KeyBind> keybinds;
	};
}

