#pragma once

#include "Nizhoni/Core.h"
#include "Events/Event.h"
#include "Nizhoni/Events/ApplicationEvent.h"

#include "Window.h"

namespace Nizhoni {
	class NIZHONI_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;


	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
	};

	//To be defined in Client
	Application* CreateApplication();
}