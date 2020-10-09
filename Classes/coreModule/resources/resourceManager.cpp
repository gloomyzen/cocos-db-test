#include "resourceManager.h"
#include "debugModule/logManager.h"
#include "cocos2d.h"

using namespace mb::coreModule;

resourceManager *currentResourceManager = nullptr;

resourceManager::resourceManager() {}

resourceManager::~resourceManager() {}

resourceManager &resourceManager::getInstance() {
	if (currentResourceManager == nullptr) {
		currentResourceManager = new resourceManager();
		// add Resources folder to search path. This is necessary when releasing for win32
//		cocos2d::FileUtils::getInstance()->addSearchPath("Resources");
	}
	return *currentResourceManager;
}

jsonLoader *resourceManager::getJsonLoader() {
	return &jsonLoaderInstance;
}
