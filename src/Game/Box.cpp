#include "Box.h"
#include <iostream>

void Box::onInit()
{
		std::cout << "hello" << std::endl;
}

void Box::onUpdate()
{
		//Position
		getCore()->getComp<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, -5.0f));

		//Rotation
		getCore()->getComp<Transform>()->setRotation(glm::vec3(1, 1, 1));
}