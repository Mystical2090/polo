#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <fstream>
#include <sstream>

using namespace geode::prelude;

// player
bool noclipEnabled = false;
bool ignoreInputsEnabled = false;
bool jumpHackEnabled = false;
bool autoclickerEnabled = false;

// editor
bool verifyHackEnabled = false;
bool copyHackEnabled = false;
bool noCMarkEnabled = false;
bool customObjectsBypassEnabled = false;

// misc
float speedhackValue = 1.0f;
float noWavePulseValue = 1.0f;
bool practiceMusicHackEnabled = false;
bool hidePauseButtonEnabled = false;
bool layoutModeEnabled = false;
bool commentHistoryBypassEnabled = false;
bool autoPracticeEnabled = false;
bool iconHackEnabled = false;
bool colorHackEnabled = false;
bool noSolidsEnabled = false;
bool suicideEnabled = false;
bool showHitboxesEnabled = false;
bool yes = false;
bool showHitboxesOnDeathEnabled = false;
bool rainbowIconsEnabled = false;
bool everythingKillsYouEnabled = false;
bool safeModeEnabled = false;
bool instantCompleteEnabled = false;
bool basementBypassEnabled = false;
bool levelEditEnabled = false;
bool mainLevelBypassEnabled = false;
bool towerBypassEnabled = false;
bool noGlowEnabled = false;

std::string getSettingsPath() {
    return (Mod::get()->getConfigDir() / "polo_settings.txt").string();
}

void saveSettings() {
    std::ofstream file(getSettingsPath());
    if (file.is_open()) {
        // Player settings
        file << "noclip=" << noclipEnabled << "\n";
        file << "ignoreInputs=" << ignoreInputsEnabled << "\n";
        file << "jumpHack=" << jumpHackEnabled << "\n";
        file << "autoclicker=" << autoclickerEnabled << "\n";
        
        // Editor settings
        file << "verifyHack=" << verifyHackEnabled << "\n";
        file << "copyHack=" << copyHackEnabled << "\n";
        file << "noCMark=" << noCMarkEnabled << "\n";
        file << "customObjectsBypass=" << customObjectsBypassEnabled << "\n";
        
        // Misc settings
        file << "speedhackValue=" << speedhackValue << "\n";
        file << "noWavePulseValue=" << noWavePulseValue << "\n";
        file << "practiceMusicHack=" << practiceMusicHackEnabled << "\n";
        file << "hidePauseButton=" << hidePauseButtonEnabled << "\n";
        file << "layoutMode=" << layoutModeEnabled << "\n";
        file << "commentHistoryBypass=" << commentHistoryBypassEnabled << "\n";
        file << "autoPractice=" << autoPracticeEnabled << "\n";
        file << "iconHack=" << iconHackEnabled << "\n";
        file << "colorHack=" << colorHackEnabled << "\n";
        file << "noSolids=" << noSolidsEnabled << "\n";
        file << "suicide=" << suicideEnabled << "\n";
        file << "showHitboxes=" << showHitboxesEnabled << "\n";
        file << "showHitboxesOnDeath=" << showHitboxesOnDeathEnabled << "\n";
        file << "rainbowIcons=" << rainbowIconsEnabled << "\n";
        file << "everythingKillsYou=" << everythingKillsYouEnabled << "\n";
        file << "safeMode=" << safeModeEnabled << "\n";
        file << "instantComplete=" << instantCompleteEnabled << "\n";
        file << "basementBypass=" << basementBypassEnabled << "\n";
        file << "levelEdit=" << levelEditEnabled << "\n";
        file << "mainLevelBypass=" << mainLevelBypassEnabled << "\n";
        file << "towerBypass=" << towerBypassEnabled << "\n";
        file << "noGlow=" << noGlowEnabled << "\n";
        
        file.close();
    }
}

void loadSettings() {
    std::ifstream file(getSettingsPath());
    if (!file.is_open()) {
        return; // File doesn't exist, use defaults
    }
    
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            
            // Player settings
            if (key == "noclip") noclipEnabled = (value == "1");
            else if (key == "ignoreInputs") ignoreInputsEnabled = (value == "1");
            else if (key == "jumpHack") jumpHackEnabled = (value == "1");
            else if (key == "autoclicker") autoclickerEnabled = (value == "1");
            
            // Editor settings
            else if (key == "verifyHack") verifyHackEnabled = (value == "1");
            else if (key == "copyHack") copyHackEnabled = (value == "1");
            else if (key == "noCMark") noCMarkEnabled = (value == "1");
            else if (key == "customObjectsBypass") customObjectsBypassEnabled = (value == "1");
            
            // Misc settings
            else if (key == "speedhackValue") speedhackValue = std::stof(value);
            else if (key == "noWavePulseValue") noWavePulseValue = std::stof(value);
            else if (key == "practiceMusicHack") practiceMusicHackEnabled = (value == "1");
            else if (key == "hidePauseButton") hidePauseButtonEnabled = (value == "1");
            else if (key == "layoutMode") layoutModeEnabled = (value == "1");
            else if (key == "commentHistoryBypass") commentHistoryBypassEnabled = (value == "1");
            else if (key == "autoPractice") autoPracticeEnabled = (value == "1");
            else if (key == "iconHack") iconHackEnabled = (value == "1");
            else if (key == "colorHack") colorHackEnabled = (value == "1");
            else if (key == "noSolids") noSolidsEnabled = (value == "1");
            else if (key == "suicide") suicideEnabled = (value == "1");
            else if (key == "showHitboxes") showHitboxesEnabled = (value == "1");
            else if (key == "showHitboxesOnDeath") showHitboxesOnDeathEnabled = (value == "1");
            else if (key == "rainbowIcons") rainbowIconsEnabled = (value == "1");
            else if (key == "everythingKillsYou") everythingKillsYouEnabled = (value == "1");
            else if (key == "safeMode") safeModeEnabled = (value == "1");
            else if (key == "instantComplete") instantCompleteEnabled = (value == "1");
            else if (key == "basementBypass") basementBypassEnabled = (value == "1");
            else if (key == "levelEdit") levelEditEnabled = (value == "1");
            else if (key == "mainLevelBypass") mainLevelBypassEnabled = (value == "1");
            else if (key == "towerBypass") towerBypassEnabled = (value == "1");
            else if (key == "noGlow") noGlowEnabled = (value == "1");
        }
    }
    file.close();
}

$on_mod(Loaded) {
    loadSettings(); // Load settings on mod startup
    
    ImGuiCocos::get().setup([] {
        ImGui::StyleColorsDark();
    }).draw([]() {
        bool settingsChanged = false;
        
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        if (ImGui::BeginTabBar("Polo")) {
            if (ImGui::BeginTabItem("Misc")) {
                ImGui::Text("speedhack");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    settingsChanged = true;
                }
#else
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f")) {
                    settingsChanged = true;
                }
#endif
                
                ImGui::Text("no wave pulse");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    settingsChanged = true;
                }
#else
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f")) {
                    settingsChanged = true;
                }
#endif
                
                ImGui::Text("practice music hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##practicemusichack", &practiceMusicHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("hide pause button");
                ImGui::SameLine();
                if (ImGui::Checkbox("##hidepausebutton", &hidePauseButtonEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("layout mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##layoutmode", &layoutModeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("comment history bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##commenthistorybypass", &commentHistoryBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("auto practice");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autopractice", &autoPracticeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("icon hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##iconhack", &iconHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("color hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##colorhack", &colorHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no solids");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nosolids", &noSolidsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("suicide");
                ImGui::SameLine();
                if (ImGui::Checkbox("##suicide", &suicideEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("show hitboxes");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxes", &showHitboxesEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("show hitboxes on death");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxesondeath", &showHitboxesOnDeathEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("rainbow icons");
                ImGui::SameLine();
                if (ImGui::Checkbox("##rainbowicons", &rainbowIconsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("everything kills you");
                ImGui::SameLine();
                if (ImGui::Checkbox("##everythingkillsyou", &everythingKillsYouEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("safe mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##safemode", &safeModeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("instant complete");
                ImGui::SameLine();
                if (ImGui::Checkbox("##instantcomplete", &instantCompleteEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("basement bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##basementbypass", &basementBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("level edit");
                ImGui::SameLine();
                if (ImGui::Checkbox("##leveledit", &levelEditEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("main level bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##mainlevelbypass", &mainLevelBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("tower bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##towerbypass", &towerBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no glow");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noglow", &noGlowEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Editor")) {
                ImGui::Text("verify hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##verifyhack", &verifyHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("copy hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##copyhack", &copyHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no c mark");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nocmark", &noCMarkEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("custom objects bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##customobjectsbypass", &customObjectsBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Player")) {
                ImGui::Text("noclip");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noclip", &noclipEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("ignore inputs");
                ImGui::SameLine();
                if (ImGui::Checkbox("##ignoreinputs", &ignoreInputsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("jump hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##jumphack", &jumpHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("autoclicker");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autoclicker", &autoclickerEnabled)) {
                    settingsChanged = true;
                }
                ImGui::EndTabItem();
            }
                
            if (ImGui::BeginTabItem("Credits")) {
                ImGui::Text("Gtxx9003, Developer, Features, more..");
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
                
                if (ImGui::Button("Save Settings")) {
                    saveSettings();
                }
                ImGui::SameLine();
                if (ImGui::Button("Load Settings")) {
                    loadSettings();
                }
                
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
        
        // Auto-save when settings change
        if (settingsChanged) {
            saveSettings();
        }
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
