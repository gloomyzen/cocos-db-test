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
		case MAIN_MENU: {
			// todo change to cast instance
			auto node = new Node();
			auto visibleSize = Director::getInstance()->getVisibleSize();
			Vec2 origin = Director::getInstance()->getVisibleOrigin();

			auto _background = cocos2d::Sprite::create("images/ui/windows/testWindow/background.png");
			node->addChild(_background);
			auto label = Label::createWithTTF("Main menu", "fonts/Marker Felt.ttf", 24);
			if (label == nullptr) {
				LOG_ERROR("'fonts/Marker Felt.ttf'");
			} else {
				// position the label on the center of the screen
				label->setPosition(Vec2(origin.x + visibleSize.width / 2,
										origin.y + visibleSize.height - label->getContentSize().height));
				// add the label as a child to this layer
				node->addChild(label, 1);
			}
			return node;
		}
		case LOADING_SCREEN: return new Node();
		case BATTLE_SCENE: {
			// todo change to cast instance
			auto node = new Node();
			auto visibleSize = Director::getInstance()->getVisibleSize();
			Vec2 origin = Director::getInstance()->getVisibleOrigin();

			auto _background = cocos2d::Sprite::create("images/ui/windows/testWindow/background.png");
			node->addChild(_background);
			node->addChild(cocos2d::Sprite::create("images/ui/windows/testWindow/icon_gold.png"));
			node->addChild(cocos2d::Sprite::create("images/ui/windows/testWindow/icon_treasure.png"));
			auto label = Label::createWithTTF("Battle scene", "fonts/Marker Felt.ttf", 24);
			if (label == nullptr) {
				LOG_ERROR("'fonts/Marker Felt.ttf'");
			} else {
				// position the label on the center of the screen
				label->setPosition(Vec2(origin.x + visibleSize.width / 2,
										origin.y + visibleSize.height - label->getContentSize().height));
				// add the label as a child to this layer
				node->addChild(label, 1);
			}
			return node;
		}
	}
	LOG_ERROR("scenesFactoryInstance::getStateRoot: Current state " + std::to_string(state) + " is wrong!");
	return nullptr;
}
