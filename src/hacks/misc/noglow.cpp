#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void addObject(GameObject* obj) {
        if (Mod::get()->getSettingValue<bool>("noglow")) {
            obj->m_hasNoGlow = true;
        }

        PlayLayer::addObject(obj);
    }
};
