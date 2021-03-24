#include "battleObject.h"
#include <string>

using namespace mb::battleModule;

battleObject::battleObject() {
    this->setName("battleObject");
    loadProperty("battle/" + this->getName(), this);
}

battleObject::~battleObject() {}

void battleObject::setObjectSize(battleObject::eBattleObjectSize size) {
    std::string name;
    switch (size) {

    case eBattleObjectSize::SMALL:
        name = STRING_FORMAT("%sSmall", this->getName().c_str());
        break;
    case eBattleObjectSize::MEDIUM:
        name = STRING_FORMAT("%sMedium", this->getName().c_str());
        break;
    case eBattleObjectSize::LARGE:
        name = STRING_FORMAT("%sLarge", this->getName().c_str());
        break;
    }
    //todo wip
}
