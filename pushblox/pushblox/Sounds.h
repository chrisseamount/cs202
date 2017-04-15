#pragma once
#include<SFML/Audio.hpp>
#include<iostream>
#include <fstream> 

namespace Sounds
{

	class SoundClass {
		public:
			void menuMusic();

		private:
			sf::SoundBuffer _soundBuffer;
			sf::Sound _sound;
	};

}