#ifndef TMSENGINE_CAMERA_H_
#define TMSENGINE_CAMERA_H_

#include <glm/ext.hpp>
#include <memory>

#include "Component.h"

namespace tmsengine
{

class Camera : public Component
{
public:
	Camera();

	void onInit();

	glm::mat4 getProj();
	glm::mat4 getView();

private:
	glm::mat4 projMatrix;
	glm::mat4 viewMatrix;
};
}
#endif