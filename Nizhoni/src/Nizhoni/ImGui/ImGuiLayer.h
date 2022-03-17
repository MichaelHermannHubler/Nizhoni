#pragma once

#include "Nizhoni/Layer.h"

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
	};
}