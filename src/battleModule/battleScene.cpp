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
        // todo check and update theme for battlefield
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
        auto worldSize = world->getContentSize();
        scrollView->setInnerContainerSize(cocos2d::Size(worldSize.width * 0.8f, worldSize.height * 0.8f));
        world->setMarkDirty();

        return eTasksStatus::STATUS_OK;
    });

    result.emplace_back([this]() {
        // init players
        player.first = new playerData();
        player.first->setPlayerMode(playerData::ePlayerMode::PVE);
        player.first->setPlayerPosition(playerData::ePlayerPosition::LEFT);
        player.first->setPlayerFraction(playerData::ePlayerFraction::HUMAN);
        player.first->setRealUser(true);
        player.first->setBaseNode(battleFieldNode->getBaseNode());
        player.first->init();

        player.second = new playerData();
        player.second->setPlayerMode(playerData::ePlayerMode::PVE);
        player.second->setPlayerPosition(playerData::ePlayerPosition::RIGHT);
        player.second->setPlayerFraction(playerData::ePlayerFraction::ORC);
        player.second->setRealUser(false);
        player.second->setBaseNode(battleFieldNode->getBaseNode());
        player.second->init();

        return eTasksStatus::STATUS_OK;
    });

    return result;
}
