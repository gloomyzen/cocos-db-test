#ifndef MERCENARY_BATTLES_GAMEMANAGER_H
#define MERCENARY_BATTLES_GAMEMANAGER_H

#include "cocos2d.h"

#define GET_GAME_MANAGER() mercenaryBattles::coreModule::gameManager::getInstance()

namespace mercenaryBattles {
	using namespace cocos2d;

	enum gameLayers {
		NONE = 0,
		SKY = 2,
		PLAN_3 = 4,
		PLAN_2 = 6,
		PLAN_1 = 8,
		FLOOR = 10
	};

	enum gameStates {
		MAIN_MENU,
		BATTLE_SCENE
	};

	namespace coreModule {

		class gameManager {
		public:
			gameManager();
			~gameManager();
			static gameManager &getInstance();

			void run(gameStates state = gameStates::MAIN_MENU);
			void changeState(gameStates state);
			gameStates getCurrentState() { return currentState; }

		private:
			gameStates currentState;
		};
	}
}


#endif //MERCENARY_BATTLES_GAMEMANAGER_H
