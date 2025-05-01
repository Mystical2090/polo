#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
            this->setTitle("Polo Mod Menu");

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    // Misc button
    auto miscbtn = ButtonSprite::create(" Misc  ");
    miscbtn->setScale(0.9f);
    auto miscbutton = CCMenuItemSpriteExtra::create(
        miscbtn,
        miscbtn,
        this,
        menu_selector(MyPopup::onMiscButton)
    );
    miscbutton->setPosition({ -150.f, 70.f });

    // Player button
    auto playerbtn = ButtonSprite::create("Player");
    playerbtn->setScale(0.9f);
    auto playerbutton = CCMenuItemSpriteExtra::create(
        playerbtn,
        playerbtn,
        this,
        menu_selector(MyPopup::onPlayerButton)
    );
    playerbutton->setPosition({ -150.f, 40.f });

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(playerbutton);
    menu->addChild(miscbutton);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
    return true;
}

    void onMiscButton(cocos2d::CCObject*) {
// i will add code to show only misc hacks
    }
    void onPlayerButton(cocos2d::CCObject*) {
// i will add code to show only player hacks
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

