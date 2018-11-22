#include "Core.h"
#include "GameObject.h"

#include <GL/glew.h>
#include <glm/ext.hpp>
#include <iostream>

namespace tmsengine
{

std::shared_ptr<Core> Core::initialise()
{

	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;

	rtn->input.init();
	rtn->window.ScreenInit();
	rtn->enviroment.init();

	rtn->device = alcOpenDevice(NULL);

	if (!rtn->device)
	{
		throw std::exception();
	}

	rtn->context = alcCreateContext(rtn->device, NULL);

	//Creates OpenAL rendering context
	if (!rtn->context)
	{
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->context))
	{
		alcDestroyContext(rtn->context);
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	return rtn;
}

void Core::Start()
{
	running = true;

	while (running)
	{
		input.update();

		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				Stop();
			}
		}

		float deltaTime = enviroment.getDeltaTime();

		window.ClearBuff();

		for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
		{
			(*it)->update(deltaTime);
		}

		for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
		{
			(*it)->display();
		}

		window.SwapScreen();

		if (input.getKey(SDL_SCANCODE_ESCAPE))
		{
			Stop();
			std::cout << "close" << std::endl;
		}
	}
}

void Core::Stop()
{
	running = false;

	//Cleans up context and device
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

std::shared_ptr<GameObject> Core::addGameObject()
{
	std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();
	gameObjects.push_back(rtn);

	rtn->self = rtn;
	rtn->core = self;

	return rtn;
}
}