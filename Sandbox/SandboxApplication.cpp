#include "..\MCC\src\MCC\Application.h"
#include <MCC.h>

class Sandbox : public CP::Application {
public:
		Sandbox() {

		}

		~Sandbox() {

		}
};

void CP::CpInit()
{
	Log::Init();
}

CP::Application* CP::CreateApplication() {
	return new Sandbox();
}
