#include "gameManager.h"
#include "coreModule/scenes/mainScene.h"
#include "debugModule/logManager.h"

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
	mainSceneIns = dynamic_cast<mainScene *>(mainScene::createScene());
	/// Starting from state
	changeState(eGameStates::BATTLE_SCENE);
	Director::getInstance()->runWithScene(mainSceneIns);

	//todo remove after testing
//	auto seq = Sequence::create(DelayTime::create(7.f), CallFunc::create([this](){
//		changeState(eGameStates::BATTLE_SCENE);
//	}), nullptr);
//	mainSceneIns->runAction(seq);
}

void gameManager::changeState(eGameStates state) {
	if (mainSceneIns == nullptr) {
		LOG_ERROR("gameManager::changeState Instance mainSceneIns is null!");
		return;
	}
	currentState = state;
	mainSceneIns->setRoom(currentState);
}
