#pragma once

#ifdef NI_PLATFORM_WINDOWS

extern Nizhoni::Application* Nizhoni::CreateApplication();

int main(int argc, char** argv) {
	printf("Nizhoni Engine");
	auto app = Nizhoni::CreateApplication();
	app->Run();
	delete app;
}

#endif