#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(SpeedhackMod, PlayLayer) {
public:
    // update overide yayyayayayayay
    void update(float dt) {
        // Check if geode settings has it enabled
        float speedMultiplier = Mod::get()->getSettingValue<float>("speedhack");
        
        // Adjust to adjust speed yay
        PlayLayer::update(dt * speedMultiplier); // Scale the delta time by the speed multiplier
    }
};
