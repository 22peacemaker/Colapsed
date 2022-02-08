#include "MCCpch.h"
#include "InputController.h"
namespace CP {
	std::vector<KeyBind> InputController::keybinds;

	void InputController::addKeyBind(const std::string name, const int keycode)
	{
		keybinds.push_back({ name, keycode, true });
	}
	void InputController::removeKeyBind(const std::string name)
	{
		int counter = 0;
		for (KeyBind& bind : keybinds) {
			if (bind.bindName == name)
				break;
			counter++;
		}
		keybinds.erase(keybinds.begin() + counter);
	}
	void InputController::activateKeyBind(const std::string name)
	{
		for (KeyBind& binding : keybinds) {
			if (binding.bindName == name) {
				binding.isActive = true;
				break;
			}
		}
	}
	void InputController::deactivateKeyBind(const std::string name)
	{
		for (KeyBind& binding : keybinds) {
			if (binding.bindName == name) {
				binding.isActive = false;
			}
		}
	}
	void InputController::toggleKeyBind(const std::string name)
	{
		for (KeyBind& binding : keybinds) {
			if (binding.bindName == name) {
				binding.isActive = !binding.isActive;
			}
		}
	}
	int InputController::getByName(const std::string name)
	{
		for (KeyBind& binding : keybinds) {
			if (binding.bindName == name)
				return binding.Keycode;
		}

		return -1;
	}
}
