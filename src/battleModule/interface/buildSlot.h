#ifndef MERCENARY_BATTLES_BUILDSLOT_H
#define MERCENARY_BATTLES_BUILDSLOT_H

#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "common/coreModule/nodes/widgets/buttonNode.h"

namespace mb::battleModule {

    class buildSlot : public common::coreModule::buttonNode {
      public:
        buildSlot();
        ~buildSlot();
    };
}// namespace mb::battleModule

#endif// MERCENARY_BATTLES_BUILDSLOT_H
