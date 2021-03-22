#include "battleScene.h"
#include "ui/CocosGUI.h"

using namespace mb::battleModule;
using namespace cocos2d;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

battleScene::~battleScene() { this->getEventDispatcher()->removeEventListener(worldTouchListener); }

std::deque<nodeTasks> battleScene::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() {
        world = dynamic_cast<cocos2d::Layer*>(findNode("world"));
        battleFieldNode = new battleField();
        battleFieldNode->loadLocation("forest");
        world->addChild(battleFieldNode);

        return eTasksStatus::STATUS_OK;
    });

    result.emplace_back([this]() {
           auto scrollView = dynamic_cast<ui::ScrollView*>(findNode("scrollContainer"));
           if (!scrollView) {
               return eTasksStatus::STATUS_ERROR_BREAK;
           }
           scrollView->setInnerContainerSize(world->getContentSize());
           world->setMarkDirty();

           return eTasksStatus::STATUS_OK;
    });

    return result;
}
void battleScene::initCameraHandling() {
    startWorldPos = world->getPosition();
    worldTouchListener = cocos2d::EventListenerTouchOneByOne::create();
    worldTouchListener->setSwallowTouches(true);
    worldTouchListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        worldTouchPos = touch->getLocation();
        return true;
    };
    worldTouchListener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto force = 0.2f;
        float xDiff = world->getPositionX() - (worldTouchPos.x - touch->getLocation().x);
        //        float yDiff = startWorldPos.y + (worldTouchPos.y - touch->getLocation().y);
        if (startWorldPos.x + 300 >= xDiff && startWorldPos.x < xDiff) {
            world->setPositionX(world->getPositionX() - (worldTouchPos.x - touch->getLocation().x));
        }
        //        if (startWorldPos.y - 20 >= yDiff && startWorldPos.y + 100 < yDiff) {
        //            world->setPositionY(yDiff);
        //        }
        auto test = "";
    };
    //    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(worldTouchListener, this);
}
