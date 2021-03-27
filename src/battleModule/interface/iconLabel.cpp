#include "iconLabel.h"
#include "json/document.h"

using namespace mb::battleModule;

iconLabel::iconLabel() {
    this->setName("iconLabel");
    loadProperty("battle/" + this->getName(), this);
    auto settings = getPropertyData().FindMember("settings");
    // todo rename iconLabel -> battleIncomeWidget
    //todo get icon from settings of current node
}

iconLabel::~iconLabel() {}
