#include "battleScene.h"
#include "ui/CocosGUI.h"

using namespace mb::battleModule;
using namespace cocos2d;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

battleScene::~battleScene() {}

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
