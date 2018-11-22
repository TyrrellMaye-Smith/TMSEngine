#ifndef TMSENGINE_ENVIROMENT_H_
#define TMSENGINE_ENVIROMENT_H_

namespace tmsengine
{
	class Enviroment
	{
	public:
		void init();
		float getDeltaTime();

	private:
		float deltaTime = 0;
		float lastTime;
		float time;
		float difference;
		float idealTime;
	};
}
#endif