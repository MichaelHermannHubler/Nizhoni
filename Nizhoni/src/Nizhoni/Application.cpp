#include "nipch.h"
#include "Application.h"

#include "Nizhoni/Events/ApplicationEvent.h"
#include "Nizhoni/Log.h"

#include <GLFW/glfw3.h>

namespace Nizhoni {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(0.2, 0.2, 0.8, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}