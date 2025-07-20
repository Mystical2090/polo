
#include <imgui_internal.h>
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
            if (ImGui::BeginTabBar("Polo")) {
                if (ImGui::BeginTabItem("Misc")) {
                    ImGui::Text("speedhack");
                    ImGui::SameLine();

                    if (ImGui::SliderFloat("##Speedhack", &speedhackValue, 0.00001f, 50.0f)) {
                        Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                    }
                    
                    ImGui::Text("no wave pulse");
                    ImGui::SameLine();

                    if (ImGui::SliderFloat("##nowavepulse", &noWavePulseValue, 0.00001f, 50.0f)) {
                        Mod::get()->setSavedValue("no-wave-pulse-value", noWavePulseValue);
                    }
                    
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
