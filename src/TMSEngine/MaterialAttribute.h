#include "TMSEngine/TMSEngine.h"

class Texture

class MaterialAttribute
{
public:
	std::string name;
	int type;
	float value;
	std::weak_ptr<Texture> textureValue;
};