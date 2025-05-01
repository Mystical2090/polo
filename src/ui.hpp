#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        this->setTitle("Polo Mod Menu");

        auto miscbtn = ButtonSprite::create("Misc");
        miscbtn->setScale(0.9f);

        auto miscbutton = CCMenuItemSpriteExtra::create(
            miscbtn,
            miscbtn,
            this,
            menu_selector(MyPopup::onMiscButton)
        );

        auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        miscbutton->setPosition({ winSize.width / 2 - 150.f, winSize.height / 2 - 50.f });

        auto menu = cocos2d::CCMenu::create();
        menu->addChild(miscbutton);
        menu->setPosition({ 0, 0 });

        this->addChild(menu);
        return true;
    }

    void onMiscButton(cocos2d::CCObject*) {
// i will add code to show only misc hacks
    }

public:
    static MyPopup* create(std::string const& text) {
        auto ret = new MyPopup();
        if (ret->initAnchored(440.f, 250.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};

