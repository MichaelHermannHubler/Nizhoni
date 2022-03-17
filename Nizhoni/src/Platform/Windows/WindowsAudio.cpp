#include "nipch.h"
#include "WindowsAudio.h"

#include "soloud.h"
#include "soloud_speech.h"
#include "soloud_thread.h"
#include "soloud_wav.h"
#include "soloud_file.h"
#include "soloud_audiosource.h"

#include <thread>


namespace Nizhoni {

	Audio* Audio::Create(const AudioProps& props) {
		return new WindowsAudio(props);
	}

	WindowsAudio::WindowsAudio(const AudioProps& props) {
		int success = m_Engine.init();
		NI_CORE_ASSERT(success, "Could not initialize SoLoud Engine");

		m_EngineMutex = SoLoud::Thread::createMutex();
	}

	void WindowsAudio::SetPause(SoLoud::handle handle, bool pause) {
		SoLoud::Thread::lockMutex(m_EngineMutex);
		m_Engine.setPause(handle, pause);
		SoLoud::Thread::unlockMutex(m_EngineMutex);
	}

	WindowsAudio::~WindowsAudio() {
		SoLoud::Thread::lockMutex(m_EngineMutex);
		m_Engine.deinit();
		SoLoud::Thread::unlockMutex(m_EngineMutex);
		SoLoud::Thread::destroyMutex(m_EngineMutex);
	}

	/// <summary>
	/// Load A sound Asset into the Sound Asset Table
	/// Cuurently only WAV files are supported
	/// </summary>
	/// <param name="identifier"></param>
	/// <param name="filename"></param>
	void WindowsAudio::LoadAsset(const char* identifier, const char* filename) {
		m_SoundLibrary.insert_or_assign(identifier, filename);
	}

	void WindowsAudio::PlayAsset(const char* identifier) {
		std::string fileName = m_SoundLibrary.at(identifier);

		std::thread t1([this](std::string fileName) { this->PlayAssetThreaded(fileName); }, fileName);
		t1.detach();
	}

	void WindowsAudio::PlayAssetThreaded(std::string fileName) {
		SoLoud::Wav sound;

		sound.load(fileName.c_str());
		sound.setVolume(1); //TODO: CHANGEABLE TO 0.-1.

		SoLoud::Thread::lockMutex(m_EngineMutex);
		auto handle = m_Engine.play(sound);
		SoLoud::Thread::unlockMutex(m_EngineMutex);

		bool isPaused = false;

		while (m_Engine.getActiveVoiceCount() > 0 || isPaused) {
			// Handle Pausing of Sample
			if (b_Pause && !isPaused) {
				SetPause(handle, true);
				isPaused = true;
			}
			else if (isPaused && !b_Pause) {
				SetPause(handle, false);
				isPaused = false;
			}

			SoLoud::Thread::sleep(100);
		}
	}

	void WindowsAudio::SayText(const char* Text) {
		std::thread t1([this](const char* Text) { this->SayTextThreaded(Text); }, Text);
		t1.detach();
	}

	void WindowsAudio::SayTextThreaded(const char* Text) {
		SoLoud::Speech speech;

		speech.setText(Text);
		speech.setVolume(1); //TODO: CHANGEABLE TO 0.-1.

		SoLoud::Thread::lockMutex(m_EngineMutex);
		auto handle = m_Engine.play(speech);
		SoLoud::Thread::unlockMutex(m_EngineMutex);

		bool isPaused = false;

		while (m_Engine.getActiveVoiceCount() > 0) {
			// Handle Pausing of Sample
			if (b_Pause && !isPaused) {
				SetPause(handle, true);
				isPaused = true;
			}
			else if (isPaused && !b_Pause) {
				SetPause(handle, false);
				isPaused = false;
			}
			SoLoud::Thread::sleep(100);
		}
	}
}