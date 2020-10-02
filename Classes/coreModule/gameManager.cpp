#include "gameManager.h"
#include "coreModule/scenes/mainScene.h"

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
	/// Starting from state
	changeState(eGameStates::MAIN_MENU);

	mainScene = mainScene::createScene();

	Director::getInstance()->runWithScene(mainScene);
}

void gameManager::changeState(eGameStates state) {
	currentState = state;
}
