#pragma once

#include "Window.h"
#include "Nizhoni/Audio.h"
#include "Nizhoni/Core.h"
#include "Nizhoni/LayerStack.h"
#include "Nizhoni/Events/Event.h"
#include "Nizhoni/Events/ApplicationEvent.h"


namespace Nizhoni {
	class NIZHONI_API Application
	{
	private:
		static Application* s_Instance;

	public:
		inline static Application& Get() { return *s_Instance; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		std::unique_ptr<Audio> m_AudioEngine;

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void LoadAudioAsset(const char* identifier, const char* filename);
		void PlayAudioAsset(const char* identifier);
		void SayText(const char* text);

		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	};

	//To be defined in Client
	Application* CreateApplication();
}