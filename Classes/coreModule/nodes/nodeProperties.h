#ifndef MERCENARY_BATTLES_NODEPROPERTIES_H
#define MERCENARY_BATTLES_NODEPROPERTIES_H

#include "debugModule/logManager.h"
#include "cocos2d.h"
#include <string>

namespace mercenaryBattles {
	using namespace cocos2d;

	namespace coreModule {

		class nodeProperties : public Node {
		public:

			void setId(const std::string &name) {
				this->setName(name);
			}

			std::string getId() { return this->getName(); }

			void setPropertyPath(const std::string &path) {
				propertyPath = path;
			}

			std::string getPropertyPath() { return propertyPath; }

			void loadProperty(const std::string &path, Node *node);

//			virtual void draw(Renderer* renderer, const Mat4& transform, uint32_t flags);

		private:
			std::string propertyPath{};
		};
	}
}//mercenaryBattles::coreModule

#endif //MERCENARY_BATTLES_NODEPROPERTIES_H
