#include "resourceManager.h"
#include "debugModule/logManager.h"

using namespace mercenaryBattles::coreModule;

resourceManager *currentResourceManager = nullptr;

resourceManager::resourceManager() {}

resourceManager::~resourceManager() {}

resourceManager &resourceManager::getInstance() {
	if (currentResourceManager == nullptr) {
		currentResourceManager = new resourceManager();
	}
	return *currentResourceManager;
}

jsonLoader *resourceManager::getJsonLoader() {
	return &jsonLoaderInstance;
}
