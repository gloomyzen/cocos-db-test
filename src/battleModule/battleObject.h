#ifndef MERCENARY_BATTLES_BATTLEOBJECT_H
#define MERCENARY_BATTLES_BATTLEOBJECT_H

#include "battleModule/battleField.h"
#include "battleModule/playerData/playerData.h"
#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "common/coreModule/scenes/windows/windowBase.h"
#include <tuple>

namespace mb::battleModule {

    class battleObject : public common::coreModule::nodeProperties<common::coreModule::node3d> {
      public:
        enum class eBattleObjectSize { SMALL = 0, MEDIUM, LARGE };
        battleObject();
        ~battleObject();
        void setObjectSize(eBattleObjectSize);
    };
}// namespace mb::battleModule


#endif// MERCENARY_BATTLES_BATTLEOBJECT_H
