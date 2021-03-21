#ifndef MERCENARY_BATTLES_BASE_H
#define MERCENARY_BATTLES_BASE_H

#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "common/coreModule/scenes/windows/windowBase.h"

namespace mb::battleModule {

    class base
        : public common::coreModule::nodeProperties<cocos2d::Node>
        , public taskHolder {
      public:
        base();
        ~base() = default;
        std::deque<nodeTasks> getTasks() override;
    };

}// namespace mb::battleModule


#endif// MERCENARY_BATTLES_BASE_H
