#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
// dam optimization god gtxx9903
using namespace geode::prelude;

// player
bool noclipEnabled = Mod::get()->getSavedValue<bool>("noclip-enabled", false);
bool ignoreInputsEnabled = Mod::get()->getSavedValue<bool>("ignore-inputs-enabled", false);
bool jumpHackEnabled = Mod::get()->getSavedValue<bool>("jump-hack-emabled", false);
bool autoclickerEnabled = Mod::get()->getSavedValue<bool>("auto-clicker-enabled", false);

// editor
bool verifyHackEnabled = Mod::get()->getSavedValue<bool>("verify-hack-enabled", false);
bool copyHackEnabled = Mod::get()->getSavedValue<bool>("copy-hack-enabled", false);
bool noCMarkEnabled = Mod::get()->getSavedValue<bool>("no-c-mark-enabled", false);
bool customObjectsBypassEnabled = Mod::get()->getSavedValue<bool>("custom-objects-bypass-enabled", false);

// misc
float speedhackValue = Mod::get()->getSavedValue<float>("speedhack-value");
float noWavePulseValue = Mod::get()->getSavedValue<float>("no-wave-pulse-value");
bool practiceMusicHackEnabled = Mod::get()->getSavedValue<bool>("practice-music-hack-enabled", false);
bool hidePauseButtonEnabled = Mod::get()->getSavedValue<bool>("hide-pause-button-enabled", false);
bool layoutModeEnabled = Mod::get()->getSavedValue<bool>("layout-mode-enabled", false);
bool commentHistoryBypassEnabled = Mod::get()->getSavedValue<bool>("comment-history-bypass-enabled", false);
bool autoPracticeEnabled = Mod::get()->getSavedValue<bool>("auto-practice-enabled", false);
bool iconHackEnabled = Mod::get()->getSavedValue<bool>("icon-hack-enabled", false);
bool colorHackEnabled = Mod::get()->getSavedValue<bool>("color-hack-enabled", false);
bool noSolidsEnabled = Mod::get()->getSavedValue<bool>("no-solids-enabled", false);
bool suicideEnabled = Mod::get()->getSavedValue<bool>("suicide-enabled", false);
bool showHitboxesEnabled = Mod::get()->getSavedValue<bool>("show-hitboxes-enabled", false);
bool yes = Mod::get()->getSavedValue<bool>("yes-btw-hi", false);
bool showHitboxesOnDeathEnabled = Mod::get()->getSavedValue<bool>("show-hitboxes-on-death-enabled", false);
bool rainbowIconsEnabled = Mod::get()->getSavedValue<bool>("rainbow-icons-enabled", false);
bool everythingKillsYouEnabled = Mod::get()->getSavedValue<bool>("everything-kills-you-enabled", false);
bool safeModeEnabled = Mod::get()->getSavedValue<bool>("safe-mode-enabled", false);
bool instantCompleteEnabled = Mod::get()->getSavedValue<bool>("instant-complete-enabled", false);
bool basementBypassEnabled = Mod::get()->getSavedValue<bool>("basement-bypass-enabled", false);
bool levelEditEnabled = Mod::get()->getSavedValue<bool>("level-edit-bypass-enabled", false);
bool mainLevelBypassEnabled = Mod::get()->getSavedValue<bool>("main-level-bypass-enabled", false);
bool towerBypassEnabled = Mod::get()->getSavedValue<bool>("tower-bypass-enabled", false);
bool noGlowEnabled = Mod::get()->getSavedValue<bool>("no-glow-enabled", false);
bool SolidWave = Mod::get()->getSavedValue<bool>("SolidWave", false);
bool noWavePulse = Mod::get()->getSavedValue<bool>("noWavePulse", false);
$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        ImGuiStyle& style = ImGui::GetStyle();
        
        style.Alpha = 1.0f;
        style.FrameRounding = 3.0f;
        
        style.Colors[ImGuiCol_Text]                  = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
        style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
        style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
        style.Colors[ImGuiCol_Border]                = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
        style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.21f, 0.23f, 1.00f);
        style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.28f, 0.29f, 0.31f, 1.00f);
        style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.09f, 0.09f, 0.09f, 1.00f);
        style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
        style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
        style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.20f, 0.25f, 0.30f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.27f, 0.30f, 0.35f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.33f, 0.36f, 0.41f, 1.00f);
        style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.37f, 0.61f, 0.99f, 1.00f);
        style.Colors[ImGuiCol_Button]                = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
        style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_Header]                = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
        style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_Separator]             = ImVec4(0.43f, 0.43f, 0.50f, 1.00f);
        style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.57f, 0.57f, 0.64f, 1.00f);
        style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.76f, 0.76f, 0.84f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
        style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        style.Colors[ImGuiCol_Tab]                   = ImVec4(0.18f, 0.35f, 0.58f, 0.86f);
        style.Colors[ImGuiCol_TabHovered]            = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        style.Colors[ImGuiCol_TabActive]             = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
        style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
        style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
        style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
    }).draw([]() {        
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        if (ImGui::BeginTabBar("Polo")) {
            if (ImGui::BeginTabItem("Misc")) {
                ImGui::Text("speedhack");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                }
#else
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f")) {
                    Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                }
#endif
                
                ImGui::Text("no wave pulse");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    Mod::get()->setSavedValue("no-wave-pulse-value", noWavePulseValue);
                }
#else
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f")) {
                    Mod::get()->setSavedValue("no-wave-pulse-value", noWavePulseValue);
                }
#endif
                
                ImGui::Text("practice music hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##practicemusichack", &practiceMusicHackEnabled)) {
                    Mod::get()->setSavedValue("practice-music-hack-enabled", practiceMusicHackEnabled);
                }
                
                ImGui::Text("hide pause button");
                ImGui::SameLine();
                if (ImGui::Checkbox("##hidepausebutton", &hidePauseButtonEnabled)) {
                    Mod::get()->setSavedValue("hide-pause-button-enabled", hidePauseButtonEnabled);                
                }
                
                ImGui::Text("layout mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##layoutmode", &layoutModeEnabled)) {
                    Mod::get()->setSavedValue("layout-mode-enabled", layoutModeEnabled);
                }
                
                ImGui::Text("comment history bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##commenthistorybypass", &commentHistoryBypassEnabled)) {
                    Mod::get()->setSavedValue("comment-history-bypass", commentHistoryBypassEnabled);
                }
                
                ImGui::Text("auto practice");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autopractice", &autoPracticeEnabled)) {
                    Mod::get()->setSavedValue("auto-practice-enabled", autoPracticeEnabled);
                }
                
                ImGui::Text("icon hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##iconhack", &iconHackEnabled)) {
                    Mod::get()->setSavedValue("icon-hack-enabled", iconHackEnabled);
                }
                
                ImGui::Text("color hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##colorhack", &colorHackEnabled)) {
                    Mod::get()->setSavedValue("color-hack-enabled", colorHackEnabled);
                }
                
                ImGui::Text("no solids");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nosolids", &noSolidsEnabled)) {
                    Mod::get()->setSavedValue("no-solids-enabled", noSolidsEnabled);
                }
                
                ImGui::Text("suicide");
                ImGui::SameLine();
                if (ImGui::Checkbox("##suicide", &suicideEnabled)) {
                    Mod::get()->setSavedValue("suicide-enabled", suicideEnabled);
                }
                
                ImGui::Text("show hitboxes");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxes", &showHitboxesEnabled)) {
                    Mod::get()->setSavedValue("show-hitboxes-enabled", showHitboxesEnabled);
                }
                
                ImGui::Text("show hitboxes on death");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxesondeath", &showHitboxesOnDeathEnabled)) {
                    Mod::get()->setSavedValue("show-hitboxes-on-death-enabled", showHitboxesOnDeathEnabled);
                }
                
                ImGui::Text("rainbow icons");
                ImGui::SameLine();
                if (ImGui::Checkbox("##rainbowicons", &rainbowIconsEnabled)) {
                    Mod::get()->setSavedValue("raindow-icons-enabled", rainbowIconsEnabled);
                }
                
                ImGui::Text("everything kills you");
                ImGui::SameLine();
                if (ImGui::Checkbox("##everythingkillsyou", &everythingKillsYouEnabled)) {
                    Mod::get()->setSavedValue("everything-kills-you", everythingKillsYouEnabled);
                }
                
                ImGui::Text("safe mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##safemode", &safeModeEnabled)) {
                    Mod::get()->setSavedValue("safe-mode-enabled", safeModeEnabled);
                }
                
                ImGui::Text("instant complete");
                ImGui::SameLine();
                if (ImGui::Checkbox("##instantcomplete", &instantCompleteEnabled)) {
                    Mod::get()->setSavedValue("instant-complete-enabled", instantCompleteEnabled);
                }
                
                ImGui::Text("basement bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##basementbypass", &basementBypassEnabled)) {
                    Mod::get()->setSavedValue("basement-bypass-enabled", basementBypassEnabled);
                }
                
                ImGui::Text("level edit");
                ImGui::SameLine();
                if (ImGui::Checkbox("##leveledit", &levelEditEnabled)) {
                    Mod::get()->setSavedValue("level-edit-enabled", levelEditEnabled);
                }
                
                ImGui::Text("main level bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##mainlevelbypass", &mainLevelBypassEnabled)) {
                    Mod::get()->setSavedValue("main-level-bypass-enabled", mainLevelBypassEnabled);
                }

                ImGui::Text("No Wave Pulse");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noWavePulse", &noWavePulse)) {
                     Mod::get()->getSavedValue<bool>("noWavePulse", noWavePulse);
                }

                ImGui::Text("tower bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##towerbypass", &towerBypassEnabled)) {
                    Mod::get()->setSavedValue("tower-bypass-enabled", towerBypassEnabled);
                }

                ImGui::Text("Solid Wave Trail");
                ImGui::SameLine();
                if (ImGui::Checkbox("##solidwavetrail", &SolidWave)) {
                    Mod::get()->getSavedValue("SolidWave", SolidWave);
                }
                
                ImGui::Text("no glow");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noglow", &noGlowEnabled)) {
                    Mod::get()->setSavedValue("no-glow-enabled", noGlowEnabled);
                }
                
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Editor")) {
                ImGui::Text("verify hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##verifyhack", &verifyHackEnabled)) {
                    Mod::get()->setSavedValue("verify-hack-enabled", verifyHackEnabled);
                }
                
                ImGui::Text("copy hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##copyhack", &copyHackEnabled)) {
                    Mod::get()->setSavedValue("copy-hack-enabled", copyHackEnabled);
                }
                
                ImGui::Text("no c mark");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nocmark", &noCMarkEnabled)) {
                    Mod::get()->setSavedValue("no-c-mark-enabled", noCMarkEnabled);
                }
                
                ImGui::Text("custom objects bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##customobjectsbypass", &customObjectsBypassEnabled)) {
                    Mod::get()->setSavedValue("custom-object-bypass", customObjectsBypassEnabled);
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Player")) {
                ImGui::Text("noclip");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noclip", &noclipEnabled)) {
                    Mod::get()->setSavedValue("noclip-enabled", noclipEnabled);
                }
                
                ImGui::Text("ignore inputs");
                ImGui::SameLine();
                if (ImGui::Checkbox("##ignoreinputs", &ignoreInputsEnabled)) {
                    Mod::get()->setSavedValue("ignore-inputs-enabled", ignoreInputsEnabled);
                }
                
                ImGui::Text("jump hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##jumphack", &jumpHackEnabled)) {
                    Mod::get()->setSavedValue("jump-hack-enabled", jumpHackEnabled);
                }
                
                ImGui::Text("autoclicker");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autoclicker", &autoclickerEnabled)) {
                    Mod::get()->setSavedValue("auto-clicker-enabled", autoclickerEnabled);
                }
                ImGui::EndTabItem();
            }
                
            if (ImGui::BeginTabItem("Credits")) {
                ImGui::Text("gtxx9003, Developer, Features, more..");
                ImGui::Text("Mystical433, Leader Developer, Features, ui, more...");
                ImGui::Text("Speedyfriend67, Developer, Bug fixes");
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Info")) {
                ImGui::Text("Polo version v1.0.0");
                ImGui::Text("Nightly Release: ");
                ImGui::SameLine();
                ImGui::Text("False");
                
                ImGui::Separator();
                
                if (ImGui::Button("Export Settings")) {}
                ImGui::SameLine();
                if (ImGui::Button("Load Settings")) {}
                
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
    });
}



#ifndef GEODE_IS_IOS
#include <Geode/modify/CCKeyboardDispatcher.hpp>
class $modify(ImGuiKeybindHook, cocos2d::CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
        if (key == cocos2d::enumKeyCodes::KEY_Tab && isKeyDown) {
            ImGuiCocos::get().toggle();
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
    }
};
#endif
