#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    CCLabelBMFont* jumphacklabel = nullptr;
    CCLabelBMFont* nocliplabel = nullptr;
    CCLabelBMFont* ignoreinputslabel = nullptr;
    CCLabelBMFont* autoclickerlabel = nullptr;
    bool setup(std::string const& value) override {
            this->setTitle("Player");
            this->m_title->setScale(1.2f); 
        
    auto popupSize = this->getContentSize();

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
// polo version label
    auto label = CCLabelBMFont::create("Polo v1.0.0", "bigFont.fnt");
        label->setScale(0.3f);
        label->setAnchorPoint({1.0f, 0.0f});
        label->setPosition({ popupSize.width - 10.f, 10.f });
// jump hack label
        jumphacklabel = CCLabelBMFont::create("Jump Hack", "bigFont.fnt");
        jumphacklabel->setScale(1.0f);
        m_mainLayer->addChild(jumphacklabel);
// noclip label
        nocliplabel = CCLabelBMFont::create("Ignore Inputs", "bigFont.fnt");
        nocliplabel->setScale(1.0f);
        nocliplabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() + 30.f
            );
            m_mainLayer->addChild(nocliplabel)2;
// ignore inputs label
        ignoreinputslabel = CCLabelBMFont::create("Ignore Inputs", "bigFont.fnt");
        ignoreinputslabel->setScale(1.0f);
        ignoreinputslabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() - 30.f
            );
            m_mainLayer->addChild(ignoreinputslabel);
// autoclicker label 
        autoclickerlabel = CCLabelBMFont::create("Ignore Inputs", "bigFont.fnt");
        autoclickerlabel->setScale(1.0f);
        autoclickerlabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() - 60.f
            );
            m_mainLayer->addChild(autoclickerlabel);
    // Misc button
    auto miscbtn = ButtonSprite::create(" Misc  ");
    miscbtn->setScale(0.9f);
    miscbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto miscbutton = CCMenuItemSpriteExtra::create(
        miscbtn,
        miscbtn,
        this,
        menu_selector(MyPopup::onMiscButton)
    );
    miscbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.55f });

    // Player button
    auto playerbtn = ButtonSprite::create("Player");
    playerbtn->setScale(0.9f);
    playerbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto playerbutton = CCMenuItemSpriteExtra::create(
        playerbtn,
        playerbtn,
        this,
        menu_selector(MyPopup::onPlayerButton)
    );
    playerbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.67f });
        // creator button
    auto creatorbtn = ButtonSprite::create("Creator");
    creatorbtn->setScale(0.9f);
    creatorbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto creatorbutton = CCMenuItemSpriteExtra::create(
        creatorbtn,
        creatorbtn,
        this,
        menu_selector(MyPopup::onCreatorButton)
    );
    creatorbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.43f });
        // credits button
    auto creditsbtn = ButtonSprite::create("Credits");
    creditsbtn->setScale(0.9f);
    creditsbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto creditsbutton = CCMenuItemSpriteExtra::create(
        creditsbtn,
        creditsbtn,
        this,
        menu_selector(MyPopup::onCreditsButton)
    );
    creditsbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.31f });
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
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
    }
    void onPlayerButton(cocos2d::CCObject*) {
        this->setTitle("Player");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(true);
        jumphacklabel->setVisible(true);
        ignoreinputslabel->setVisible(true);
        autoclickerlabel->setVisible(true);
    }
    void onCreatorButton(cocos2d::CCObject*) {
        this->setTitle("Creator");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
    }
    void onCreditsButton(cocos2d::CCObject*) {
        this->setTitle("Credits");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
    }

public:
    static MyPopup* create(std::string const& text) {
        auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        float popupWidth = winSize.width * 0.9f;
        float popupHeight = winSize.height * 0.8f;

        auto ret = new MyPopup();
        if (ret->initAnchored(popupWidth, popupHeight, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};
