/* i drunk rn idk
basdkfuh
*/
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

class $modify(SafeModeStatsBlocker, GameStatsManager) {
    void incrementStat(const char* key, int value) {
        if (Mod::get()->getSettingValue<bool>("safe-mode") &&
            (std::string_view(key) == "LevelComplete" ||
             std::string_view(key) == "Orbs" ||
             std::string_view(key) == "Stars")) {
            log::info("Safe Mode: Blocking stat increment for '{}'", key);
            return;
        }

        GameStatsManager::incrementStat(key, value);
    }
};

class $modify(SafeModePlayLayer, PlayLayer) {
    void levelComplete() {
        PlayLayer::levelComplete();

        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("Safe Mode: Blocking saved progress after completion");

            if (this->m_level) {
                this->m_level->m_normalPercent = 0;

                this->m_level->m_isVerified = false;

                this->m_level->m_orbCompletion = false;

                this->m_level->m_practicePercent = 0;
                this->m_level->m_coins = 0;
                
            }
        }
    }
};

