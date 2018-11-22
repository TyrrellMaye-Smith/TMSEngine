#include "Transform.h"

namespace tmsengine
{
	void Transform::onInit()
	{
		setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
		setRotation(glm::vec3(1, 1, 1));
		setScale(glm::vec3(1, 1, 1));
	}

	void Transform::translate(glm::vec3 _amount)
	{
		position += _amount;
	}

	void Transform::rotate(glm::vec3 _amount)
	{
		rotation += _amount;
	}

	void Transform::Scale(glm::vec3 _amount)
	{
		scale += _amount;
	}

	void Transform::setPosition(glm::vec3 _position)
	{
		position = _position;
	}

	void Transform::setRotation(glm::vec3 _rotation)
	{
		rotation = _rotation;
	}

	void Transform::setScale(glm::vec3 _scale)
	{
		scale = _scale;
	}

	glm::vec3 Transform::getPosition()
	{
		return position;
	}

	glm::vec3 Transform::getRotation()
	{
		return rotation;
	}

	glm::vec3 Transform::getScale()
	{
		return scale;
	}
}