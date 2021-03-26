#include "playerData.h"
#include "common/debugModule/logManager.h"
#include "battleModule/interface/buildSlot.h"

using namespace mb::battleModule;
using namespace common::coreModule;

playerData::playerData() {}
playerData::~playerData() {}

void playerData::init() {
    if (inited || !bf)
        return;
    inited = true;
    initCastle();
    initBuilds();
}

void playerData::initCastle() {
    // init castle
    castle = new battleObject();
    castle->setObjectSize(battleObject::eBattleObjectSize::LARGE);
    bf->getBaseNode()->addChild(castle);
    auto pos = bf->getBaseData().castlePos;
    if (playerPosition == ePlayerPosition::RIGHT) {
        auto bfSize = bf->getBaseNode()->getContentSize();
        pos.x += castle->getContentSize().width;
        pos.x = bfSize.width - pos.x;
    }
    castle->setPosition(pos);
    auto sprite = new nodeWithProperties<cocos2d::Sprite>();
    sprite->setName("build");
    auto fraction = fractionNames.find(getPlayerFraction());
    if (fraction != fractionNames.end()) {
        sprite->loadJson(STRING_FORMAT("battle/buildings/%sCastle", fraction->second.c_str()));
        sprite->loadComponent(sprite, "build");
    } else {
        LOG_ERROR("playerData::initCastle: can't find fraction for load sprite");
        return;
    }
    if (playerPosition == ePlayerPosition::RIGHT) {
        sprite->setFlippedX(true);
    }
    castle->getHolder()->addChild(sprite);
}

void playerData::initBuilds() {
    auto positions = bf->getBaseData().buildingPos;
    if (playerPosition == ePlayerPosition::RIGHT) {
        //todo remove after test
        return;
        std::reverse(positions.begin(), positions.end());
    }

    for (const auto& item : positions) {
//        auto slotHolder = new battleObject();
//        slotHolder->setObjectSize(battleObject::eBattleObjectSize::SMALL);
        auto slot = new buildSlot();
        slot->setPosition(item);
//        slotHolder->getHolder()->addChild(slot);
        bf->getBaseNode()->addChild(slot);
        if (item == positions.front()) {
            slot->setClickAvailable(true);
        }
    }
}
