#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
            this->setTitle("Polo");
            this->m_title->setScale(1.2f); 
        
    auto popupSize = this->getContentSize();

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    auto label = CCLabelBMFont::create("Polo v1.0.0", "goldFont.fnt");
        label->setScale(0.3f);
        label->setAnchorPoint({0.5f, 0.5f});
        label->setPosition({winSize.width - 65.f, 40.f});
    // Misc button
    auto miscbtn = ButtonSprite::create(" Misc  ");
    miscbtn->setScale(0.9f);
    auto miscbutton = CCMenuItemSpriteExtra::create(
        miscbtn,
        miscbtn,
        this,
        menu_selector(MyPopup::onMiscButton)
    );
    miscbutton->setPosition({ 100.f, popupSize.height - 115.f });

    // Player button
    auto playerbtn = ButtonSprite::create("Player");
    playerbtn->setScale(0.9f);
    auto playerbutton = CCMenuItemSpriteExtra::create(
        playerbtn,
        playerbtn,
        this,
        menu_selector(MyPopup::onPlayerButton)
    );
    playerbutton->setPosition({ 100.f, popupSize.height - 75.f });
        // creator button
    auto creatorbtn = ButtonSprite::create("Creator");
    creatorbtn->setScale(0.9f);
    auto creatorbutton = CCMenuItemSpriteExtra::create(
        creatorbtn,
        creatorbtn,
        this,
        menu_selector(MyPopup::onCreatorButton)
    );
    creatorbutton->setPosition({ 100.f, popupSize.height - 155.f });
        // credits button
    auto creditsbtn = ButtonSprite::create("Credits");
    creditsbtn->setScale(0.9f);
    auto creditsbutton = CCMenuItemSpriteExtra::create(
        creditsbtn,
        creditsbtn,
        this,
        menu_selector(MyPopup::onCreditsButton)
    );
    creditsbutton->setPosition({ 100.f, popupSize.height - 195.f });
        // mmm yes
    auto menu = cocos2d::CCMenu::create();
    menu->addChild(playerbutton);
    menu->addChild(miscbutton);
    menu->addChild(creatorbutton);
    menu->addChild(creditsbutton);
    menu->addChild(label);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
    return true;
}

    void onMiscButton(cocos2d::CCObject*) {
        this->setTitle("Misc");
        this->m_title->setScale(1.2f); 
    }
    void onPlayerButton(cocos2d::CCObject*) {
        this->setTitle("Player");
        this->m_title->setScale(1.2f); 
    }
    void onCreatorButton(cocos2d::CCObject*) {
        this->setTitle("Creator");
        this->m_title->setScale(1.2f); 
    }
    void onCreditsButton(cocos2d::CCObject*) {
        this->setTitle("Credits");
        this->m_title->setScale(1.2f); 
    }

public:
    static MyPopup* create(std::string const& text) {
        auto ret = new MyPopup();
        if (ret->initAnchored(550.f, 250.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};

