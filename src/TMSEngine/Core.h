#ifndef TMSENGINE_CORE_H_
#define TMSENGINE_CORE_H_

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

#include "GameObject.h"
#include "Keyboard.h"
#include "Enviroment.h"
#include "Screen.h"

namespace tmsengine
{

	//class GameObject;

	class Core
	{

	public:
		static std::shared_ptr<Core> initialise();
		std::shared_ptr<GameObject> addGameObject();

		void Start();
		void Stop();

		template <typename T>
		std::shared_ptr<T> getComp();

	private:
		bool running;

		std::vector<std::shared_ptr<GameObject>> gameObjects;
		std::weak_ptr<Core> self;

		//SDL_Window *window;
		ALCdevice* device;
		ALCcontext* context;

		Keyboard input;
		Enviroment enviroment;
		Screen window;
	};

	template<typename T>
	inline std::shared_ptr<T> Core::getComp()
	{
		for (std::shared_ptr<GameObject> gameObj : gameObjects)
		{
			if (gameObj->GetComponent<T>())
			{
				return gameObj->GetComponent<T>();
			}
		}
	}
}
#endif