#ifndef MERCENARY_BATTLES_RESOURCEMANAGER_H
#define MERCENARY_BATTLES_RESOURCEMANAGER_H

#include "cocos2d.h"
#include <map>
#include <string>
#include "coreModule/resources/loaders/jsonLoader.h"

#define GET_RESOURCE_MANAGER() TGEngine::core::ResourceManager::getInstance()
#define GET_JSON_MANAGER() TGEngine::core::ResourceManager::getInstance().getJsonLoader()
#define GET_JSON(L) GET_JSON_MANAGER()->loadJson(L)
#define GET_JSON_PREF(L, K) GET_JSON_MANAGER()->loadJson(L, K)

namespace mercenaryBattles {
	using namespace cocos2d;

	namespace coreModule {
		class resourceManager {
		public:
			resourceManager();
			~resourceManager();
			static resourceManager &getInstance();

			jsonLoader* getJsonLoader();

		private:
			jsonLoader jsonLoaderInstance;
		};
	}
}


#endif //MERCENARY_BATTLES_RESOURCEMANAGER_H
