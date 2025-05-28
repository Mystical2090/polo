#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
// hey mystic whats up with all those chatgpt ahh includes
using namespace geode::prelude;

class $modify(GameObject) {
    void setVisible(bool v) {
        if (Mod::get()->getSettingValue<bool>("layout-mode")) {
            if (m_objectType == GameObjectType::Decoration &&
                m_objectID != 44 && // 44 is checkpoints cus apparently thats a quote decoration lmao
                m_objectID != 38 &&
                m_objectID != 749 &&
                m_objectID != 747) {
                // These are deco obj that will hide in layout mode
                GameObject::setVisible(false);
            } else {
                GameObject::setVisible(v);
            }
        } else {
            GameObject::setVisible(v);
        }
    }
};
