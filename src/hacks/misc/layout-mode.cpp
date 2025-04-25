#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/CCSprite.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/CCApplication.hpp>

using namespace geode::prelude;

class $modify(GameObject) {
    void setVisible(bool v) {
        if (Mod::get()->getSettingValue<bool>("layout-mode")) return GameObject::setVisible(v);
        if (m_objectType == GameObjectType::Decoration && m_objectID != 44 && m_objectID != 38 && m_objectID != 749 && m_objectID != 747) // 44 is checkpoints cus apparebtky thats a quote decoration lmao
            GameObject::setVisible(false);
        } else {
            GameObject::setVisible(v);
        }
    }
};
