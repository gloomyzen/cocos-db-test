#ifndef MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
#define MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H

#include "cocos2d.h"
#include "coreModule/enums/layersEnum.h"
#include "coreModule/enums/statesEnums.h"
#include <map>
#include <functional>
#include <string>

#define GET_SCENES_FACTORY() mb::coreModule::scenesFactoryInstance::getInstance()

namespace mb {

	namespace coreModule {
		using namespace cocos2d;

		class scenesFactoryInstance {
		public:
			scenesFactoryInstance();
			~scenesFactoryInstance();
			static scenesFactoryInstance &getInstance();
			Node* getStateRoot(eGameStates);
			void registerState(eGameStates, std::function<Node*(Node* node)>);
		private:
			std::map<eGameStates, std::function<Node*(Node* node)>> states{};
		};
	}
}//mb::coreModule


#endif //MERCENARY_BATTLES_SCENESFACTORYINSTANCE_H
