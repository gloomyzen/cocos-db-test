#ifndef MERCENARY_BATTLES_ICONLABEL_H
#define MERCENARY_BATTLES_ICONLABEL_H

#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"
#include "common/coreModule/nodes/nodeProperties.h"

namespace mb::battleModule {

    class iconLabel
        : public common::coreModule::nodeProperties, public cocos2d::Sprite {
      public:
        iconLabel();
        ~iconLabel() override;
        CREATE_FUNC(iconLabel);
    };
}


#endif// MERCENARY_BATTLES_ICONLABEL_H
