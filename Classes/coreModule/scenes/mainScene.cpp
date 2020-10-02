#include "mainScene.h"
#include "debugModule/logManager.h"
#include "debugModule/imGuiLayer.h"
#include "coreModule/gameManager.h"

using namespace mercenaryBattles::coreModule;
using namespace cocos2d;

Scene *mainScene::createScene() {
	return mainScene::create();
}

bool mainScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!Scene::init()) {
		return false;
	}
	LOG_INFO("mainScene::init()");

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto _background = cocos2d::Sprite::create("images/ui/windows/testWindow/background.png");
	this->addChild(_background);


	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr) {
		LOG_ERROR("'fonts/Marker Felt.ttf'");
	} else {
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
								origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);

		auto imGuiLayer = mercenaryBattles::debugModule::imGuiLayer::create();

		this->addChild(imGuiLayer, mercenaryBattles::coreModule::eGameLayers::DEBUG_LAYER);
	}

	return true;
}

void mainScene::menuCloseCallback(Ref *pSender) {
	Director::getInstance()->end();
}