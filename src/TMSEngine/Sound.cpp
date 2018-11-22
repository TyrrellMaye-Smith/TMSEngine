#include "Sound.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>
#include <iostream>
#include <vector>

namespace tmsengine
{
	struct SoundImpl
	{
		ALuint soundID;

		
		~SoundImpl()
		{
			alDeleteBuffers(1, &soundID);
		}

		void load_ogg(std::string filename, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
		{
			int endian = 0;
			int bitStream = 0;
			long bytes = 0;
			char array[2048] = { 0 };
			vorbis_info *pInfo = NULL;
			OggVorbis_File oggFile = { 0 };

			//Using fopen to create a file descriptor
			if (ov_fopen(filename.c_str(), &oggFile) != 0)
			{
				std::cout << "Failed to open file '" << filename << "' for decoding" << std::endl;
				throw std::exception();
			}

			//Use file header information
			pInfo = ov_info(&oggFile, -1);

			//Record the format required by OpenAL
			if (pInfo->channels == 1)
			{
				format = AL_FORMAT_MONO16;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}

			//Record the smaple rate required by OpenAL
			freq = pInfo->rate;

			//Keep reading bytes from the file to fill the output buffer
			while (true)
			{
				//Reads the bytes into a temporary array
				bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << "Failed to decode file '" << filename << "'." << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}

				//Copy from array to output buffer
				buffer.insert(buffer.end(), array, array + bytes);
			}

			//Clean and close file
			ov_clear(&oggFile);
		}
	};

	Sound::Sound() {}

	Sound::Sound(std::string path)
	{
		load(path);
	}

	void Sound::load(std::string path)
	{
		impl = std::make_shared<SoundImpl>();

		ALenum format = 0;
		ALsizei freq = 0;

		std::vector<char> bufferData;

		alGenBuffers(1, &impl->soundID);
		impl->load_ogg(path.c_str(), bufferData, format, freq);
		alBufferData(impl->soundID, format, &bufferData[0], 
			static_cast<ALsizei>(bufferData.size()), freq);
	}

	void Sound::play()
	{
		ALuint sID = 0;
		alGenSources(1, &sID);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sID, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sID, AL_BUFFER, impl->soundID);
		alSourcePlay(sID);
	}

	void Sound::play(float vol, float min, float max)
	{
		min *= 1000.0f;
		max *= 1000.0f;

		float variance = (std::rand() % ((int)min + 1 - (int)max) + (int)min) / 1000.0f;

		ALuint sID = 0;
		alGenSources(1, &sID);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sID, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sID, AL_BUFFER, impl->soundID);
		alSourcef(sID, AL_PITCH, variance);
		alSourcef(sID, AL_GAIN, vol);
		alSourcePlay(sID);
	}
}