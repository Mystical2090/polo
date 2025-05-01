#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class $modify(MyLayer, PoloUI) {
    void onMiscButton(cocos2d::CCObject*);
};

class PoloUI : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        this->setTitle("Polo Mod Menu");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        m_mainLayer->addChildAtPosition(label, Anchor::Center);
        
    auto miscbtn = ButtonSprite::create("Misc");
        miscbtn->setScale(0.9f);
        
        
    auto miscbutton = CCMenuItemSpriteExtra::create(
        miscbtn,
        miscbtn,
        this,
        menu_selector(MyLayer::onMiscButton)
);

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    miscbutton->setPosition({ winSize.width / 2 - 150.f, winSize.height / 2 - 50.f });

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(miscbutton);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
        return true;
    }

public:
    static PoloUI* create(std::string const& text) {
        auto ret = new MyLayer();
        if (ret->initAnchored(240.f, 160.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};
