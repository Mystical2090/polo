#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

extern bool noGlowEnabled;

class $modify(PlayLayer) {
    void addObject(GameObject* obj) {
        if (noGlowEnabled) {
            obj->m_hasNoGlow = true;
        }

        PlayLayer::addObject(obj);
    }
};
