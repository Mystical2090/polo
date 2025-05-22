#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

class $modify(SecretLayer2) {
public:
    void onDoor(cocos2d::CCObject* sender) {
        auto originalUGV = GameManager::get()->getUGV("4");

        if (Mod::get()->getSettingValue<bool>("basement-bypass")) {
            GameManager::get()->setUGV("4", true);
        }

        SecretLayer2::onDoor(sender);

        GameManager::get()->setUGV("4", originalUGV);
    }
};
