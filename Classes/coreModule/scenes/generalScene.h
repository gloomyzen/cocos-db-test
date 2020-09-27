#ifndef MERCENARY_BATTLES_GENERALSCENE_H
#define MERCENARY_BATTLES_GENERALSCENE_H

#include "cocos2d.h"
#include "coreModule/nodes/nodeProperties.h"

namespace mercenaryBattles {
	namespace coreModule {

	using namespace cocos2d;

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
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_GENERALSCENE_H
