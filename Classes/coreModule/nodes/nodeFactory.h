#ifndef MERCENARY_BATTLES_NODEFACTORY_H
#define MERCENARY_BATTLES_NODEFACTORY_H

#include "cocos2d.h"
#include <string>
#include <map>
#include <functional>
#include "rapidjson/document.h"

#define GET_NODE_FACTORY() mb::coreModule::nodeFactory::getInstance()

namespace mb {
	namespace coreModule {
		using namespace cocos2d;

		enum eNodeFactory : size_t {
			TRANSFORM_COMPONENT,
			SPRITE_COMPONENT,
			ANIMSPRITE_COMPONENT,
		};

		class nodeFactory {
		public:
			nodeFactory();
			~nodeFactory();
			static nodeFactory &getInstance();

			void getComponents(Node *node, const std::string &componentName,
									  const rapidjson::GenericValue<rapidjson::UTF8<char>>::Object &object);

			bool hasRegisteredComponent(const std::string &componentName);

			Node* createNodeWithType(const std::string &type);

		private:
			void init();
			bool inited = false;
		};
	}
}//mb::coreModule


#endif //MERCENARY_BATTLES_NODEFACTORY_H
