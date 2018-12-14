#ifndef BLACKSHADES_SOUNDFX_H
#define BLACKSHADES_SOUNDFX_H

#include <vector>
#include <algorithm>

#ifdef OS9 
#include "alut.h"
#else
	#ifdef WIN32
	#include <al.h>
	#include <alut.h>
	#else
	#include <AL/al.h>
	#include <AL/alut.h>
	#endif
#endif


#define DEDICATED_SOURCES 3

class SoundFX
{
private:
	typedef std::vector<ALuint> source_list;
	source_list m_sources;

	ALuint m_music_source;
	ALuint m_enviro_source;
	ALuint m_vision_source;

	static SoundFX *m_singleton;

protected:
	SoundFX()
	{
		ALuint sources[32];
		unsigned long total_sources = 32;
		
		ALint error = AL_NO_ERROR + 1;

		while ((error != AL_NO_ERROR) && total_sources > DEDICATED_SOURCES)
		{
			// crappy test implementation coming on
			alGenSources(total_sources, sources);

			if ((error = alGetError()) == AL_NO_ERROR)
			{
				// push the sources array into the sources vector
				std::insert_iterator<source_list> ii(m_sources, m_sources.begin());

				m_music_source = sources[0];
				m_enviro_source = sources[1];
				m_vision_source = sources[2];

				// jump one ahead to skip the music source
				std::copy(sources + DEDICATED_SOURCES, sources + total_sources, ii);
			}
			else
			{
				total_sources -= 2;
			}
		}

	}

	~SoundFX()
	{
		for (source_list::iterator i = m_sources.begin(); i != m_sources.end(); ++i)
		{
			alDeleteSources(1, &(*i));
		}

		alDeleteSources(1, &m_music_source);
		alDeleteSources(1, &m_enviro_source);
		alDeleteSources(1, &m_vision_source);
	}

public:

	static SoundFX *inst()
	{
		if (m_singleton != NULL)
		{
			return m_singleton;
		}
		else
		{
			m_singleton = new SoundFX;
			return m_singleton;
		}
	}

	static void clean()
	{
		delete m_singleton;
		m_singleton = NULL;
	}

// NOTE! that psychic sound will probably need a dedicated channel ... pllgphfhfh1!!!!

	// reserved channel for music
	ALuint getMusicSource(ALuint buffer = 0xFFFFFFFF)
	{

		// possibly bad
		float gLoc[] = {0.0f, 0.0f, 0.0f};

		alSourcefv(m_music_source, AL_POSITION, gLoc);
		alSourcei(m_music_source, AL_LOOPING, 1);
		alSourcef(m_music_source, AL_MIN_GAIN, 0);

		if (buffer != 0xFFFFFFFF)
		{
			alSourceStop(m_music_source);

			alSourcei(m_music_source, AL_BUFFER, buffer);
		}

		return m_music_source;
	}

	ALuint getVisionSource(ALuint buffer = 0xFFFFFFFF)
	{

		// possibly bad
		float gLoc[] = {0.0f, 0.0f, 0.0f};

		alSourcefv(m_vision_source, AL_POSITION, gLoc);
		alSourcei(m_vision_source, AL_LOOPING, 1);
		alSourcef(m_vision_source, AL_MIN_GAIN, 1);

		if (buffer != 0xFFFFFFFF)
		{
			alSourceStop(m_vision_source);

			alSourcei(m_vision_source, AL_BUFFER, buffer);
		}

		return m_vision_source;
	}


	// reserved channel for rain, etc
	ALuint getEnviroSource(ALuint buffer = 0xFFFFFFFF)
	{
		// possibly bad
		float gLoc[] = {0.0f, 0.0f, 0.0f};

		alSourcefv(m_enviro_source, AL_POSITION, gLoc);
		alSourcei(m_enviro_source, AL_LOOPING, 1);
		alSourcef(m_enviro_source, AL_MIN_GAIN, 0);

		if (buffer != 0xFFFFFFFF)
		{
			alSourceStop(m_enviro_source);

			alSourcei(m_enviro_source, AL_PITCH, 1);
			alSourcei(m_enviro_source, AL_BUFFER, buffer);
		}

		return m_enviro_source;
	}

	ALuint getFreeSource(ALuint buffer, ALfloat min_gain = 0.0f, ALfloat max_gain = 1.0f)
	{
		source_list::iterator i = m_sources.begin();
		// skip dedicated sources
		std::advance(i, (rand()%(m_sources.size() - DEDICATED_SOURCES)) + DEDICATED_SOURCES);

		// random pick, not optimal, but probably suitable.
		ALuint pick = *i;

		i = m_sources.begin();
		// skip dedicated sources
		std::advance(i, DEDICATED_SOURCES);

		for (; i != m_sources.end(); ++i)
		{
			if (!isPlaying(*i))
			{
				pick = *i;
				break;
			}
		}

		alSourceStop(pick);

		// possibly bad
		float gLoc[] = {0.0f, 0.0f, 0.0f};

		alSourcefv(pick, AL_POSITION, gLoc);
		alSourcei(pick, AL_LOOPING, 0);
		alSourcef(pick, AL_MIN_GAIN, min_gain);
		alSourcef(pick, AL_MAX_GAIN, max_gain);

		alSourcei(pick, AL_BUFFER, buffer);

		return pick;
	}

	void playFX(ALuint buffer, float *gloc = NULL, ALfloat min_gain = 0.0f, ALfloat max_gain = 1.0f, bool only_one = false)
	{
		if (only_one)
			stopBuffer(buffer);

		ALuint snd = getFreeSource(buffer, min_gain, max_gain);
		if (gloc != NULL)
			alSourcefv(snd, AL_POSITION, gloc);		
		alSourcePlay(snd);
	}

private:

	void stopBuffer(ALuint buffer)
	{
		ALint state;		

		for (source_list::iterator i = m_sources.begin(); i != m_sources.end(); ++i)
		{
			alGetSourcei(*i, AL_BUFFER, &state);
			if (buffer == state)
			{
				alSourceStop(*i);
			}
		}		
	}

	bool isPlaying(ALuint source)
	{
		ALint state;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		return (AL_PLAYING == state)?true:false;
	}
};



#endif
