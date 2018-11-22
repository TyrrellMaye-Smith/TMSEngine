#include "GameObject.h"

namespace tmsengine
{

void GameObject::update(float _deltaTime)
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onUpdate();
	}
}

void GameObject::display()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();
	}
}

std::shared_ptr<Core> GameObject::getCore()
{
	return core.lock();
}
}