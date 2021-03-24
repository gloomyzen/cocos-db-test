#ifndef MERCENARY_BATTLES_BATTLEFIELD_H
#define MERCENARY_BATTLES_BATTLEFIELD_H

#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "common/coreModule/nodes/widgets/node3d.h"
#include <string>

namespace mb::battleModule {
    class battleField : public common::coreModule::nodeProperties<cocos2d::Node> {
      public:
        battleField();
        ~battleField() = default;
        void loadLocation(const std::string&);
        common::coreModule::node3d* getBaseNode() { return baseNode; }

      private:
        common::coreModule::node3d* baseNode = nullptr;
    };
}


#endif// MERCENARY_BATTLES_BATTLEFIELD_H
