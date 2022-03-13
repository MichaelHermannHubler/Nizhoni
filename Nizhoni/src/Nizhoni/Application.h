#pragma once

#include "Window.h"
#include "Nizhoni/Core.h"
#include "Nizhoni/LayerStack.h"
#include "Nizhoni/Events/Event.h"
#include "Nizhoni/Events/ApplicationEvent.h"


namespace Nizhoni {
	class NIZHONI_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;


	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
	};

	//To be defined in Client
	Application* CreateApplication();
}