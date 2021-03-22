#ifndef MERCENARY_BATTLES_BATTLEFIELD_H
#define MERCENARY_BATTLES_BATTLEFIELD_H

#include "cocos2d.h"
#include "common/coreModule/scenes/windows/windowBase.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include <string>

namespace mb::battleModule {
    class battleField : public common::coreModule::nodeProperties<cocos2d::Node> {
      public:
        battleField();
        ~battleField() = default;
        void loadLocation(const std::string&);

      private:
        cocos2d::Node* baseNode = nullptr;
    };
}


#endif// MERCENARY_BATTLES_BATTLEFIELD_H
