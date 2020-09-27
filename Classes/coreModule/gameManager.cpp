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

void gameManager::run() {
	auto state = eGameStates::MAIN_MENU;
	auto scene = generalScene::createScene();
	Director::getInstance()->runWithScene(scene);
	changeState(state);
}

void gameManager::changeState(eGameStates state) {
	currentState = state;
}
