#include <Geode/Geode.hpp>
#include <Geode/modify/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(SafeMode, GJGameLevel) {
    void levelWasCompleted() {
        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("level not complete cus ssafe mode");
            return; // block level from being marked as completed
        }

        GJGameLevel::levelWasCompleted(); // allow normal completion
    }
};
