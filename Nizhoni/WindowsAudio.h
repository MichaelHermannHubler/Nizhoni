#pragma once
#include "Nizhoni/Audio.h"

#include "soloud.h"
#include "soloud_speech.h"

namespace Nizhoni {
	class WindowsAudio : public Audio
	{
	private:
		SoLoud::Soloud m_Engine;
	public:
		WindowsAudio(const AudioProps& props);

		virtual void LoadAsset(const char* identifier, const std::string & Filename) override;
		virtual void PlayAsset(const char* identifier) override;
		virtual void SayText(const char* Text) override;
	};
}
