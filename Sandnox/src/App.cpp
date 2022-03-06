#include <Nizhoni.h>

class App : public Nizhoni::Application {
public:
	App() {

	}

	~App() {

	}
};

Nizhoni::Application* Nizhoni::CreateApplication() {
	return new App();
}