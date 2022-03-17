#include "nipch.h"
#include "Application.h"

#include "Nizhoni/Events/ApplicationEvent.h"
#include "Nizhoni/Log.h"

#include <glad/glad.h>

namespace Nizhoni {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		NI_ASSERT(!s_Instance, "Application allready exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		m_AudioEngine = std::unique_ptr<Audio>(Audio::Create());
	}

	Application::~Application() {

	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::LoadAudioAsset(const char* identifier, const char* filename) {
		m_AudioEngine->LoadAsset(identifier, filename);
	}

	void Application::PlayAudioAsset(const char* identifier) {
		m_AudioEngine->PlayAsset(identifier);
	} 

	void Application::SayText(const char* text) {
		m_AudioEngine->SayText(text);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		NI_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(0.2, 0.2, 0.8, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}