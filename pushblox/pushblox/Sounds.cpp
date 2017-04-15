#include "Sounds.h"

namespace Sounds
{
	void SoundClass::menuMusic()
	{
		if (!_soundBuffer.loadFromFile("HaloTheme_IntroSong.ogg"))
		{
			std::cout << "DID NOT FIND THE FILE" << std::endl;
		}

		_sound.setBuffer(_soundBuffer);
		_sound.play();
	}
}