#pragma once
#include "Nizhoni/Audio.h"

#include "soloud.h"
#include "soloud_speech.h"

namespace Nizhoni {
	class WindowsAudio : public Audio
	{
	private:
		SoLoud::Soloud m_Engine;
		void* m_EngineMutex;
	public:
		WindowsAudio(const AudioProps& props);
		~WindowsAudio();

		virtual void LoadAsset(const char* identifier, const char* Filename) override;
		virtual void PlayAsset(const char* identifier) override;
		virtual void SayText(const char* Text) override;

	private:
		void PlayAssetThreaded(std::string fileName);
		void SayTextThreaded(const char* Text);
		void WindowsAudio::SetPause(SoLoud::handle handle, bool pause);
	};
}
