#ifndef MB_NOTIFYWINDOW_H
#define MB_NOTIFYWINDOW_H

#include "cocos2d.h"
#include "common/coreModule/scenes/windows/windowBase.h"
#include "databasesModule/coursesDatabase.h"

namespace mb::interfaceModule {

    class notifyWindow
        : public common::coreModule::windowBase
        , public taskHolder {
      public:
        notifyWindow();
        ~notifyWindow() = default;
        std::deque<nodeTasks> getTasks() override;
    };
}// namespace mb::interfaceModule


#endif// MB_NOTIFYWINDOW_H
