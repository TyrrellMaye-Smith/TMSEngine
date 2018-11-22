#ifndef TMSENGINE_SOUND_H_
#define TMSENGINE_SOUND_H_

#include <memory>
#include <string>

namespace tmsengine
{
	struct SoundImpl;

	class Sound
	{
	private:
		std::shared_ptr<SoundImpl> impl;

	public:
		Sound();
		Sound(std::string path);

		void load(std::string path);
		void play(float vol, float min, float max);
		void play();
	};
}
#endif