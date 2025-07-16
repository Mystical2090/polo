#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

extern bool copyHackEnabled;

using namespace geode::prelude;

class $modify(What, LevelInfoLayer) {
    bool init(GJGameLevel *p0, bool p1) {
        if (!LevelInfoLayer::init(p0, p1)) return false;
        if (copyHackEnabled) {
            auto gm = GameManager::sharedState();
            if (gm->m_playerUserID == p0->m_userID) return true;
            if (m_cloneBtn == nullptr) return true;
            auto aCloneBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_duplicateBtn_001.png"), this, menu_selector(LevelInfoLayer::confirmClone));
            aCloneBtn->setPosition(m_cloneBtn->getPosition());
            m_cloneBtn->getParent()->addChild(aCloneBtn);
            m_cloneBtn->setVisible(false);
        }
        return true;
    }
};
