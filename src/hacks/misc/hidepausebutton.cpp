#include <Geode/Geode.hpp>
#include <Geode/modify/UILayer.hpp>

using namespace geode::prelude;

extern bool hidePauseButtonEnabled;

class $modify(UILayerMod, UILayer) {
    bool init(GJBaseGameLayer* p0) {
        if (!UILayer::init(p0))
            return false;

        if (hidePauseButtonEnabled) {
            if (auto menu = this->getChildByType<CCMenu>(0)) {
                if (auto btn = menu->getChildByType<CCMenuItemSpriteExtra>(0)) {
                    if (auto sprite = btn->getNormalImage()) {
                        sprite->setVisible(false);
                    }
                }
            }
        }

        return true;
    }
};
