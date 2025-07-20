#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <imgui-cocos.hpp>
#include <vector>
#include <string>
#include <map>

using namespace geode::prelude;

namespace PoloColors {
    const ImVec4 Background = ImVec4(0.08f, 0.08f, 0.12f, 1.0f);
    const ImVec4 WindowBg = ImVec4(0.11f, 0.11f, 0.16f, 1.0f);
    const ImVec4 Header = ImVec4(0.15f, 0.15f, 0.22f, 1.0f);
    const ImVec4 HeaderHovered = ImVec4(0.20f, 0.20f, 0.28f, 1.0f);
    const ImVec4 HeaderActive = ImVec4(0.25f, 0.25f, 0.32f, 1.0f);
    const ImVec4 Button = ImVec4(0.18f, 0.18f, 0.25f, 1.0f);
    const ImVec4 ButtonHovered = ImVec4(0.25f, 0.25f, 0.35f, 1.0f);
    const ImVec4 ButtonActive = ImVec4(0.30f, 0.30f, 0.40f, 1.0f);
    const ImVec4 Frame = ImVec4(0.16f, 0.16f, 0.23f, 1.0f);
    const ImVec4 FrameHovered = ImVec4(0.22f, 0.22f, 0.30f, 1.0f);
    const ImVec4 FrameActive = ImVec4(0.28f, 0.28f, 0.36f, 1.0f);
    const ImVec4 Tab = ImVec4(0.14f, 0.14f, 0.20f, 1.0f);
    const ImVec4 TabHovered = ImVec4(0.22f, 0.22f, 0.30f, 1.0f);
    const ImVec4 TabActive = ImVec4(0.28f, 0.28f, 0.36f, 1.0f);
    const ImVec4 CheckMark = ImVec4(0.40f, 0.80f, 0.40f, 1.0f);
    const ImVec4 SliderGrab = ImVec4(0.35f, 0.70f, 0.35f, 1.0f);
    const ImVec4 SliderGrabActive = ImVec4(0.45f, 0.85f, 0.45f, 1.0f);
    const ImVec4 Text = ImVec4(0.90f, 0.90f, 0.95f, 1.0f);
    const ImVec4 TextDisabled = ImVec4(0.50f, 0.50f, 0.55f, 1.0f);
    const ImVec4 Accent = ImVec4(0.35f, 0.70f, 0.95f, 1.0f);
    const ImVec4 AccentHovered = ImVec4(0.45f, 0.80f, 1.0f, 1.0f);
    const ImVec4 Border = ImVec4(0.25f, 0.25f, 0.32f, 1.0f);
    const ImVec4 Separator = ImVec4(0.20f, 0.20f, 0.28f, 1.0f);
}

namespace PoloState {
// player hacks
    bool noclipEnabled = false;
    bool ignoreInputsEnabled = false;
    bool speedHackEnabled = false;
    bool autoclickerEnabled = false;
    float speedHackMultiplier = 1.0f;
    bool jumpHackEnabled = false;

// creator hacks
    bool copyHackEnabled = false;
    bool customObjectsBypassEnabled = false;
    bool noCMarkEnabled = false;
    bool verifyHackEnabled = false;
// misc hacks!
    bool autoPracticeEnabled = false;
    bool basementBypassEnabled = false;
    bool colorHackEnabled = false;
    bool commentHistoryBypassEnabled = false;
    bool hidePauseButtonEnabled = false;
    bool iconHackEnabled = false;
    bool levelEditEnabled = false;
    bool howHitboxesEnabled = false;
    bool mainLevelBypassEnabled = false;
    bool everythingKillsYouEnabled = false;
    bool instantCompleteEnabled = false;
    bool noGlowEnabled = false;
    bool suicideEnabled = false;
    bool layoutModeEnabled = false;
    bool showHitboxesOnDeathEnabled = false;
    bool safeModeEnabled = false;
    bool practiceMusicHackEnabled = false;
// cosmetic
    bool ForceGhostOn = false;
    bool ForceGhostOff = false;
    bool LongerTrail = false;
    bool NoCameraShake = false;
}

struct HackFeature {
    std::string name;
    bool* enabledPtr; // Pointer to the actual state variable
    std::string description;
    bool hasSlider = false;
    float* sliderValuePtr = nullptr;
    float sliderMin = 0.0f;
    float sliderMax = 10.0f;
};

struct HackCategory {
    std::string name;
    std::vector<HackFeature> features;
    bool expanded = true;
};

class PoloUI {
public:
    std::vector<HackCategory> categories;
    int selectedTab = 0;
    bool showAbout = false;
    bool showSettings = false;
    std::string searchQuery = "";
    char searchBuffer[256] = "";

    PoloUI() {
        initializeHacks();
    }

    void initializeHacks() {
        HackCategory player;
        player.name = "Player";
        player.features = {
            {"Noclip", &PoloState::noclipEnabled, "Pass through objects."},
            {"Ignore Inputs", &PoloState::ignoreInputsEnabled, "Ignore your inputs"},
            {"Jump Hack", &PoloState::jumpHackEnabled, "Infinite Jumps."},
            {"AutoClicker", &PoloState::autoclickerEnabled, "Auto Click(er)"},
        };
        categories.push_back(player);

        HackCategory cosmetic;
        cosmetic.name = "Cosmetic";
        cosmetic.features = {
            {"Force Ghost On", &PoloState::ForceGhostOn, "Hi gtxx :3"},
            {"Force Ghost Off", &PoloState::ForceGhostOff, "Hi speedy :3"},
            {"Longer Trail", &PoloState::LongerTrail, "Hi Mystic :3."},
            {"No Camera Shake", &PoloState::NoCameraShake, "Hi qwerty :3"},
        categories.push_back(cosmetic);

        HackCategory creator;
        creator.name = "Creator";
        creator.features = {
            {"Copy hack", &PoloState::copyHackEnabled, "Hi gtxx :3"},
            {"Custom Object Bypass", &PoloState::customObjectsBypassEnabled, "Hi speedy :3"},
            {"No C mark", &PoloState::noCMarkEnabled, "Hi Mystic :3."},
            {"Verify Hack", &PoloState::verifyHackEnabled, "Hi qwerty :3"},
        };
        categories.push_back(creator);

        HackCategory misc;
        misc.name = "Misc";
        misc.features = {
            {"Auto Practice", &PoloState::autoPracticeEnabled, "Hi gtxx :3"},
            {"Basement bypass", &PoloState::basementBypassEnabled, "Hi speedy :3"},
            {"Color Hack", &PoloState::colorHackEnabled, "Hi Mystic :3."},
            {"Comment History Bypass", &PoloState::commentHistoryBypassEnabled, "Hi qwerty :3"},
            {"Everything Kills you", &PoloState::everythingKillsYouEnabled, "Hi qwerty1234 :3"},
            {"Hide Pause Button", &PoloState::hidePauseButtonEnabled, "Hi qwerty1234 :3"},
            {"Icon Hack", &PoloState::iconHackEnabled, "Hi qwerty :3"},
            {"Instant Complete", &PoloState::instantCompleteEnabled, "Hi qwerty1234 :3"},
            {"Layout Mode", &PoloState::layoutModeEnabled, "Hi qwerty1234 :3"},
            {"Level Edit", &PoloState::levelEditEnabled, "Hi qwerty :3"},
            {"Main Levels Bypass", &PoloState::mainLevelBypassEnabled, "Hi qwerty1234 :3"},
            {"No Glow", &PoloState::noGlowEnabled, "Hi qwerty1234 :3"},
            {"Safe Mode", &PoloState::safeModeEnabled, "Hi qwerty :3"},
            {"Show Hitboxes", &PoloState::showHitboxesEnabled, "Hi qwerty1234 :3"},
            {"Show hitboxes on death", &PoloState::showHitboxesOnDeathEnabled, "Hi qwerty1234 :3"},
            {"Suicide", &PoloState::suicideEnabled, "Hi qwerty1234 :3"},
        };
        categories.push_back(misc);
    }

    void applyPoloStyle() {
        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4* colors = style.Colors;

        colors[ImGuiCol_Text] = PoloColors::Text;
        colors[ImGuiCol_TextDisabled] = PoloColors::TextDisabled;
        colors[ImGuiCol_WindowBg] = PoloColors::WindowBg;
        colors[ImGuiCol_ChildBg] = PoloColors::Background;
        colors[ImGuiCol_PopupBg] = PoloColors::WindowBg;
        colors[ImGuiCol_Border] = PoloColors::Border;
        colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        colors[ImGuiCol_FrameBg] = PoloColors::Frame;
        colors[ImGuiCol_FrameBgHovered] = PoloColors::FrameHovered;
        colors[ImGuiCol_FrameBgActive] = PoloColors::FrameActive;
        colors[ImGuiCol_TitleBg] = PoloColors::Header;
        colors[ImGuiCol_TitleBgActive] = PoloColors::HeaderActive;
        colors[ImGuiCol_TitleBgCollapsed] = PoloColors::Header;
        colors[ImGuiCol_MenuBarBg] = PoloColors::Header;
        colors[ImGuiCol_ScrollbarBg] = PoloColors::Background;
        colors[ImGuiCol_ScrollbarGrab] = PoloColors::Button;
        colors[ImGuiCol_ScrollbarGrabHovered] = PoloColors::ButtonHovered;
        colors[ImGuiCol_ScrollbarGrabActive] = PoloColors::ButtonActive;
        colors[ImGuiCol_CheckMark] = PoloColors::CheckMark;
        colors[ImGuiCol_SliderGrab] = PoloColors::SliderGrab;
        colors[ImGuiCol_SliderGrabActive] = PoloColors::SliderGrabActive;
        colors[ImGuiCol_Button] = PoloColors::Button;
        colors[ImGuiCol_ButtonHovered] = PoloColors::ButtonHovered;
        colors[ImGuiCol_ButtonActive] = PoloColors::ButtonActive;
        colors[ImGuiCol_Header] = PoloColors::Header;
        colors[ImGuiCol_HeaderHovered] = PoloColors::HeaderHovered;
        colors[ImGuiCol_HeaderActive] = PoloColors::HeaderActive;
        colors[ImGuiCol_Separator] = PoloColors::Separator;
        colors[ImGuiCol_SeparatorHovered] = PoloColors::AccentHovered;
        colors[ImGuiCol_SeparatorActive] = PoloColors::Accent;
        colors[ImGuiCol_ResizeGrip] = PoloColors::Button;
        colors[ImGuiCol_ResizeGripHovered] = PoloColors::ButtonHovered;
        colors[ImGuiCol_ResizeGripActive] = PoloColors::ButtonActive;
        colors[ImGuiCol_Tab] = PoloColors::Tab;
        colors[ImGuiCol_TabHovered] = PoloColors::TabHovered;
        colors[ImGuiCol_TabActive] = PoloColors::TabActive;
        colors[ImGuiCol_TabUnfocused] = PoloColors::Tab;
        colors[ImGuiCol_TabUnfocusedActive] = PoloColors::TabActive;
        colors[ImGuiCol_PlotLines] = PoloColors::Accent;
        colors[ImGuiCol_PlotLinesHovered] = PoloColors::AccentHovered;
        colors[ImGuiCol_PlotHistogram] = PoloColors::Accent;
        colors[ImGuiCol_PlotHistogramHovered] = PoloColors::AccentHovered;
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.35f, 0.70f, 0.95f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = PoloColors::AccentHovered;
        colors[ImGuiCol_NavHighlight] = PoloColors::Accent;
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.60f);

        style.WindowPadding = ImVec2(12.0f, 12.0f);
        style.WindowRounding = 8.0f;
        style.WindowBorderSize = 1.0f;
        style.ChildRounding = 6.0f;
        style.PopupRounding = 6.0f;
        style.FramePadding = ImVec2(8.0f, 6.0f);
        style.FrameRounding = 6.0f;
        style.ItemSpacing = ImVec2(8.0f, 6.0f);
        style.ItemInnerSpacing = ImVec2(6.0f, 4.0f);
        style.IndentSpacing = 20.0f;
        style.ScrollbarSize = 16.0f;
        style.ScrollbarRounding = 8.0f;
        style.GrabMinSize = 12.0f;
        style.GrabRounding = 6.0f;
        style.TabRounding = 6.0f;
        style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
        style.SelectableTextAlign = ImVec2(0.0f, 0.5f);
    }

    void render() {
        applyPoloStyle();
        
        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
        
        if (ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_MenuBar)) {
            renderMenuBar();
            renderMainContent();
        }
        ImGui::End();

        if (showAbout) renderAboutWindow();
        if (showSettings) renderSettingsWindow();
    }

private:
    void renderMenuBar() {
        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("Github")) {
                ImGui::Separator();
                if (ImGui::MenuItem("Github", "Press Alt+F4 :3")) {
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Tools")) {
                if (ImGui::MenuItem("Settings")) {
                    showSettings = true;
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help")) {
                if (ImGui::MenuItem("About")) {
                    showAbout = true;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    }

    void renderMainContent() {
        ImGui::PushItemWidth(-1);
        if (ImGui::InputTextWithHint("##search", "Search hacks...", searchBuffer, sizeof(searchBuffer))) {
            searchQuery = std::string(searchBuffer);
        }
        ImGui::PopItemWidth();

        ImGui::Spacing();

        if (ImGui::BeginChild("MainContent", ImVec2(0, 0), false)) {
            if (ImGui::BeginTabBar("HackTabs")) {
                for (size_t i = 0; i < categories.size(); ++i) {
                    if (ImGui::BeginTabItem(categories[i].name.c_str())) {
                        selectedTab = i;
                        renderCategoryContent(categories[i]);
                        ImGui::EndTabItem();
                    }
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::EndChild();
    }

    void renderCategoryContent(HackCategory& category) {
        ImGui::Spacing();

        if (ImGui::Button("Enable All")) {
            for (auto& feature : category.features) {
                if (feature.enabledPtr) {
                    *feature.enabledPtr = true;
                }
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Disable All")) {
            for (auto& feature : category.features) {
                if (feature.enabledPtr) {
                    *feature.enabledPtr = false;
                }
            }
        }

        ImGui::Separator();
        ImGui::Spacing();

        for (auto& feature : category.features) {
            if (!searchQuery.empty() &&
                feature.name.find(searchQuery) == std::string::npos &&
                feature.description.find(searchQuery) == std::string::npos) {
                continue;
            }

            ImGui::PushID(feature.name.c_str());

            bool wasEnabled = feature.enabledPtr ? *feature.enabledPtr : false;
            bool currentEnabled = wasEnabled;
            
            if (ImGui::Checkbox("", &currentEnabled)) {
                if (feature.enabledPtr) {
                    *feature.enabledPtr = currentEnabled;
                    log::info("Feature '{}' {}", feature.name, currentEnabled ? "enabled" : "disabled");
                }
            }

            ImGui::SameLine();
            ImGui::Text("%s", feature.name.c_str());

            if (feature.hasSlider && feature.enabledPtr && *feature.enabledPtr && feature.sliderValuePtr) {
                ImGui::SameLine(0, 50);
                ImGui::PushItemWidth(150);
                ImGui::SliderFloat("##slider", feature.sliderValuePtr, feature.sliderMin, feature.sliderMax, "%.2f");
                ImGui::PopItemWidth();
            }

            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("%s", feature.description.c_str());
            }

            ImGui::PopID();
        }
    }

    void renderAboutWindow() {
        ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("About Polo", &showAbout)) {
            ImGui::TextColored(PoloColors::Accent, "Polo");
            ImGui::Text("Made by Mystical433 & Gtxx9903");
            ImGui::Spacing();
            ImGui::Text("Version: 1.0.0");
            ImGui::Text("Built with: Geode SDK");
            ImGui::Text("UI: Dear ImGui");
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();
            if (ImGui::Button("Close", ImVec2(120, 0))) {
                showAbout = false;
            }
        }
        ImGui::End();
    }

    void renderSettingsWindow() {
        ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("Settings", &showSettings)) {
            if (ImGui::CollapsingHeader("Interface")) {
                static float uiScale = 1.0f;
                ImGui::SliderFloat("UI Scale", &uiScale, 0.5f, 2.0f);
                
                static bool animations = true;
                ImGui::Checkbox("Animations", &animations);
            }
            
            if (ImGui::CollapsingHeader("Keybinds")) {
                ImGui::Text("Toggle Menu: F4");
                if (ImGui::Button("Customize Keybinds")) {
                    // soon™
                }
            }
            
            if (ImGui::CollapsingHeader("Advanced")) {
                static bool debugMode = false;
                ImGui::Checkbox("Debug Mode", &debugMode);
                
                static bool logging = true;
                ImGui::Checkbox("Enable Logging", &logging);
                
                if (ImGui::Button("Reset to Defaults")) {
                    // soon™
                }
            }
            
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            
            if (ImGui::Button("Apply", ImVec2(120, 0))) {
                // soon™
            }
            ImGui::SameLine();
            if (ImGui::Button("Close", ImVec2(120, 0))) {
                showSettings = false;
            }
        }
        ImGui::End();
    }
};

static PoloUI* g_ui = nullptr;

$on_mod(Loaded) {
    g_ui = new PoloUI();
    
    ImGuiCocos::get().setup([]{
        // Setup is handled in render function
    }).draw([]{
        if (g_ui) {
            g_ui->render();
        }
    });
}

#ifndef GEODE_IS_IOS
#include <Geode/modify/CCKeyboardDispatcher.hpp>
class $modify(PoloKeybindHook, cocos2d::CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
        if (key == cocos2d::enumKeyCodes::KEY_F4 && isKeyDown) {
            ImGuiCocos::get().toggle();
        }
        if (key == cocos2d::enumKeyCodes::KEY_F5 && isKeyDown) {
            // Refresh functionality or other keybinds
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
    }
};
#endif
