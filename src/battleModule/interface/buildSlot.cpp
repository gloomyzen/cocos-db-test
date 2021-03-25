#include "buildSlot.h"

using namespace mb::battleModule;

buildSlot::buildSlot() {
    this->setName("buildSlot");
    loadProperty("battle/" + this->getName(), dynamic_cast<cocos2d::Node*>(this));
    bgNode = findNode("bg");
}

buildSlot::~buildSlot() {}

