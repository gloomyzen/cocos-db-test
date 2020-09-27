#ifndef MERCENARY_BATTLES_NODEFACTORY_H
#define MERCENARY_BATTLES_NODEFACTORY_H

#include "cocos2d.h"
#include <string>
#include "rapidjson/document.h"

namespace mercenaryBattles {
	namespace coreModule {
		using namespace cocos2d;

		enum eNodeFactory : size_t {
			TRANSFORM_COMPONENT,
			SPRITE_COMPONENT,
			ANIMSPRITE_COMPONENT,
		};

		class nodeFactory {
		public:
			static void getComponents(Node *node, const std::string &componentName,
									  const rapidjson::GenericValue<rapidjson::UTF8<char>>::Object &object);

			static bool hasRegisteredComponent(const std::string &componentName);
		};
	}
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_NODEFACTORY_H
