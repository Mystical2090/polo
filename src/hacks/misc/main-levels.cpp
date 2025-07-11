#include <Geode/Geode.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/LevelAreaInnerLayer.hpp>

using namespace geode::prelude;

extern bool mainLevelBypassEnabled;

class $modify(LevelPage) {
    void onPlay(cocos2d::CCObject* sender) {
        auto v = m_level->m_requiredCoins;

        if (mainLevelBypassEnabled)
            m_level->m_requiredCoins = 0;

        LevelPage::onPlay(sender);

        m_level->m_requiredCoins = v;
    }
};

class $modify(LevelAreaInnerLayer) {
    bool init(bool p0) {
        if (!LevelAreaInnerLayer::init(p0))
            return false;

        if (!mainLevelBypassEnabled)
            return true;

        auto x = this->getChildByType<CCNode>(1);
        auto menu = x->getChildByType<CCMenu>(0);

        if (menu) {
            CCArrayExt<CCMenuItemSpriteExtra*> objs = menu->getChildren();

            for (auto child : objs) {
                child->setEnabled(true);
            }
        }

        return true;
    }
};
