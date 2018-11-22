#ifndef TMSENGINE_SCREEN_H_
#define TMSENGINE_SCREEN_H_

#include <SDL2/SDL.h>

namespace tmsengine
{
	class Screen
	{
	public:

		static int getWidth();
		static int getHeight();
		void ScreenInit();
		void ClearBuff();
		void SwapScreen();

		SDL_Window* GetScreen();

	private:

		static int winPosX;
		static int winPosY;
		static int winWidth;
		static int winHeight;
		SDL_Window* window;
	};
}

#endif