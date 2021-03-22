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
        void initCameraHandling();
//        base* playerBase = nullptr;
        battleField* battleFieldNode = nullptr;
        // camera section
        cocos2d::Camera* camera = nullptr;
        cocos2d::Vec3 startCameraPos;
        cocos2d::EventListenerTouchOneByOne* cameraListener = nullptr;
        cocos2d::Vec2 cameraTouchPos;
    };
}// namespace mb::interfaceModule


#endif// MERCENARY_BATTLES_BATTLESCENE_H
