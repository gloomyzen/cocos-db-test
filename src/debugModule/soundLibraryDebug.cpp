#ifdef DEBUG

#include "soundLibraryDebug.h"
#include "CCImGuiLayer.h"
#include "cocos2d.h"
#include <CCIMGUI.h>
#include <imgui.h>
#include <imgui_internal.h>
#include "common/audioModule/audioEngine.h"

using namespace mb::debugProfile;


soundLibraryDebug::soundLibraryDebug() {}
soundLibraryDebug::~soundLibraryDebug() {}

soundLibraryDebug* currentSoundDebugger = nullptr;

soundLibraryDebug& soundLibraryDebug::getInstance() {
    if (currentSoundDebugger == nullptr) {
        currentSoundDebugger = new soundLibraryDebug();
    }
    return *currentSoundDebugger;
}

void soundLibraryDebug::update() {
    if (ImGui::Button("Sounds")) {
        isOpened = !isOpened;
    }
    if (isOpened) {
        soundWindow(&isOpened);
    }
}

void soundLibraryDebug::soundWindow(bool* windowOpened) {
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(400), static_cast<float>(350)),
                             ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Sounds debug", reinterpret_cast<bool*>(windowOpened))) {
        ImGui::End();
        return;
    }

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));

    ImGui::BeginChild("sounds");
    ImGui::PushID("sounds");

    auto effects = GET_AUDIO_ENGINE().getAllEffects();
    const char* items[effects.size()];
    static int currentEffect = 0;
    int countEffects = 0;
    std::for_each(effects.begin(), effects.end(), [&items, &countEffects](const auto& effect){
           items[countEffects] = effect.first.c_str();
           countEffects++;
    });

    ImGui::Combo("Effects", &currentEffect, items, IM_ARRAYSIZE(items));
    if (ImGui::Button("Play effect") && currentEffect >= 0 && currentEffect < static_cast<int>(effects.size())) {
        GET_AUDIO_ENGINE().playEffect(items[currentEffect]);
    }

    ImGui::Separator();

    auto musics = GET_AUDIO_ENGINE().getAllMusics();
    const char* musicsItems[musics.size()];
    static int currentMusic = 0;
    int countMusic = 0;
    std::for_each(musics.begin(), musics.end(), [&musicsItems, &countMusic](const auto& music){
           musicsItems[countMusic] = music.first.c_str();
           countMusic++;
    });

    ImGui::Combo("Musics", &currentMusic, musicsItems, IM_ARRAYSIZE(musicsItems));
    if (ImGui::Button("Play music") && currentMusic >= 0 && currentMusic < static_cast<int>(musics.size())) {
        GET_AUDIO_ENGINE().playBackgroundMusic(musicsItems[currentMusic]);
    }
    ImGui::SameLine();
    if (ImGui::Button("Stop all musics")) {
        GET_AUDIO_ENGINE().stopBackgroundMusic();
    }

    if (ImGui::Button("Pause all musics")) {
        GET_AUDIO_ENGINE().pauseBackgroundMusic();
    }
    ImGui::SameLine();
    if (ImGui::Button("Resume all musics")) {
        GET_AUDIO_ENGINE().resumeBackgroundMusic();
    }


    ImGui::PopID();
    ImGui::EndChild();

    ImGui::PopStyleVar();
    ImGui::End();
}

#endif