#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        if (Mod::get()->getSettingValue<bool>("instant-respawn")) {
            this->resetLevel();
        } else {
            PlayLayer::destroyPlayer(player, obj);
        }
    }
}; // easiesst hack ever lol
