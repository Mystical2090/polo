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

static int currentTheme = 0;
const char* themes[] = { "Dark", "Light", "Classic" };
$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        ImGuiStyle& style = ImGui::GetStyle();	
        	style.Alpha = 1.0f; // i made this with imTheme okay
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
        	style.TabMinWidthForCloseButton = 0.0f;
        	style.ColorButtonPosition = ImGuiDir_Right;
        	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
        	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
        	
        	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f); // woah what are those numbers i tought that the color picker would round them
        	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 0.9399999976158142f);
        	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
        	style.Colors[ImGuiCol_Border] = ImVec4(0.6355431079864502f, 0.6355460286140442f, 0.6824034452438354f, 0.5f);
        	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1976459473371506f, 0.2228297591209412f, 0.2489270567893982f, 0.5400000214576721f);
        	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.4162905812263489f, 0.4232926666736603f, 0.4291845560073853f, 0.4000000059604645f);
        	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.3648032248020172f, 0.3648051619529724f, 0.3648068904876709f, 0.6700000166893005f);
        	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.03921568766236305f, 0.03921568766236305f, 0.03921568766236305f, 1.0f);
        	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(9.999899930335232e-07f, 9.999952226280584e-07f, 9.999999974752427e-07f, 1.0f);
        	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
        	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1373390555381775f, 0.1355707347393036f, 0.1355707347393036f, 0.6909871101379395f);
        	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
        	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
        	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
        	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5098039507865906f, 0.5098039507865906f, 0.5098039507865906f, 1.0f);
        	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9699570536613464f, 0.98567795753479f, 1.0f, 1.0f);
        	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.6566457748413086f, 0.6566490530967712f, 0.6566523313522339f, 1.0f);
        	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.9999899864196777f, 0.999994695186615f, 1.0f, 1.0f);
        	style.Colors[ImGuiCol_Button] = ImVec4(0.5899538397789001f, 0.6284513473510742f, 0.6738197803497314f, 0.4000000059604645f);
        	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4185930788516998f, 0.4257249534130096f, 0.4334763884544373f, 1.0f);
        	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.5278916954994202f, 0.5278944969177246f, 0.5278970003128052f, 1.0f);
        	style.Colors[ImGuiCol_Header] = ImVec4(0.4532225728034973f, 0.5060346126556396f, 0.5708154439926147f, 0.3100000023841858f); // hi
        	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3605113923549652f, 0.3605130910873413f, 0.3605149984359741f, 0.800000011920929f);
        	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.335979700088501f, 0.3393619954586029f, 0.3433476686477661f, 0.454935610294342f);
        	style.Colors[ImGuiCol_Separator] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
        	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3991376161575317f, 0.3991397023200989f, 0.3991416096687317f, 0.7799999713897705f);
        	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.2611026167869568f, 0.2654090523719788f, 0.270386278629303f, 1.0f);
        	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.4849736988544464f, 0.4849759936332703f, 0.4849785566329956f, 0.2000000029802322f);
        	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.5879769325256348f, 0.5879799723625183f, 0.5879828333854675f, 0.6700000166893005f);
        	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.3148704171180725f, 0.3161545693874359f, 0.3175965547561646f, 0.8025751113891602f);
        	style.Colors[ImGuiCol_Tab] = ImVec4(0.3433442413806915f, 0.3433458805084229f, 0.3433476686477661f, 0.2618025541305542f);
        	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.4031755924224854f, 0.4072664380073547f, 0.4120171666145325f, 0.5321888327598572f);
        	style.Colors[ImGuiCol_TabActive] = ImVec4(0.4175984263420105f, 0.4208010733127594f, 0.4248927235603333f, 0.6266094446182251f);
        	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1881596744060516f, 0.190397784113884f, 0.1931330561637878f, 0.9724000096321106f);
        	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1158786714076996f, 0.1158792153000832f, 0.1158798336982727f, 1.0f);
        	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
        	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
        	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
        	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
        	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
        	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
        	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
        	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
        	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.1759639084339142f, 0.1759647578001022f, 0.1759656667709351f, 0.3499999940395355f);
        	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
        	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.1931311190128326f, 0.1931320130825043f, 0.1931330561637878f, 0.7768239974975586f);
        	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
        	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f); // lol
        	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
    }).draw([] {        
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        if (ImGui::BeginTabBar("Polo")) {
            if (ImGui::BeginTabItem("Misc")) {
                ImGui::Text("speedhack");
                ImGui::SameLine();

                if (ImGui::SliderFloat("##Speedhack", &speedhackValue, 0.00001f, 50.0f) {
                    Mod::get()->setSavedValue("speedhack-value", speedhackValue);
                }
                
                ImGui::Text("no wave pulse");
                ImGui::SameLine();

                if (ImGui::SliderFloat("##nowavepulse", &noWavePulseValue, 0.00001f, 50.0f) {
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
            if (ImGui::BeginTabItem("Settings")) {
                if (ImGui::Combo("Theme", &currentTheme, themes, IM_ARRAYSIZE(themes))) {
                    switch (currentTheme) {
                        case 0: ImGui::StyleColorsDark(); break;
                        case 1: ImGui::StyleColorsLight(); break;
                        case 2: ImGui::StyleColorsClassic(); break;
                    }
                    ImGuiStyle& style = ImGui::GetStyle();
                    style.WindowRounding    = 8.0f;
                    style.FrameRounding     = 5.0f;
                    style.PopupRounding     = 6.0f;
                    style.ChildRounding     = 6.0f;
                    style.TabRounding       = 4.0f;
                    style.GrabRounding      = 4.0f;
                    style.ScrollbarRounding = 4.0f;
                }
            ImGui::EndTabItem();
            }
        ImGui::End();
        };
    });
};


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
