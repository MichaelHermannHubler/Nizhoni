#include <Nizhoni.h>

class App : public Nizhoni::Application {
public:
	App() {
		NI_SET_CORE_LOGLEVEL(NI_LOG_LEVEL_TRACE);

		NI_CORE_CRITICAL("Critical");
		NI_CORE_ERROR("Error");
		NI_CORE_WARN("Warn");
		NI_CORE_INFO("Info");
		NI_CORE_TRACE("Trace");
	}

	~App() {

	}
};

Nizhoni::Application* Nizhoni::CreateApplication() {
	return new App();
}