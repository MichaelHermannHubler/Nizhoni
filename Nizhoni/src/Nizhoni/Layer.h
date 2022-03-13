#pragma once

#include "Nizhoni/Core.h"
#include "Nizhoni/Events/Event.h"

namespace Nizhoni{
	class NIZHONI_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}