#ifndef MERCENARY_BATTLES_ICONLABEL_H
#define MERCENARY_BATTLES_ICONLABEL_H

#include "cocos/ui/CocosGUI.h"
#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"

namespace mb::battleModule {

    class iconLabel
        : public common::coreModule::nodeProperties
        , public cocos2d::Sprite {
      public:
        enum class eIconLabelTypes { GOLD = 0, TROPHIES };
        iconLabel();
        ~iconLabel() override;
        CREATE_FUNC(iconLabel);
    };
}// namespace mb::battleModule


#endif// MERCENARY_BATTLES_ICONLABEL_H
