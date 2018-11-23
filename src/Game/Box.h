#ifndef TMSENGINE_BOX_H_
#define TMSENGINE_BOX_H_

#include "TMSEngine\Component.h"
#include "TMSEngine\Core.h"
#include "TMSEngine\Transform.h"

using  namespace tmsengine;

class Box : public Component
{
public:
		void onUpdate();
		void onInit();

private:
};
#endif