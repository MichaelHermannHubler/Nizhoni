#include <Nizhoni.h>

class ExampleLayer : public Nizhoni::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override {
		NI_TRACE("Example Layer Update");
	}

	void OnEvent(Nizhoni::Event& event) override {
		NI_INFO("{0}", event);
	}
};

class App : public Nizhoni::Application {
public:
	App() {
		NI_SET_CORE_LOGLEVEL(NI_LOG_LEVEL_WARN);
		NI_SET_LOGLEVEL(NI_LOG_LEVEL_WARN);

		PushLayer(new ExampleLayer);
		PushOverlay(new Nizhoni::ImGuiLayer());

		//SayText("Beep Boop Beep Boopity Boop");

		LoadAudioAsset("aud_beep", "Data\\Retro Alarm 02.wav");
		LoadAudioAsset("aud_background", "Data\\Retro Ambience 11.wav");
		//PlayAudioAsset("aud_beep");
		SetLoopingBackgroundAsset("aud_background");
		//PauseAudio();
		//UnpauseAudio();
		//PlayAudioAsset("aud_beep");
		
	}

	~App() {

	}
};

Nizhoni::Application* Nizhoni::CreateApplication() {
	return new App();
}