#include "scenesFactoryInstance.h"
#include "debugModule/logManager.h"
#include <map>

using namespace mb;
using namespace mb::coreModule;
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

Layer *scenesFactoryInstance::getStateRoot(eGameStates state) {
	if (states.count(state)) {
		auto node = Layer::create();
		return states[state](node);
	}
	LOG_ERROR("scenesFactoryInstance::getStateRoot: Current state " + std::to_string(state) + " is not registered! Return simple layer.");
	return Layer::create();
}

void scenesFactoryInstance::registerState(eGameStates state, std::function<Layer *(Layer*)> clb) {
	states[state] = std::move(clb);
}
