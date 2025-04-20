#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(Speedhack, PlayLayer) {
    void update(float dt) {
        float mult = Mod::get()->getSettingValue<float>("speedhack");

        // logging stuff to see if it worksasjkdc DEV thing
        log::debug("Running Speedhack: dt = {}, mult = {}", dt, mult);

        // Apply da speedhack to make da work daadsldci
        PlayLayer::update(dt * mult);
    }
};

void loadGlobalHacks() {
    log::info("Speedhack loaded");

    // Link the class
    Speedhack::get();
}
