#include "gameManager.h"
#include "coreModule/scenes/generalScene.h"

using namespace mercenaryBattles;
using namespace mercenaryBattles::coreModule;

gameManager *currentGameManager = nullptr;

gameManager::gameManager() = default;

gameManager::~gameManager() = default;

gameManager &gameManager::getInstance() {
	if (currentGameManager == nullptr) {
		currentGameManager = new gameManager();
	}
	return *currentGameManager;
}

void gameManager::run(gameStates state) {
	auto scene = generalScene::createScene();
	Director::getInstance()->runWithScene(scene);
	changeState(state);
}

void gameManager::changeState(gameStates state) {
	currentState = state;
}
