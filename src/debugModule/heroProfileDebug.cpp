#ifdef DEBUG

#include "heroProfileDebug.h"
#include "CCImGuiLayer.h"
#include <CCIMGUI.h>
#include <imgui.h>
#include <imgui_internal.h>

using namespace mb::debugProfile;


heroProfileDebug::heroProfileDebug() {}
heroProfileDebug::~heroProfileDebug() {}

heroProfileDebug* currentProfileDebugger = nullptr;

heroProfileDebug& heroProfileDebug::getInstance() {
    if (currentProfileDebugger == nullptr) {
        currentProfileDebugger = new heroProfileDebug();
    }
    return *currentProfileDebugger;
}

void heroProfileDebug::update() {
    if (ImGui::Button("Heroes")) {
        isOpened = !isOpened;
    }
    if (isOpened) {
        //some action
    }
}

#endif