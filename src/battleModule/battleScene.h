#ifndef MERCENARY_BATTLES_BATTLESCENE_H
#define MERCENARY_BATTLES_BATTLESCENE_H

#include "cocos2d.h"
#include "common/coreModule/scenes/windows/windowBase.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "battleModule/base.h"

namespace mb::battleModule {

    class battleScene
        : public common::coreModule::nodeProperties<cocos2d::Node>
        , public taskHolder {
      public:
        battleScene();
        ~battleScene() = default;
        std::deque<nodeTasks> getTasks() override;

      private:
        base* playerBase = nullptr;
    };
}// namespace mb::interfaceModule


#endif// MERCENARY_BATTLES_BATTLESCENE_H
