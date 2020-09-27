#include "generalScene.h"
#include "debugModule/logManager.h"

using namespace mercenaryBattles::coreModule;
using namespace cocos2d;

Scene *generalScene::createScene() {
	return generalScene::create();
}

bool generalScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!Scene::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
		LOG_ERROR("'fonts/Marker Felt.ttf'");
	if (label == nullptr) {
	} else {
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
								origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	return true;
}

void generalScene::menuCloseCallback(Ref *pSender) {
	Director::getInstance()->end();
}