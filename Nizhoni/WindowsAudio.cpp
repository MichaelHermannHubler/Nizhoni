#include "nipch.h"
#include "WindowsAudio.h"

#include "soloud.h"
#include "soloud_speech.h"
#include "soloud_thread.h"

namespace Nizhoni {

	Audio* Audio::Create(const AudioProps& props) {
		return new WindowsAudio(props);
	}

	WindowsAudio::WindowsAudio(const AudioProps& props) {
		int success = m_Engine.init();
		NI_CORE_ASSERT(success, "Could not initialize SoLoud Engine");
	}

	void WindowsAudio::LoadAsset(const char* identifier, const std::string& Filename)
	{
	}
	void WindowsAudio::PlayAsset(const char* identifier)
	{
	}
	void WindowsAudio::SayText(const char* Text)
	{
		SoLoud::Speech speech;
		speech.setText(Text);
		m_Engine.play(speech);

		while (m_Engine.getActiveVoiceCount() > 0)
		{
			// Still going, sleep for a bit
			SoLoud::Thread::sleep(100);
		}
	}
}