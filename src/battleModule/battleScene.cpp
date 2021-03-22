#include "battleScene.h"

using namespace mb::battleModule;
using namespace cocos2d;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

std::deque<nodeTasks> battleScene::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() {
        //------------ player base


        return eTasksStatus::STATUS_OK;
    });

    return result;
}
