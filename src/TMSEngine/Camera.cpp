#include "Camera.h"

using namespace tmsengine;

Camera::Camera()
{
}

void Camera::onInit()
{
	
	projMatrix = glm::mat4(1.0f);
	projMatrix = glm::perspective(glm::radians(45.0f), 500.0f / 500.0f, 0.1f, 100.0f);
	

	//Sets up camera
	glm::mat4 model(1.0f);
	viewMatrix = glm::inverse(model);
}

glm::mat4 Camera::getProj()
{
	return projMatrix;
}

glm::mat4 Camera::getView()
{
	return viewMatrix;
}