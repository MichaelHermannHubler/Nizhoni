#pragma once

#include "Nizhoni/Core.h"

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
		std::unordered_map<std::string, int> SoundLibrary;

	public:
		virtual ~Audio() = default;

		virtual void LoadAsset(const char* identifier, const std::string& Filename) = 0;
		virtual void PlayAsset(const char* identifier) = 0;
		virtual void SayText(const char* Text) = 0;

		static Audio* Create(const AudioProps& props = AudioProps());
	};
}
