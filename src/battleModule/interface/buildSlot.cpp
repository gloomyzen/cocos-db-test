#include "buildSlot.h"

using namespace mb::battleModule;

buildSlot::buildSlot() {
    this->setName("buildSlot");
    loadProperty("battle/" + this->getName(), dynamic_cast<cocos2d::Node*>(this));
    setClickAvailable(false);
}

buildSlot::~buildSlot() {}

void buildSlot::setClickAvailable(bool value) {
    if (value) {
//        setName("buildSlotGreen");
//        loadComponent(this, "buildSlotGreen");
        this->loadTexture("images/battle/ui/green.png");
    } else {
//        setName("buildSlotRed");
//        loadComponent(this, "buildSlotRed");
        this->loadTexture("images/battle/ui/red.png");
//        this->loadTextureNormal("images/battle/ui/red.png");
    }
//    loadComponent(this, this->getName());
    setClickable(value);
}
