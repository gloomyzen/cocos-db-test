#ifndef MERCENARY_BATTLES_DEFINITIONS_H
#define MERCENARY_BATTLES_DEFINITIONS_H

namespace mercenaryBattles {
	namespace coreModule {

		enum class gameLayers {
			NONE = 0,
			SKY = 2,
			PLAN_3 = 4,
			PLAN_2 = 6,
			PLAN_1 = 8,
			FLOOR = 10
		};

		enum class gameStates {
			MAIN_MENU,
			BATTLE_SCENE
		};
	}
}

#endif //MERCENARY_BATTLES_DEFINITIONS_H
