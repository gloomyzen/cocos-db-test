#ifndef MERCENARY_BATTLES_GENERALSCENE_H
#define MERCENARY_BATTLES_GENERALSCENE_H

#include "cocos2d.h"
#include "coreModule/properties/nodeProperties.h"

namespace mercenaryBattles {
	using namespace cocos2d;

	namespace coreModule {
		class generalScene : public Scene {
		public:
			static cocos2d::Scene *createScene();

			virtual bool init();

			// a selector callback
			void menuCloseCallback(cocos2d::Ref *pSender);

			// implement the "static create()" method manually
			CREATE_FUNC(generalScene);
		};
	}
}


#endif //MERCENARY_BATTLES_GENERALSCENE_H
