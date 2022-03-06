#include "Application.h"

#include "Nizhoni/Events/ApplicationEvent.h"
#include "Nizhoni/Log.h"

namespace Nizhoni {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		NI_TRACE(e);

		while (true);
	}
}