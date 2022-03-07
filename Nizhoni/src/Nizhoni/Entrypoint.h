#pragma once

#ifdef NI_PLATFORM_WINDOWS

extern Nizhoni::Application* Nizhoni::CreateApplication();

int main(int argc, char** argv) {
	Nizhoni::Log::Init();

	NI_CORE_INFO("Logger initialized");
	NI_TRACE("Logger initialized");

	auto app = Nizhoni::CreateApplication();
	app->Run();
	delete app;
}

#endif