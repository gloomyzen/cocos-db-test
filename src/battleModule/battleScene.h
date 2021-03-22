#ifndef MERCENARY_BATTLES_BATTLESCENE_H
#define MERCENARY_BATTLES_BATTLESCENE_H

#include "cocos2d.h"
#include "common/coreModule/scenes/windows/windowBase.h"
#include "common/coreModule/nodes/nodeProperties.h"
//#include "battleModule/base.h"
#include "battleModule/battleField.h"

namespace mb::battleModule {

    class battleScene
        : public common::coreModule::nodeProperties<cocos2d::Layer>
        , public taskHolder {
      public:
        battleScene();
        ~battleScene();
        std::deque<nodeTasks> getTasks() override;

      private:
//        base* playerBase = nullptr;
        battleField* battleFieldNode = nullptr;
        // world section
        cocos2d::Layer* world = nullptr;
    };
}// namespace mb::interfaceModule


#endif// MERCENARY_BATTLES_BATTLESCENE_H
