#pragma once

#include "Nizhoni/Core.h"
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

	};

	//To be defined in Client
	Application* CreateApplication();
}