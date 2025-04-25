#include <Geode/Geode.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(CCScheduler) {
    float getTimeScale() {
        float originalTimeScale = CCScheduler::getTimeScale();
        
        auto speedhackEnabled = Mod::get()->getSettingValue<bool>("enabled");
        
        if (speedhackEnabled) {
            float speedMultiplier = Mod::get()->getSettingValue<float>("speed-value");
            
            return originalTimeScale * speedMultiplier;
        }
        
        return originalTimeScale;
    }
};