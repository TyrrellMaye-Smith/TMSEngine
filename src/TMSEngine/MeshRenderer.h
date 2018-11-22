#ifndef TMSENGINE_MESHRENDERER_H_
#define TMSENGINE_MESHRENDERER_H_

#include "Component.h"

#include <memory>
#include <glm/ext.hpp>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Resources/Texture.h"
#include "Core.h"
#include "Camera.h"
#include "Transform.h"
#include "Keyboard.h"

namespace tmsengine
{

	class Mesh;
	class Material;
	class VertexArray;
	class ShaderProgram;
	class Texture;

	class MeshRenderer : public Component
	{
	public:
		void onInit();
		void setMesh(std::weak_ptr<Mesh> mesh);

		std::shared_ptr<Mesh> getMesh();
		std::shared_ptr<Material> getMaterial();
	private:
		void onDisplay();
		float angle;

		std::weak_ptr<Mesh> mesh;
		std::shared_ptr<Material> material;
		std::shared_ptr<VertexArray> shape;
		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<VertexArray> hallShape;
		std::shared_ptr<Texture> hallTexture;
		std::shared_ptr<VertexArray> object;
		std::shared_ptr<Texture> texture;

		Keyboard input;

		glm::mat4 model;
	};
}
#endif