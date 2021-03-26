#include "buildSlot.h"

using namespace mb::battleModule;

buildSlot::buildSlot() {
    this->setName("buildSlot");
    loadProperty("battle/" + this->getName(), dynamic_cast<cocos2d::Node*>(this));
    setClickAvailable(false);
}

buildSlot::~buildSlot() {}

common::coreModule::eventNode::eventTouchClb buildSlot::getOnTouchEnded() {
    return clickAvailable ? eventNode::getOnTouchEnded() : nullptr;
}

void buildSlot::setClickAvailable(bool value) {
    clickAvailable = value;
    setClickable(value);
}