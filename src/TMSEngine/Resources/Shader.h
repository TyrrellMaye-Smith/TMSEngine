#include "TMSEngine/TMSEngine.h"

class Texture;

class Shader
{
public:
	~Shader();

	void setUniform(std::string name, float value);
	void setUniform(std::string name, std::weak_ptr<Texture> value);
	void setUniform(std::string name, glm::mat4 value);
	void setUniform(std::string name, glm::vec3 value);

	GLuint getID();
private:
	//GLuint int
	std::shared_ptr<Shader> create(std::string vertSrc, std::string fragSrc);
	std::shared_ptr<Shader> load(std::string path);
};