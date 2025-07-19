#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
// dam optimization god gtxx9903
using namespace geode::prelude;

bool noclipEnabled = Mod::get()->getSavedValue<bool>("noclip-enabled", false);
bool ignoreInputsEnabled = Mod::get()->getSavedValue<bool>("ignore-inputs-enabled", false);
bool jumpHackEnabled = Mod::get()->getSavedValue<bool>("jump-hack-enabled", false);
bool autoclickerEnabled = Mod::get()->getSavedValue<bool>("auto-clicker-enabled", false);

bool verifyHackEnabled = Mod::get()->getSavedValue<bool>("verify-hack-enabled", false);
bool copyHackEnabled = Mod::get()->getSavedValue<bool>("copy-hack-enabled", false);
bool noCMarkEnabled = Mod::get()->getSavedValue<bool>("no-c-mark-enabled", false);
bool customObjectsBypassEnabled = Mod::get()->getSavedValue<bool>("custom-objects-bypass-enabled", false);

bool practiceMusicHackEnabled = Mod::get()->getSavedValue<bool>("practice-music-hack-enabled", false);
bool layoutModeEnabled = Mod::get()->getSavedValue<bool>("layout-mode-enabled", false);
bool autoPracticeEnabled = Mod::get()->getSavedValue<bool>("auto-practice-enabled", false);
bool safeModeEnabled = Mod::get()->getSavedValue<bool>("safe-mode-enabled", false);
bool instantCompleteEnabled = Mod::get()->getSavedValue<bool>("instant-complete-enabled", false);

bool commentHistoryBypassEnabled = Mod::get()->getSavedValue<bool>("comment-history-bypass-enabled", false);
bool basementBypassEnabled = Mod::get()->getSavedValue<bool>("basement-bypass-enabled", false);
bool levelEditEnabled = Mod::get()->getSavedValue<bool>("level-edit-bypass-enabled", false);
bool mainLevelBypassEnabled = Mod::get()->getSavedValue<bool>("main-level-bypass-enabled", false);
bool towerBypassEnabled = Mod::get()->getSavedValue<bool>("tower-bypass-enabled", false);

bool iconHackEnabled = Mod::get()->getSavedValue<bool>("icon-hack-enabled", false);
bool colorHackEnabled = Mod::get()->getSavedValue<bool>("color-hack-enabled", false);
bool noSolidsEnabled = Mod::get()->getSavedValue<bool>("no-solids-enabled", false);
bool showHitboxesEnabled = Mod::get()->getSavedValue<bool>("show-hitboxes-enabled", false);
bool showHitboxesOnDeathEnabled = Mod::get()->getSavedValue<bool>("show-hitboxes-on-death-enabled", false);
bool rainbowIconsEnabled = Mod::get()->getSavedValue<bool>("rainbow-icons-enabled", false);
bool noGlowEnabled = Mod::get()->getSavedValue<bool>("no-glow-enabled", false);
bool SolidWave = Mod::get()->getSavedValue<bool>("SolidWave", false);

float speedhackValue = Mod::get()->getSavedValue<float>("speedhack-value", 1.0f);
float noWavePulseValue = Mod::get()->getSavedValue<float>("no-wave-pulse-value", 1.0f);
bool hidePauseButtonEnabled = Mod::get()->getSavedValue<bool>("hide-pause-button-enabled", false);
bool suicideEnabled = Mod::get()->getSavedValue<bool>("suicide-enabled", false);
bool everythingKillsYouEnabled = Mod::get()->getSavedValue<bool>("everything-kills-you-enabled", false);
bool noWavePulse = Mod::get()->getSavedValue<bool>("noWavePulse", false);

static int currentTheme = Mod::get()->getSavedValue<int>("theme", 3);
const char* themes[] = { "Dark", "Light", "Classic", "Default" };

bool ToggleButton(const char* label, bool* enabled) {
    ImVec4 activeColor = ImVec4(0.2f, 0.7f, 0.2f, 1.0f);
    ImVec4 inactiveColor = ImVec4(0.7f, 0.2f, 0.2f, 1.0f);
    
    ImGui::PushStyleColor(ImGuiCol_Button, *enabled ? activeColor : inactiveColor);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, *enabled ? ImVec4(0.3f, 0.8f, 0.3f, 1.0f) : ImVec4(0.8f, 0.3f, 0.3f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, *enabled ? ImVec4(0.1f, 0.6f, 0.1f, 1.0f) : ImVec4(0.6f, 0.1f, 0.1f, 1.0f));
    
    bool clicked = ImGui::Button(label, ImVec2(-1, 0));
    if (clicked) {
        *enabled = !*enabled;
    }
    
    ImGui::PopStyleColor(3);
    return clicked;
}

$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        ImGuiIO& io = ImGui::GetIO();
        
        ImFont* customFont = io.Fonts->AddFontFromFileTTF((Mod::get()->getResourcesDir() / "OpenSans-Regural.ttf").string().c_str(), 18.0f);
        io.FontDefault = customFont;
        
        switch (currentTheme) {
            case 0:
                ImGui::StyleColorsDark();
                break;
            case 1:
                ImGui::StyleColorsLight();
                break;
            case 2:
                ImGui::StyleColorsClassic();
                break;
            case 3: {
                ImGui::StyleColorsDark();
                ImGuiStyle& style = ImGui::GetStyle();
                
                style.Alpha = 1.0f;
                style.DisabledAlpha = 0.4f;
                style.WindowPadding = ImVec2(8.0f, 8.0f);
                style.WindowRounding = 8.0f;
                style.WindowBorderSize = 1.0f;
                style.WindowMinSize = ImVec2(32.0f, 32.0f);
                style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
                style.WindowMenuButtonPosition = ImGuiDir_Left;
                style.ChildRounding = 5.5f;
                style.ChildBorderSize = 1.0f;
                style.PopupRounding = 5.5f;
                style.PopupBorderSize = 1.0f;
                style.FramePadding = ImVec2(6.0f, 3.0f);
                style.FrameRounding = 5.0f;
                style.FrameBorderSize = 0.0f;
                style.ItemSpacing = ImVec2(4.5f, 4.0f);
                style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
                style.CellPadding = ImVec2(2.0f, 2.0f);
                style.IndentSpacing = 6.5f;
                style.ColumnsMinSpacing = 6.0f;
                style.ScrollbarSize = 11.0f;
                style.ScrollbarRounding = 10.0f;
                style.GrabMinSize = 8.5f;
                style.GrabRounding = 4.5f;
                style.TabRounding = 9.0f;
                style.TabBorderSize = 1.0f;
                style.ColorButtonPosition = ImGuiDir_Right;
                style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
                style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
                            
                style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
                style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.498f, 0.498f, 0.498f, 1.0f);
                style.Colors[ImGuiCol_WindowBg] = ImVec4(0.0588f, 0.0588f, 0.0588f, 0.94f);
                style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784f, 0.0784f, 0.0784f, 0.94f);
                style.Colors[ImGuiCol_Border] = ImVec4(0.636f, 0.636f, 0.682f, 0.5f);
                style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                style.Colors[ImGuiCol_FrameBg] = ImVec4(0.198f, 0.223f, 0.249f, 0.54f);
                style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.416f, 0.423f, 0.429f, 0.4f);
                style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.365f, 0.365f, 0.365f, 0.67f);
                style.Colors[ImGuiCol_TitleBg] = ImVec4(0.039f, 0.039f, 0.039f, 1.0f);
                style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
                style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.51f);
                style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.137f, 0.136f, 0.136f, 0.69f);
                style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53);
                style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.0f);
                style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.0f);
                style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.0f);
                style.Colors[ImGuiCol_CheckMark] = ImVec4(0.97f, 0.99f, 1.0f, 1.0f);
                style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.657f, 0.657f, 0.657f, 1.0f);
                style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
                style.Colors[ImGuiCol_Button] = ImVec4(0.59f, 0.63f, 0.67f, 0.4f);
                style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.43f, 0.43f, 1.0f);
                style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.53f, 0.53f, 0.53f, 1.0f);
                style.Colors[ImGuiCol_Header] = ImVec4(0.45f, 0.51f, 0.57f, 0.31f);
                style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.36f, 0.36f, 0.36f, 0.8f);
                style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.34f, 0.34f, 0.34f, 0.45f);
                style.Colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.5f, 0.5f);
                style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.4f, 0.4f, 0.4f, 0.78f);
                style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.27f, 0.27f, 1.0f);
                style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.48f, 0.48f, 0.48f, 0.2f);
                style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.59f, 0.59f, 0.59f, 0.67f);
                style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.31f, 0.32f, 0.32f, 0.8f);
                style.Colors[ImGuiCol_Tab] = ImVec4(0.34f, 0.34f, 0.34f, 0.26f);
                style.Colors[ImGuiCol_TabHovered] = ImVec4(0.4f, 0.41f, 0.41f, 0.53f);
                style.Colors[ImGuiCol_TabActive] = ImVec4(0.42f, 0.42f, 0.42f, 0.63f);
                style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.19f, 0.19f, 0.19f, 0.97f);
                style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.12f, 0.12f, 0.12f, 1.0f);
                style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.0f);
                style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.43f, 0.35f, 1.0f);
                style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.9f, 0.7f, 0.0f, 1.0f);
                style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
                style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.2f, 1.0f);
                style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.0f);
                style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.0f);
                style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.06f);
                style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.176f, 0.176f, 0.176f, 0.35f);
                style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.9f);
                style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.193f, 0.193f, 0.193f, 0.78f);
                style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.7f);
                style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.8f, 0.8f, 0.8f, 0.2f);
                style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.8f, 0.8f, 0.8f, 0.35f);
                break;
            }
        }
    }).draw([] {
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        
        if (ImGui::BeginTabBar("Polo", ImGuiTabBarFlags_TabListPopupButton)) {
            if (ImGui::BeginTabItem("Player")) {
                if (ToggleButton("Noclip", &noclipEnabled)) {
                    Mod::get()->setSavedValue("noclip-enabled", noclipEnabled);
                }
                
                if (ToggleButton("Ignore Inputs", &ignoreInputsEnabled)) {
                    Mod::get()->setSavedValue("ignore-inputs-enabled", ignoreInputsEnabled);
                }
                
                if (ToggleButton("Jump Hack", &jumpHackEnabled)) {
                    Mod::get()->setSavedValue("jump-hack-enabled", jumpHackEnabled);
                }
                
                if (ToggleButton("Auto Clicker", &autoclickerEnabled)) {
                    Mod::get()->setSavedValue("auto-clicker-enabled", autoclickerEnabled);
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Creator")) {
                if (ToggleButton("Verify Hack", &verifyHackEnabled)) {
                    Mod::get()->setSavedValue("verify-hack-enabled", verifyHackEnabled);
                }
                
                if (ToggleButton("Copy Hack", &copyHackEnabled)) {
                    Mod::get()->setSavedValue("copy-hack-enabled", copyHackEnabled);
                }
                
                if (ToggleButton("No C Mark", &noCMarkEnabled)) {
                    Mod::get()->setSavedValue("no-c-mark-enabled", noCMarkEnabled);
                }
                
                if (ToggleButton("Custom Objects Bypass", &customObjectsBypassEnabled)) {
                    Mod::get()->setSavedValue("custom-objects-bypass-enabled", customObjectsBypassEnabled);
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Level")) {
                if (ToggleButton("Practice Music Hack", &practiceMusicHackEnabled)) {
                    Mod::get()->setSavedValue("practice-music-hack-enabled", practiceMusicHackEnabled);
                }
                
                if (ToggleButton("Layout Mode", &layoutModeEnabled)) {
                    Mod::get()->setSavedValue("layout-mode-enabled", layoutModeEnabled);
                }
                
                if (ToggleButton("Auto Practice", &autoPracticeEnabled)) {
                    Mod::get()->setSavedValue("auto-practice-enabled", autoPracticeEnabled);
                }
                
                if (ToggleButton("Safe Mode", &safeModeEnabled)) {
                    Mod::get()->setSavedValue("safe-mode-enabled", safeModeEnabled);
                }
                
                if (ToggleButton("Instant Complete", &instantCompleteEnabled)) {
                    Mod::get()->setSavedValue("instant-complete-enabled", instantCompleteEnabled);
                }
                
                ImGui::EndTabItem();
            }

            // Universal Tab
            if (ImGui::BeginTabItem("Universal")) {
                if (ToggleButton("Comment History Bypass", &commentHistoryBypassEnabled)) {
                    Mod::get()->setSavedValue("comment-history-bypass-enabled", commentHistoryBypassEnabled);
                }
                
                if (ToggleButton("Basement Bypass", &basementBypassEnabled)) {
                    Mod::get()->setSavedValue("basement-bypass-enabled", basementBypassEnabled);
                }
                
                if (ToggleButton("Level Edit Bypass", &levelEditEnabled)) {
                    Mod::get()->setSavedValue("level-edit-bypass-enabled", levelEditEnabled);
                }
                
                if (ToggleButton("Main Level Bypass", &mainLevelBypassEnabled)) {
                    Mod::get()->setSavedValue("main-level-bypass-enabled", mainLevelBypassEnabled);
                }
                
                if (ToggleButton("Tower Bypass", &towerBypassEnabled)) {
                    Mod::get()->setSavedValue("tower-bypass-enabled", towerBypassEnabled);
                }
                
                ImGui::EndTabItem();
            }

            // Visual Tab
            if (ImGui::BeginTabItem("Visual")) {
                if (ToggleButton("Icon Hack", &iconHackEnabled)) {
                    Mod::get()->setSavedValue("icon-hack-enabled", iconHackEnabled);
                }
                
                if (ToggleButton("Color Hack", &colorHackEnabled)) {
                    Mod::get()->setSavedValue("color-hack-enabled", colorHackEnabled);
                }
                
                if (ToggleButton("No Solids", &noSolidsEnabled)) {
                    Mod::get()->setSavedValue("no-solids-enabled", noSolidsEnabled);
                }
                
                if (ToggleButton("Show Hitboxes", &showHitboxesEnabled)) {
                    Mod::get()->setSavedValue("show-hitboxes-enabled", showHitboxesEnabled);
                }
                
                if (ToggleButton("Show Hitboxes On Death", &showHitboxesOnDeathEnabled)) {
                    Mod::get()->setSavedValue("show-hitboxes-on-death-enabled", showHitboxesOnDeathEnabled);
                }
                
                if (ToggleButton("Rainbow Icons", &rainbowIconsEnabled)) {
                    Mod::get()->setSavedValue("rainbow-icons-enabled", rainbowIconsEnabled);
                }
                
                if (ToggleButton("No Glow", &noGlowEnabled)) {
                    Mod::get()->setSavedValue("no-glow-enabled", noGlowEnabled);
                }
                
                if (ToggleButton("Solid Wave Trail", &SolidWave)) {
                    Mod::get()->setSavedValue("SolidWave", SolidWave);
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Config")) {
                ImGui::Text("Speedhack");
                if (ImGui::SliderFloat("##Speedhack", &speedhackValue, 0.00001f, 50.0f)) {
                    Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                }
                
                ImGui::Text("No Wave Pulse Value");
                if (ImGui::SliderFloat("##nowavepulse", &noWavePulseValue, 0.00001f, 50.0f)) {
                    Mod::get()->setSavedValue("no-wave-pulse-value", noWavePulseValue);
                }
                
                if (ToggleButton("Hide Pause Button", &hidePauseButtonEnabled)) {
                    Mod::get()->setSavedValue("hide-pause-button-enabled", hidePauseButtonEnabled);
                }
                
                if (ToggleButton("Suicide", &suicideEnabled)) {
                    Mod::get()->setSavedValue("suicide-enabled", suicideEnabled);
                }
                
                if (ToggleButton("Everything Kills You", &everythingKillsYouEnabled)) {
                    Mod::get()->setSavedValue("everything-kills-you-enabled", everythingKillsYouEnabled);
                }
                
                if (ToggleButton("No Wave Pulse", &noWavePulse)) {
                    Mod::get()->setSavedValue("noWavePulse", noWavePulse);
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Credits")) {
                ImGui::Text("gtxx9003, Developer, Features, more..");
                ImGui::Text("Mystical433, Leader Developer, Features, ui, more...");
                ImGui::Text("Speedyfriend67, Developer, Bug fixes");
                ImGui::EndTabItem();
            }

            // Info Tab
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

            if (ImGui::BeginTabItem("Settings")) {
                if (ImGui::Combo("Theme", &currentTheme, themes, IM_ARRAYSIZE(themes))) {
                    Mod::get()->setSavedValue("theme", currentTheme);

                    switch (currentTheme) {
                        case 0: ImGui::StyleColorsDark(); break;
                        case 1: ImGui::StyleColorsLight(); break;
                        case 2: ImGui::StyleColorsClassic(); break;
                        case 3: {
                            ImGui::StyleColorsDark();
                            ImGuiStyle& style = ImGui::GetStyle();
                            // Apply custom theme styling...
                            break;
                        }
                    }
                }
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
