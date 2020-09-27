#ifndef MERCENARY_BATTLES_NODEPROPERTIES_H
#define MERCENARY_BATTLES_NODEPROPERTIES_H

#include "cocos2d.h"

namespace mercenaryBattles {
	using namespace cocos2d;

	namespace coreModule {

		class nodeProperties: public Node {
		public:
			CREATE_FUNC(nodeProperties);
			static Node* createNode() {
				return nodeProperties::create();
			}

			bool init() {
				if(!Node::init())
				{
					return false;
				}
				return true;
			}
//			virtual void draw(Renderer* renderer, const Mat4& transform, uint32_t flags);
		};
	}
}//mercenaryBattles::coreModule

#endif //MERCENARY_BATTLES_NODEPROPERTIES_H
