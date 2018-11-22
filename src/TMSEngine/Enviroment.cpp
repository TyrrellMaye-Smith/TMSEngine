#include "Enviroment.h"

#include <iostream>
#include <SDL2/SDL.h>

namespace tmsengine
{
	void Enviroment::init()
	{
		lastTime = SDL_GetTicks();
	}

	float Enviroment::getDeltaTime()
	{
		time = SDL_GetTicks();
		difference = time - lastTime;
		deltaTime = difference / 1000.0f;
		lastTime = time;

		idealTime = 1.0f / 60.0f;
		
		if (idealTime > deltaTime)
		{
			SDL_Delay((idealTime - deltaTime) * 1000.0f);
		}

		return deltaTime;
	}
}