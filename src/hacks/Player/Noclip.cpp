#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(NoclipHack, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-noclip")) {
            void destroyPlayer(PlayerObject* player, GameObject* object) {
            }
        }
        PlayLayer::update(dt);
    }
};
