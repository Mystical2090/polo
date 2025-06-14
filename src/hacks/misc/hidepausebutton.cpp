#include <Geode/Geode.hpp>
#include <Geode/modify/UILayer.hpp>

using namespace geode::prelude;

class $modify(UILayerMod, UILayer) {
    bool init(GJBaseGameLayer* p0) {
        if (!UILayer::init(p0))
            return false;

        if (Mod::get()->getSettingValue<bool>("hide-pause-button")) {
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
