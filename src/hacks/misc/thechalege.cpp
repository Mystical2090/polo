/* #include <Geode/Geode.hpp> // polo ui when 
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/loader/Setting.hpp>

using namespace geode::prelude;

class $modify(TheChallegeHook, SecretLayer2) {
    void onSecretLevel(cocos2d::CCObject* sender) {
        if (!Mod::get()->getSettingValue<bool>("thechan")) {
            return SecretLayer2::onSecretLevel(sender);
        }

        GameManager::get()->m_sceneEnum = 12;
        auto scene = CCTransitionFade::create(
            0.5f,
            PlayLayer::scene(GameLevelManager::get()->getMainLevel(3001, false), false, false)
        );
        CCDirector::get()->replaceScene(scene);
    }

    void onModify() override {
        setHookPriority("onSecretLevel", 99999999);
    }
}; maybe i should commit suicide*/