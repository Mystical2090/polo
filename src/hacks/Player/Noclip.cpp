#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(NoclipHack, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (!Mod::get()->getSettingValue<bool>("enable-noclip")) {
            PlayLayer::destroyPlayer(player, object);
        }
    }
};
