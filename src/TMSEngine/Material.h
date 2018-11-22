#include "TMSEngine/TMSEngine.h"

class Shader;
class MaterialAttributes;
class Texture;

class Material
{
public:
	void setShader(std::weak_ptr<Shader>shader);
	void setValue(std::string name, std::weak_ptr<Texture> value);
	void setValue(std::string name, float value);
	
	std::shared_ptr<Shader> getShader();
private:
	std::weak_ptr<Shader> shader;
	std::vector<MaterialAttributes> attributes;
};