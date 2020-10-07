#ifndef MERCENARY_BATTLES_METATABS_H
#define MERCENARY_BATTLES_METATABS_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "coreModule/nodes/nodeProperties.h"

namespace mb {
	namespace metaModule {
		using namespace cocos2d;
		using namespace ui;

		class metaTabs : public coreModule::nodeProperties {
		public:
			metaTabs();

			~metaTabs();

			CREATE_FUNC(metaTabs);

			static Node *createNode() { return metaTabs::create(); }

			bool init() {
				if (!Node::init()) {
					return false;
				}
				return true;
			}

		private:
			void createPageView();
			PageView* pageView = nullptr;

		};
	}
}//mb::metaTabs


#endif //MERCENARY_BATTLES_METATABS_H
