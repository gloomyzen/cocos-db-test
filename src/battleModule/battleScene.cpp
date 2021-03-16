#include "battleScene.h"

using namespace mb::battleModule;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

std::deque<nodeTasks> battleScene::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() { return eTasksStatus::STATUS_OK; });

    return result;
}
