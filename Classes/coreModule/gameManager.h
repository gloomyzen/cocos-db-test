#ifndef MERCENARY_BATTLES_GAMEMANAGER_H
#define MERCENARY_BATTLES_GAMEMANAGER_H

#include "cocos2d.h"
#include "enums/layersEnum.h"
#include "enums/scenesEnums.h"

#define GET_GAME_MANAGER() mercenaryBattles::coreModule::gameManager::getInstance()

namespace mercenaryBattles {

	namespace coreModule {
		class mainScene;
		using namespace cocos2d;

		class gameManager {
		public:
			gameManager();
			~gameManager();
			static gameManager &getInstance();

			void run();
			void changeState(eGameStates state);
			eGameStates getCurrentState() { return currentState; }

		private:
			eGameStates currentState;
			mainScene* mainSceneIns = nullptr;
		};
	}
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_GAMEMANAGER_H
