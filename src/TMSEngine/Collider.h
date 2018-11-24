#ifndef TMSENGINE_COLLIDER_H_
#define TMSENGINE_COLLIDER_H_

#include <glm\glm.hpp>

#include "Component.h"
#include "Game\Box.h"
#include "Game\Apple.h"

namespace tmsengine
{

		class Collider : public Component
		{
		public:

				void collide();
				bool isColliding(glm::vec3 _a, glm::vec3 _b);

		private:

				//Collision variables
				bool colX;
				bool colY;
				bool colZ;
				bool collision;

				glm::vec3 pos;

				std::shared_ptr<Box> box;
				std::vector<Apple*> apples;
		};
}
#endif