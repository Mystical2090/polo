#include <imgui_internal.h>
#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
// dam optimization god gtxx9903
using namespace geode::prelude;

// player
bool noclipEnabled = Mod::get()->getSavedValue<bool>("noclip-enabled", false);
bool ignoreInputsEnabled = Mod::get()->getSavedValue<bool>("ignore-inputs-enabled", false);
bool jumpHackEnabled = Mod::get()->getSavedValue<bool>("jump-hack-enabled", false);
bool autoclickerEnabled = Mod::get()->getSavedValue<bool>("auto-clicker-enabled", false);

// editor
bool verifyHackEnabled = Mod::get()->getSavedValue<bool>("verify-hack-enabled", false);
bool copyHackEnabled = Mod::get()->getSavedValue<bool>("copy-hack-enabled", false);
bool noCMarkEnabled = Mod::get()->getSavedValue<bool>("no-c-mark-enabled", false);
bool customObjectsBypassEnabled = Mod::get()->getSavedValue<bool>("custom-objects-bypass-enabled", false);

// misc
float speedhackValue = Mod::get()->getSavedValue<float>("speedhack-value", 1.0f);
float noWavePulseValue = Mod::get()->getSavedValue<float>("no-wave-pulse-value", 1.0f);
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

static int currentTheme = Mod::get()->getSavedValue<int>("theme", 3);
const char* themes[] = { "Dark", "Light", "Classic", "Default" };

// Splitter state
static float splitter_pos = 300.0f; // Initial position of the splitter

// Vertical splitter function
bool VerticalSplitter(const char* str_id, float* left_width, float min_left_width = 50.0f, float min_right_width = 50.0f, float thickness = 4.0f)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *ImGui::GetCurrentContext();
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(str_id);

    ImVec2 avail = ImGui::GetContentRegionAvail();
    ImVec2 cursor_pos = ImGui::GetCursorScreenPos();
    
    // Clamp the left width
    float max_left_width = avail.x - min_right_width - thickness;
    *left_width = ImClamp(*left_width, min_left_width, max_left_width);
    
    // Splitter button area
    ImRect splitter_rect;
    splitter_rect.Min = ImVec2(cursor_pos.x + *left_width, cursor_pos.y);
    splitter_rect.Max = ImVec2(cursor_pos.x + *left_width + thickness, cursor_pos.y + avail.y);

    ImGui::ButtonBehavior(splitter_rect, id, nullptr, nullptr);
    bool hovered = ImGui::IsItemHovered();
    bool held = ImGui::IsItemActive();

    if (held || hovered)
        ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeEW);

    if (held && ImGui::IsMouseDragging(ImGuiMouseButton_Left))
    {
        *left_width += g.IO.MouseDelta.x;
        *left_width = ImClamp(*left_width, min_left_width, max_left_width);
    }

    // Draw the splitter
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImU32 col = ImGui::GetColorU32(held ? ImGuiCol_SeparatorActive : hovered ? ImGuiCol_SeparatorHovered : ImGuiCol_Separator);
    draw_list->AddRectFilled(splitter_rect.Min, splitter_rect.Max, col);

    return held;
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
        
        // Get the available region for the splitter layout
        ImVec2 avail = ImGui::GetContentRegionAvail();
        
        // Left panel (Tab bar content)
        if (ImGui::BeginChild("LeftPanel", ImVec2(splitter_pos, avail.y), true, ImGuiWindowFlags_NoScrollbar)) {
            if (ImGui::BeginTabBar("Polo", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_FittingPolicyScroll)) {
                
                // Player Features
                if (ImGui::BeginTabItem("Noclip")) {
                    if (ImGui::Checkbox("Enable Noclip", &noclipEnabled)) {
                        Mod::get()->setSavedValue("noclip-enabled", noclipEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Ignore Inputs")) {
                    if (ImGui::Checkbox("Enable Ignore Inputs", &ignoreInputsEnabled)) {
                        Mod::get()->setSavedValue("ignore-inputs-enabled", ignoreInputsEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Jump Hack")) {
                    if (ImGui::Checkbox("Enable Jump Hack", &jumpHackEnabled)) {
                        Mod::get()->setSavedValue("jump-hack-enabled", jumpHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Autoclicker")) {
                    if (ImGui::Checkbox("Enable Autoclicker", &autoclickerEnabled)) {
                        Mod::get()->setSavedValue("auto-clicker-enabled", autoclickerEnabled);
                    }
                    ImGui::EndTabItem();
                }

                // Editor Features
                if (ImGui::BeginTabItem("Verify Hack")) {
                    if (ImGui::Checkbox("Enable Verify Hack", &verifyHackEnabled)) {
                        Mod::get()->setSavedValue("verify-hack-enabled", verifyHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Copy Hack")) {
                    if (ImGui::Checkbox("Enable Copy Hack", &copyHackEnabled)) {
                        Mod::get()->setSavedValue("copy-hack-enabled", copyHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("No C Mark")) {
                    if (ImGui::Checkbox("Enable No C Mark", &noCMarkEnabled)) {
                        Mod::get()->setSavedValue("no-c-mark-enabled", noCMarkEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Custom Objects")) {
                    if (ImGui::Checkbox("Enable Custom Objects Bypass", &customObjectsBypassEnabled)) {
                        Mod::get()->setSavedValue("custom-objects-bypass-enabled", customObjectsBypassEnabled);
                    }
                    ImGui::EndTabItem();
                }

                // Misc Features
                if (ImGui::BeginTabItem("Speedhack")) {
                    ImGui::Text("Speedhack Value:");
                    if (ImGui::SliderFloat("##Speedhack", &speedhackValue, 0.00001f, 50.0f)) {
                        Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Wave Pulse")) {
                    ImGui::Text("No Wave Pulse Value:");
                    if (ImGui::SliderFloat("##nowavepulse", &noWavePulseValue, 0.00001f, 50.0f)) {
                        Mod::get()->setSavedValue("no-wave-pulse-value", noWavePulseValue);
                    }
                    ImGui::Separator();
                    if (ImGui::Checkbox("No Wave Pulse", &noWavePulse)) {
                         Mod::get()->setSavedValue("noWavePulse", noWavePulse);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Practice Music")) {
                    if (ImGui::Checkbox("Enable Practice Music Hack", &practiceMusicHackEnabled)) {
                        Mod::get()->setSavedValue("practice-music-hack-enabled", practiceMusicHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Hide Pause")) {
                    if (ImGui::Checkbox("Hide Pause Button", &hidePauseButtonEnabled)) {
                        Mod::get()->setSavedValue("hide-pause-button-enabled", hidePauseButtonEnabled);                
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Layout Mode")) {
                    if (ImGui::Checkbox("Enable Layout Mode", &layoutModeEnabled)) {
                        Mod::get()->setSavedValue("layout-mode-enabled", layoutModeEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Comment History")) {
                    if (ImGui::Checkbox("Enable Comment History Bypass", &commentHistoryBypassEnabled)) {
                        Mod::get()->setSavedValue("comment-history-bypass-enabled", commentHistoryBypassEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Auto Practice")) {
                    if (ImGui::Checkbox("Enable Auto Practice", &autoPracticeEnabled)) {
                        Mod::get()->setSavedValue("auto-practice-enabled", autoPracticeEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Icon Hack")) {
                    if (ImGui::Checkbox("Enable Icon Hack", &iconHackEnabled)) {
                        Mod::get()->setSavedValue("icon-hack-enabled", iconHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Color Hack")) {
                    if (ImGui::Checkbox("Enable Color Hack", &colorHackEnabled)) {
                        Mod::get()->setSavedValue("color-hack-enabled", colorHackEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("No Solids")) {
                    if (ImGui::Checkbox("Enable No Solids", &noSolidsEnabled)) {
                        Mod::get()->setSavedValue("no-solids-enabled", noSolidsEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Suicide")) {
                    if (ImGui::Checkbox("Enable Suicide", &suicideEnabled)) {
                        Mod::get()->setSavedValue("suicide-enabled", suicideEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Show Hitboxes")) {
                    if (ImGui::Checkbox("Enable Show Hitboxes", &showHitboxesEnabled)) {
                        Mod::get()->setSavedValue("show-hitboxes-enabled", showHitboxesEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Hitboxes on Death")) {
                    if (ImGui::Checkbox("Show Hitboxes on Death", &showHitboxesOnDeathEnabled)) {
                        Mod::get()->setSavedValue("show-hitboxes-on-death-enabled", showHitboxesOnDeathEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Rainbow Icons")) {
                    if (ImGui::Checkbox("Enable Rainbow Icons", &rainbowIconsEnabled)) {
                        Mod::get()->setSavedValue("rainbow-icons-enabled", rainbowIconsEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Everything Kills")) {
                    if (ImGui::Checkbox("Everything Kills You", &everythingKillsYouEnabled)) {
                        Mod::get()->setSavedValue("everything-kills-you-enabled", everythingKillsYouEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Safe Mode")) {
                    if (ImGui::Checkbox("Enable Safe Mode", &safeModeEnabled)) {
                        Mod::get()->setSavedValue("safe-mode-enabled", safeModeEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Instant Complete")) {
                    if (ImGui::Checkbox("Enable Instant Complete", &instantCompleteEnabled)) {
                        Mod::get()->setSavedValue("instant-complete-enabled", instantCompleteEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Basement Bypass")) {
                    if (ImGui::Checkbox("Enable Basement Bypass", &basementBypassEnabled)) {
                        Mod::get()->setSavedValue("basement-bypass-enabled", basementBypassEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Level Edit")) {
                    if (ImGui::Checkbox("Enable Level Edit Bypass", &levelEditEnabled)) {
                        Mod::get()->setSavedValue("level-edit-bypass-enabled", levelEditEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Main Level Bypass")) {
                    if (ImGui::Checkbox("Enable Main Level Bypass", &mainLevelBypassEnabled)) {
                        Mod::get()->setSavedValue("main-level-bypass-enabled", mainLevelBypassEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Tower Bypass")) {
                    if (ImGui::Checkbox("Enable Tower Bypass", &towerBypassEnabled)) {
                        Mod::get()->setSavedValue("tower-bypass-enabled", towerBypassEnabled);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Solid Wave Trail")) {
                    if (ImGui::Checkbox("Enable Solid Wave Trail", &SolidWave)) {
                        Mod::get()->setSavedValue("SolidWave", SolidWave);
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("No Glow")) {
                    if (ImGui::Checkbox("Enable No Glow", &noGlowEnabled)) {
                        Mod::get()->setSavedValue("no-glow-enabled", noGlowEnabled);
                    }
                    ImGui::EndTabItem();
                }

                // Credits tab
                if (ImGui::BeginTabItem("Credits")) {
                    ImGui::Text("gtxx9003, Developer, Features, more..");
                    ImGui::Text("Mystical433, Leader Developer, Features, ui, more...");
                    ImGui::Text("Speedyfriend67, Developer, Bug fixes");
                    ImGui::EndTabItem();
                }

                // Info tab
                if (ImGui::BeginTabItem("Info")) {
                    ImGui::Text("Polo version v1.0.0");
                if (ImGui::BeginTabItem("Info")) {
                    ImGui::SameLine();
                    ImGui::Text("False");
                    
                    ImGui::Separator();
                    
                    if (ImGui::Button("Export Settings")) {}
                    ImGui::SameLine();
                    if (ImGui::Button("Load Settings")) {}
                    
                    ImGui::Separator();
                    
                    ImGui::Text("Theme:");
                    ImGui::SameLine();
                    if (ImGui::Combo("##theme", &currentTheme, themes, IM_ARRAYSIZE(themes))) {
                        Mod::get()->setSavedValue("theme", currentTheme);
                    }
                    
                    ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
            }
        }
        ImGui::EndChild();

        ImGui::SameLine();
        VerticalSplitter("##splitter", &splitter_pos);
        ImGui::SameLine();

        if (ImGui::BeginChild("Polo", ImVec2(0, avail.y), true)) {
            ImGui::Text("Donate to use!");
            ImGui::Separator();
        }
        ImGui::EndChild();
        
        ImGui::End();
        });
    })
}
