#include "playerData.h"

using namespace mb::battleModule;
using namespace common::coreModule;

playerData::playerData() {}
playerData::~playerData() {}

void playerData::init() {
    if (inited || !bf)
        return;
    inited = true;
    initCastle();
}

void playerData::initCastle() {
    //init castle
    castle = new battleObject();
    castle->setObjectSize(battleObject::eBattleObjectSize::LARGE);
    bf->getBaseNode()->addChild(castle);
}
