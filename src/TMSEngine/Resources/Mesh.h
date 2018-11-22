#include "TMSEngine/TMSEngine.h"

class Resource;

struct Triangle
{
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
};

class Mesh
{
public:

	Mesh();
	~Mesh();

	// OBJ file must be triangulated
	void LoadOBJ(std::string _filename);

	// Draws the mesh - must have shaders applied for this to display!
	void Draw();

	std::vector<Triangle> m_tri;
	std::vector<Triangle> GetTri() { return m_tri; }

private:
	// OpenGL Vertex Array Object
	GLuint _VAO;

	// Number of vertices in the mesh
	unsigned int m_numVertices;

	bool dirty;
};