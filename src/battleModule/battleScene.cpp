#include "battleScene.h"

using namespace mb::battleModule;
using namespace cocos2d;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

battleScene::~battleScene() { this->getEventDispatcher()->removeEventListener(cameraListener); }

std::deque<nodeTasks> battleScene::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() {
        battleFieldNode = new battleField();
        battleFieldNode->loadLocation("forest");
        addChild(battleFieldNode);

        initCameraHandling();

        return eTasksStatus::STATUS_OK;
    });

    return result;
}
void battleScene::initCameraHandling() {
    camera = Director::getInstance()->getRunningScene()->getDefaultCamera();
    startCameraPos = camera->getPosition3D();
    cameraListener = cocos2d::EventListenerTouchOneByOne::create();
    cameraListener->setSwallowTouches(true);
    cameraListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        cameraTouchPos = touch->getLocation();
        return true;
    };
    cameraListener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        float x = 0.f;
        float y = 0.f;
        float xDiff = startCameraPos.x + (cameraTouchPos.x - touch->getLocation().x);//500 +
        float yDiff = startCameraPos.y + (cameraTouchPos.y - touch->getLocation().y);
        if (xDiff >= startCameraPos.x && startCameraPos.x + 100 > xDiff) {
            camera->setPositionX(startCameraPos.x + xDiff);
        }
        if (startCameraPos.y >= yDiff && startCameraPos.y + 20 < yDiff) {}
    };
//    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(cameraListener, this);
}
