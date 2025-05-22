#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>

using namespace geode::prelude;

class $modify(SecretLayer2) {
public:
    static void onModify(SecretLayer2& self) {
        if (!Mod::get()->getSettingValue<bool>("thechan")) {
            return;
        }

        self.setHookPriority("SecretLayer2::onSecretLevel", 99999999);
    }

    void onSecretLevel(cocos2d::CCObject* sender) {
        if (!Mod::get()->getSettingValue<bool>("enable-noclip")) {
            return;
        }

        GameManager::get()->m_sceneEnum = 12;

        auto scene = CCTransitionFade::create(
            0.5f,
            PlayLayer::scene(GameLevelManager::get()->getMainLevel(3001, false), false, false)
        );

        CCDirector::get()->replaceScene(scene);
    }
};
