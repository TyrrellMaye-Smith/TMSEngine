#include "Collider.h"
#include <iostream>

namespace tmsengine
{
		void Collider::collide()
		{
				pos = box->getCore()->getComp<Transform>()->getPosition();

				collision = false;

				for (size_t i = 0; i < apples.size(); i++)
				{
						if (isColliding(box->getCore()->getComp<Transform>()->getPosition(), 
								glm::vec3(apples.at(i)->getCore()->getComp<Transform>()->getPosition())))
						{
								collision = true;
						}
				}
				if (!collision)
				{
						pos = box->getCore()->getComp<Transform>()->getPosition();
				}
		}

		bool Collider::isColliding(glm::vec3 _a, glm::vec3 _b)
		{
				colX = false;
				colY = false;
				colZ = false;

				if (_a.x < _b.x)
				{
						if (_a.x + 2 > _b.x - 1)
						{
								colX = true;
						}
				}
				else if (_b.x + 2 > _a.x - 1)
				{
						colX = true;
				}

				if (_a.y < _b.y)
				{
						if (_a.y + 2 > _b.y - 1)
						{
								colY = true;
						}
				}
				else if (_b.y + 2 > _a.y - 1)
				{
						colY = true;
				}

				if (_a.z < _b.z)
				{
						if (_a.z + 2 > _b.z - 1)
						{
								colZ = true;
						}
				}
				else if (_b.z + 2 > _a.z - 1)
				{
						colY = true;
				}

				if (colX && colY && colZ)
				{
						std::cout << "Collison" << std::endl;
						return true;
				}
		}
}