#include "Keyboard.h"

#include <iostream>

namespace tmsengine
{
	void Keyboard::init()
	{
		SDL_GetKeyboardState(&keyCodes);
		currKey = new Uint8[keyCodes];
		prevKey = new Uint8[keyCodes];

		std::memcpy(prevKey, currKey, keyCodes);
	}

	void Keyboard::update()
	{
		std::memcpy(prevKey, currKey, keyCodes);
		std::memcpy(currKey, SDL_GetKeyboardState(NULL), keyCodes);
		SDL_PumpEvents();
	}

	bool Keyboard::getKey(SDL_Scancode _keyCode)
	{
		return currKey[_keyCode] && !prevKey[_keyCode];
	}

	bool Keyboard::getKeyDown(SDL_Scancode _keyCode)
	{
		
		return currKey[_keyCode];
	}

	bool Keyboard::getKeyUp(SDL_Scancode _keyCode)
	{
		return !currKey[_keyCode] && prevKey[_keyCode];
	}
}