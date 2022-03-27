#pragma once

#include "Nizhoni/Core.h"

#include <soloud.h>
#include <soloud_file.h>

#include <unordered_map>

namespace Nizhoni {
	struct AudioProps
	{
		AudioProps()
		{
		}
	};

	class NIZHONI_API Audio
	{
	protected:
		bool b_Pause = false;
		std::unordered_map<std::string, std::string> m_SoundLibrary;

	public:
		virtual ~Audio() = default;

		virtual void LoadAsset(const char* identifier, const char* Filename) = 0;
		virtual void PlayAsset(const char* identifier) = 0;
		virtual void SetLoopingBackgroundAsset(const char* identifier) = 0;
		virtual void SayText(const char* Text) = 0;

		inline void Pause() { b_Pause = true; }
		inline void UnPause() { b_Pause = false; }

		static Audio* Create(const AudioProps& props = AudioProps());
	};
}
