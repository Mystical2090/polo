#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(Speedhack, PlayLayer) {
    void update(float dt) {
        float mult = Mod::get()->getSettingValue<float>("speedhack");
        PlayLayer::update(dt * mult);
    }
};

void loadGlobalHacks() {
    log::info("Speedhack loaded");
}
