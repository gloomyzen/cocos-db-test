#ifdef DEBUG

#include "heroProfileDebug.h"
#include "CCImGuiLayer.h"
#include "cocos2d.h"
#include <CCIMGUI.h>
#include <common/profileModule/profileManager.h>
#include <databasesModule/charactersDatabase.h>
#include <databasesModule/databaseManager.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <localProfile/heroesProfileBlock.h>

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
        profileWindow(&isOpened);
    }
}

void heroProfileDebug::profileWindow(bool* windowOpened) {
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(400), static_cast<float>(350)),
                             ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Heroes list", reinterpret_cast<bool*>(windowOpened))) {
        ImGui::End();
        return;
    }

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
    ImGui::Columns(2, "AB");

    ImGui::BeginChild("left");
    leftList();
    ImGui::EndChild();

    ImGui::NextColumn();

    ImGui::BeginChild("right");
//    renderPreferences(lastTarget);
    ImGui::EndChild();

    ImGui::PopStyleVar();
    ImGui::End();
}

void heroProfileDebug::leftList() {
    using namespace databasesModule;
    auto characterDb = GET_DATABASE_MANAGER().getDatabase<charactersDatabase>(databaseManager::eDatabaseList::CHARACTER_DB);
    auto profile = GET_PROFILE().getBlock<localProfile::heroesProfileBlock>("heroes");
    for (const auto& item : characterDb->getCharacters()) {
        std::string str;
        if (profile->hasHero(item.second->id)) {
            str = STRING_FORMAT("%d +", item.second->id);
        } else {
            str = STRING_FORMAT("%d", item.second->id);
        }
        if (ImGui::ButtonEx(str.c_str(), ImVec2(0, 0), ImGuiButtonFlags_AlignTextBaseLine | ImGuiButtonFlags_NoHoveredOnFocus)) {
            //
        }
    }
}

#endif