#pragma once

#include "Core.h"

namespace Nizhoni {
	class NIZHONI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in Client
	Application* CreateApplication();
}