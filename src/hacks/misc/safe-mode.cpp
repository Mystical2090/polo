#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

class $modify(SafeGameManager, GameManager) {
    void saveGame() {
        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("Safe Mode enabled: Preventing game save.");
            return;
        }
        GameManager::saveGame();
    }

    void save() {
        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("Safe Mode enabled");
            return;
        }
        GameManager::save();
    }
};

