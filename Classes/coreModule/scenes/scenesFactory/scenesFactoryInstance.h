#ifndef MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
#define MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H

#include "cocos2d.h"
#include "coreModule/enums/layersEnum.h"
#include "coreModule/enums/scenesEnums.h"

namespace mercenaryBattles {

	namespace coreModule {
		using namespace cocos2d;

		class scenesFactoryInstance {
		public:
			scenesFactoryInstance();
			~scenesFactoryInstance();
			static scenesFactoryInstance &getInstance();
			Node* getStateRoot(eGameStates);
		};
	}
}


#endif //MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
