#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>
using namespace geode::prelude;

extern bool basementBypassEnabled;

class $modify(Hello, SecretLayer2) {
    void onDoor(cocos2d::CCObject* sender) {
        auto originalUGV = GameManager::get()->getUGV("4");

        if (basementBypassEnabled) {
            GameManager::get()->setUGV("4", true);
        }

        SecretLayer2::onDoor(sender);

        GameManager::get()->setUGV("4", originalUGV);
    }
};
