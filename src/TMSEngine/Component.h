#pragma once
#ifndef TMSENGINE_COMPONENT_H_
#define TMSENGINE_COMPONENT_H_

#include <memory>

namespace tmsengine
{

	class GameObject;
	class Core;

	class Component
	{
		friend class GameObject;

	public:
		virtual ~Component();

		std::shared_ptr<Core> getCore();
		std::shared_ptr<GameObject> getGameObject();
	private:
		bool began;
		virtual void onUpdate();
		virtual void onDisplay();
		virtual void onInit();

		std::weak_ptr<GameObject> gameObject;
	};

}
#endif