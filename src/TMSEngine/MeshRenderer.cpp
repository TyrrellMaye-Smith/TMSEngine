#include "MeshRenderer.h"

#include <iostream>
#include <glm/ext.hpp>

namespace tmsengine
{
	void MeshRenderer::onInit()
	{
		/*std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
		positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
		positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

		std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
		{
			colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		}*/

		/*shape = std::make_shared<VertexArray>();
		shape->setBuffer("in_Position", positions);
		shape->setBuffer("in_Color", colors);*/

		srand(time(NULL));

		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert","../resources/shaders/simple.frag");

		//Calls object
		object = std::make_shared<VertexArray>("../resources/models/Cube.obj");
		texture = std::make_shared<Texture>("../resources/models/textures/default.png");
		angle = 0;

		shader->setUniform("in_Projection", getCore()->getComp<Camera>()->getProj());
		shader->setUniform("in_View", getCore()->getComp<Camera>()->getView());

		input.init();
	}

	void MeshRenderer::onDisplay()
	{
		input.update();

		////Triangle
		//shader->setUniform("in_Model", glm::mat4(1.0f));
		//shader->setUniform("in_Projection", glm::mat4(1.0f));
		//shader->draw(shape);*/

		//Draw cube
		model = glm::mat4(1.0f);

		//Position
		getCore()->getComp<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
		model = glm::translate(model, getCore()->getComp<Transform>()->getPosition());

		//Rotation
		getCore()->getComp<Transform>()->setRotation(glm::vec3(1, 1, 1));
		model = glm::rotate(model, glm::radians(angle) , getCore()->getComp<Transform>()->getRotation());

		//Scale
		getCore()->getComp<Transform>()->setScale(glm::vec3(1, 1, 1));
		model = glm::scale(model, getCore()->getComp<Transform>()->getScale());

		//Movement FINISH THE REST OF THE KEYBOARD INPUTS
		if (input.getKey(SDL_SCANCODE_LEFT))
		{
			std::cout << "left key pressed" << std::endl;
			
			model = glm::translate(model, glm::vec3(-5, 0, 0));
		}

		shader->setUniform("in_Model", model);
		shader->setUniform("in_Texture", texture);
		shader->draw(object);

		angle += 1.0f * (rand() % 5);
	}
}