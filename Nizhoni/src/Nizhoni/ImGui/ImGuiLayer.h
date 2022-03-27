#pragma once

#include "Nizhoni/Core.h"
#include "Nizhoni/Layer.h"
#include <Nizhoni/Events/MouseEvent.h>
#include <Nizhoni/Events/KeyEvent.h>
#include <Nizhoni/Events/ApplicationEvent.h>

namespace Nizhoni {
	class NIZHONI_API ImGuiLayer : public Layer {
	private:
		float m_time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizedEvent(WindowResizeEvent& e);
	};
}