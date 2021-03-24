#include "playerData.h"

using namespace mb::battleModule;
using namespace common::coreModule;

playerData::playerData() {}
playerData::~playerData() {}

void playerData::init() {
    castle = new battleObject();
    castle->setObjectSize(battleObject::eBattleObjectSize::LARGE);
    baseNode->addChild(castle);
}
