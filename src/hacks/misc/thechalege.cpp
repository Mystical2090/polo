/* #include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>

using namespace geode::prelude;
using geode::Hook;

class $modify(SecretLayer2) {
public:
    static void onModify() {
        if (!Mod::get()->getSettingValue<bool>("thechan")) {
            return;
        }
        Hook::get("SecretLayer2::onSecretLevel")->setPriority(99999999);
    }

    void onSecretLevel(cocos2d::CCObject* sender) {
        if (!Mod::get()->getSettingValue<bool>("thechan")) {
            return;
        }
        GameManager::get()->m_sceneEnum = 12;
        auto scene = CCTransitionFade::create(
            0.5f,
            PlayLayer::scene(GameLevelManager::get()->getMainLevel(3001, false), false, false)
        );
        CCDirector::get()->replaceScene(scene);
    }
}; */





// fuck it i give up
