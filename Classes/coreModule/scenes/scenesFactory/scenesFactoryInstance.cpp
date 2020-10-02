#include "scenesFactoryInstance.h"
#include "debugModule/logManager.h"
#include <map>

using namespace mercenaryBattles;
using namespace mercenaryBattles::coreModule;
using namespace cocos2d;

scenesFactoryInstance *currentFactoryInstance = nullptr;

scenesFactoryInstance::scenesFactoryInstance() = default;

scenesFactoryInstance::~scenesFactoryInstance() = default;

scenesFactoryInstance &scenesFactoryInstance::getInstance() {
	if (currentFactoryInstance == nullptr) {
		currentFactoryInstance = new scenesFactoryInstance();
	}
	return *currentFactoryInstance;
}

Node *scenesFactoryInstance::getStateRoot(eGameStates state) {
	switch (state) {
		case MAIN_MENU: return new Node();
		case LOADING_SCREEN: return new Node();
		case BATTLE_SCENE: return new Node();
	}
	LOG_ERROR("scenesFactoryInstance::getStateRoot: Current state " + std::to_string(state) + " is wrong!");
	return nullptr;
}
