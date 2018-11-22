#include "Screen.h"

#include <GL/glew.h>
#include <iostream>
#include <string>

namespace tmsengine
{
	int Screen::winPosX = 100;
	int Screen::winPosY = 100;
	int Screen::winWidth = 500;
	int Screen::winHeight = 500;

	void Screen::ScreenInit()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		window = SDL_CreateWindow("Game",
			winPosX, winPosY, winWidth, winHeight,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		//Creates OpenGL rendering context
		if (!SDL_GL_CreateContext(window))
		{
			throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
	}

	void Screen::ClearBuff()
	{
		SDL_GetWindowSize(window, &winWidth, &winHeight);
		glViewport(0, 0, winWidth, winHeight);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Screen::SwapScreen()
	{
		SDL_GL_SwapWindow(window);
	}

	int Screen::getWidth()
	{
		return winWidth;
	}

	int Screen::getHeight()
	{
		return winHeight;
	}

	SDL_Window* Screen::GetScreen()
	{
		return window;
	}
}
