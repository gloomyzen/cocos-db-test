#include "iconLabel.h"

using namespace mb::battleModule;

iconLabel::iconLabel() {
    this->setName("iconLabel");
    loadProperty("battle/" + this->getName(), this);
}

iconLabel::~iconLabel() {}
