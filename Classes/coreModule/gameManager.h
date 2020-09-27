#ifndef MERCENARY_BATTLES_GAMEMANAGER_H
#define MERCENARY_BATTLES_GAMEMANAGER_H

#include "cocos2d.h"

#define GET_GAME_MANAGER() mercenaryBattles::coreModule::gameManager::getInstance()

namespace mercenaryBattles {

	namespace coreModule {

	using namespace cocos2d;

		enum eGameLayers {
			NONE = 0,
			SKY = 2,
			PLAN_3 = 4,
			PLAN_2 = 6,
			PLAN_1 = 8,
			FLOOR = 10,
			DEBUG_LAYER = 99
		};

		enum eGameStates {
			MAIN_MENU,
			BATTLE_SCENE
		};

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
		};
	}
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_GAMEMANAGER_H
