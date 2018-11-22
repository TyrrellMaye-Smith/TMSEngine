#include <TMSEngine/TMSEngine.h>
#include <iostream>
#include <GL/glew.h>

using namespace tmsengine;

class Player : public Component
{
public:
private:
};

int main()
{
	//Calls engine
	//std::shared_ptr<Core> core = std::make_shared<Core>();
	std::shared_ptr<tmsengine::Core> core = tmsengine::Core::initialise();

	//calls game object
	std::shared_ptr<tmsengine::GameObject> player = core->addGameObject();
	player->AddComponent<Player>();

	//Mesh renderer
	std::shared_ptr<tmsengine::Camera> camera = player->AddComponent<tmsengine::Camera>();
	std::shared_ptr<tmsengine::MeshRenderer> mr = player->AddComponent<tmsengine::MeshRenderer>();
	std::shared_ptr<tmsengine::Transform> transform = player->AddComponent<tmsengine::Transform>();

	//Calls sound
	std::shared_ptr<tmsengine::Sound> s = std::make_shared<tmsengine::Sound>
		("../resources/sounds/wilhelm scream.ogg");
	s->play();

	core->Start();

	return 0;
}