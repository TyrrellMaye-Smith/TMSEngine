#ifndef TMSENGINE_GAMEOBJECT_H_
#define TMSENGINE_GAMEOBJECT_H_

#include "Component.h"

#include <memory>
#include <vector>

namespace tmsengine
{

class Component;

class GameObject
{

	friend class Core;

public:
	void update(float _deltaTime);
	void display();

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->gameObject = self;
		rtn->began = false;
		components.push_back(rtn);

		rtn->onInit();

		return rtn;
	}

	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::shared_ptr<T> currCom = std::dynamic_pointer_cast<T>(components.at(i));

			if (currCom)
			{
				return currCom;
			}
		}

		return false;
		throw std::exception();
	}

	std::shared_ptr<Core> getCore();
private:
	std::vector<std::shared_ptr<Component>> components;

	std::weak_ptr<Core> core;
	std::weak_ptr<GameObject> self;
};

}
#endif