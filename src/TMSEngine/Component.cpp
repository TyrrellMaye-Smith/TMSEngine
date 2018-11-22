#include "Component.h"
#include "GameObject.h"

namespace tmsengine
{

Component::~Component()
{

}

void Component::onUpdate()
{
	
}

void Component::onDisplay()
{
	
}

void Component::onInit()
{

}

std::shared_ptr<GameObject> Component::getGameObject()
{
	return gameObject.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getGameObject()->getCore();
}

}