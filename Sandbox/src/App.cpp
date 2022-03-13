#include <Nizhoni.h>

class App : public Nizhoni::Application {
public:
	App() {
		NI_SET_CORE_LOGLEVEL(NI_LOG_LEVEL_WARN);
	}

	~App() {

	}
};

Nizhoni::Application* Nizhoni::CreateApplication() {
	return new App();
}