#ifndef MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
#define MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H

#include "cocos2d.h"
#include "coreModule/enums/layersEnum.h"
#include "coreModule/enums/statesEnums.h"
#include <map>
#include <functional>
#include <string>

namespace mercenaryBattles {

	namespace coreModule {
		using namespace cocos2d;

		class scenesFactoryInstance {
		public:
			scenesFactoryInstance();
			~scenesFactoryInstance();
			static scenesFactoryInstance &getInstance();
			Node* getStateRoot(eGameStates);
			void registerState(eGameStates, std::function<Node*()>);
		private:
			std::map<eGameStates, std::function<Node*()>> states{};
		};
	}
}


#endif //MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
