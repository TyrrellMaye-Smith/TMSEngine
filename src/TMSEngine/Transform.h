#ifndef TMSENGINE_TRANSFORM_H_
#define TMSENGINE_TRANSFORM_H_

#include <glm/glm.hpp>

#include "Component.h"

namespace tmsengine
{
	class Transform : public Component
	{
	public:

		void onInit();

		void translate(glm::vec3 amount);
		void rotate(glm::vec3 amount);
		void Scale(glm::vec3 amount);

		void setPosition(glm::vec3 position);
		void setRotation(glm::vec3 rotation);
		void setScale(glm::vec3 _scale);
		
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}
#endif