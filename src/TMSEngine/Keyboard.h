#ifndef TMSENGINE_KEYBOARD_H_
#define TMSENGINE_KEYBOARD_H_

#include <memory>

#include "SDL2/SDL.h"

namespace tmsengine
{

	class Keyboard
	{
	public:
		void init();
		void update();
		bool getKey(SDL_Scancode keyCode);
		bool getKeyDown(SDL_Scancode keyCode);
		bool getKeyUp(SDL_Scancode keyCode);
	private:
		int keyCodes;
		Uint8* currKey;
		Uint8* prevKey;
	};
}
#endif