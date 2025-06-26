
#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    CCLabelBMFont* jumphacklabel = nullptr;
    CCLabelBMFont* nocliplabel = nullptr;
    CCLabelBMFont* ignoreinputslabel = nullptr;
    CCLabelBMFont* autoclickerlabel = nullptr;
    CCLabelBMFont* instantrespawnlabel = nullptr;
    CCLabelBMFont* layoutmodelabel = nullptr;
    CCLabelBMFont* practicemusichacklabel = nullptr;
    CCLabelBMFont* iconhacklabel = nullptr;
    CCLabelBMFont* colorhacklabel = nullptr;
    CCLabelBMFont* speedhacklabel = nullptr;
    CCLabelBMFont* showtrajectorylabel = nullptr;
    CCLabelBMFont* rgbiconslabel = nullptr;
    CCMenuItemToggler* noclipcheckbox = nullptr;
    CCSprite* rightplayerarrowbtn = nullptr;
    CCSprite* leftplayerarrowbtn = nullptr;
    CCSprite* rightmiscarrowbtn = nullptr;
    CCSprite* leftmiscarrowbtn = nullptr;

    bool setup(std::string const& value) override {
            this->setTitle("Player");
            this->m_title->setScale(1.2f); 
        
    auto popupSize = this->getContentSize();

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
// polo version label
    auto label = CCLabelBMFont::create("Polo v1.0.0", "goldFont.fnt");
        label->setScale(0.3f);
        label->setAnchorPoint({1.0f, 0.0f});
        label->setPosition({ popupSize.width - 10.f, 10.f });
// jump hack label 00000
        jumphacklabel = CCLabelBMFont::create("Jump Hack", "bigFont.fnt");
        jumphacklabel->setScale(0.5f);
        jumphacklabel->setColor({255, 255, 255});
        jumphacklabel->setZOrder(1);
        jumphacklabel->setPosition(popupSize.width / 2 - 70.f, popupSize.height / 2);
        m_mainLayer->addChild(jumphacklabel);
        jumphacklabel->setContentSize({ 100.f, jumphacklabel->getContentSize().height });
// another brown background thing!
    auto hacksbackground = CCScale9Sprite::create("GJ_square01.png");
        hacksbackground->setColor({0, 0, 0});
        hacksbackground->setOpacity(75);
        hacksbackground->setZOrder(-10);
        hacksbackground->setContentSize({300.f, 175.f});
        hacksbackground->setPosition(
            jumphacklabel->getPositionX() + 135.f,
            jumphacklabel->getPositionY()
            );
// noclip label
        nocliplabel = CCLabelBMFont::create("Noclip", "bigFont.fnt");
        nocliplabel->setScale(0.5f);
        nocliplabel->setColor({255, 255, 255});
        nocliplabel->setZOrder(1);
        nocliplabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() + 40.f
            );
            m_mainLayer->addChild(nocliplabel);
        nocliplabel->setContentSize({ 100.f, jumphacklabel->getContentSize().height });
// ignore inputs label
        ignoreinputslabel = CCLabelBMFont::create("Ignore Inputs", "bigFont.fnt");
        ignoreinputslabel->setScale(0.5f);
        ignoreinputslabel->setColor({255, 255, 255});
        ignoreinputslabel->setZOrder(1);
        ignoreinputslabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() - 80.f
            );
            m_mainLayer->addChild(ignoreinputslabel);
        ignoreinputslabel->setContentSize({ 100.f, jumphacklabel->getContentSize().height });
// autoclicker label 
        autoclickerlabel = CCLabelBMFont::create("AutoClicker", "bigFont.fnt");
        autoclickerlabel->setScale(0.5);
        autoclickerlabel->setColor({255, 255, 255});
        autoclickerlabel->setZOrder(1);
        autoclickerlabel->setPosition(
            jumphacklabel->getPositionX(),
            jumphacklabel->getPositionY() - 800.f
            );
            m_mainLayer->addChild(autoclickerlabel);
        autoclickerlabel->setContentSize({ 100.f, jumphacklabel->getContentSize().height });
// layout mode label 11111
        layoutmodelabel = CCLabelBMFont::create("Layout Mode", "bigFont.fnt");
        layoutmodelabel->setScale(0.5f);
        layoutmodelabel->setPosition(popupSize.width / 2 - 70.f, popupSize.height / 2 - 10.f);
        m_mainLayer->addChild(layoutmodelabel);
        layoutmodelabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });

// practice music hack label
        practicemusichacklabel = CCLabelBMFont::create("Practice Music Hack", "bigFont.fnt");
        practicemusichacklabel->setScale(0.5f);
        practicemusichacklabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY() + 40.f
            );
            m_mainLayer->addChild(practicemusichacklabel);
        practicemusichacklabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// icon hack label
        iconhacklabel = CCLabelBMFont::create("Icon Hack", "bigFont.fnt");
        iconhacklabel->setScale(0.5f);
        iconhacklabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY() - 50.f
            );
            m_mainLayer->addChild(iconhacklabel);
        iconhacklabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// color hack label 
        colorhacklabel = CCLabelBMFont::create("Color Hack", "bigFont.fnt");
        colorhacklabel->setScale(0.5f);
        colorhacklabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY() - 100.f
            );
            m_mainLayer->addChild(colorhacklabel);
        colorhacklabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// speedhack label 
        speedhacklabel = CCLabelBMFont::create("Speed Hack", "bigFont.fnt");
        speedhacklabel->setScale(0.5);
        speedhacklabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY() - 100.f
            );
            m_mainLayer->addChild(speedhacklabel);
        speedhacklabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// instant respawn label 
        instantrespawnlabel = CCLabelBMFont::create("Instant Respawn", "bigFont.fnt");
        instantrespawnlabel->setScale(0.5f);
        instantrespawnlabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY()
            );
            m_mainLayer->addChild(instantrespawnlabel);
        instantrespawnlabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// show trajectory label 
        showtrajectorylabel = CCLabelBMFont::create("Show Trajectory", "bigFont.fnt");
        showtrajectorylabel->setScale(0.5f);
        showtrajectorylabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY() + 40.f
            );
            m_mainLayer->addChild(showtrajectorylabel);
        showtrajectorylabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
// rgb icons label 
        rgbiconslabel = CCLabelBMFont::create("Rgb Icons", "bigFont.fnt");
        rgbiconslabel->setScale(0.5f);
        rgbiconslabel->setPosition(
            layoutmodelabel->getPositionX(),
            layoutmodelabel->getPositionY()
            );
            m_mainLayer->addChild(rgbiconslabel);
        rgbiconslabel->setContentSize({ 100.f, layoutmodelabel->getContentSize().height });
    // Misc button
    auto miscbtn = ButtonSprite::create(" Misc  ");
    miscbtn->setScale(0.9f);
    miscbtn->setZOrder(0);
    miscbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto miscbutton = CCMenuItemSpriteExtra::create(
        miscbtn,
        miscbtn,
        this,
        menu_selector(MyPopup::onMiscButton)
    );
    miscbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.55f });
        // dark brown background thing
    auto playerbackground = CCScale9Sprite::create("GJ_square01.png");
        playerbackground->setColor({68, 42, 30});
        playerbackground->setOpacity(100);
        playerbackground->setZOrder(-1);
        playerbackground->setContentSize({120.f, 170.f});
        playerbackground->setPosition(
            miscbutton->getPositionX() + 7.f,
            miscbutton->getPositionY() - 19.f
            );
    // Player button
    auto playerbtn = ButtonSprite::create("Player");
    playerbtn->setScale(0.9f);
    playerbtn->setZOrder(0);
    playerbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto playerbutton = CCMenuItemSpriteExtra::create(
        playerbtn,
        playerbtn,
        this,
        menu_selector(MyPopup::onPlayerButton)
    );
    playerbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.67f });
        // creator button
    auto creatorbtn = ButtonSprite::create("Editor");
    creatorbtn->setScale(0.9f);
    creatorbtn->setZOrder(0);
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
    creditsbtn->setZOrder(0);
    creditsbtn->setContentSize({ 100.f, miscbtn->getContentSize().height });
    auto creditsbutton = CCMenuItemSpriteExtra::create(
        creditsbtn,
        creditsbtn,
        this,
        menu_selector(MyPopup::onCreditsButton)
    );
    creditsbutton->setPosition({ popupSize.width * 0.18f, popupSize.height * 0.31f });
        // right arrow for the player menu
    rightplayerarrowbtn = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");
    rightplayerarrowbtn->setFlipX(true);

    auto rightplayerarrowbutton = CCMenuItemSpriteExtra::create(
        rightplayerarrowbtn,
        rightplayerarrowbtn,
        this,
        menu_selector(MyPopup::onRightPlayerArrowButton)
    );
     rightplayerarrowbutton->setPosition(
        hacksbackground->getPositionX() + hacksbackground->getContentSize().width / 2 + 10.f,
        hacksbackground->getPositionY()
    );
        // left arrow for the player menu
    leftplayerarrowbtn = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");
    leftplayerarrowbtn->setFlipX(false);

    auto leftplayerarrowbutton = CCMenuItemSpriteExtra::create(
        leftplayerarrowbtn,
        leftplayerarrowbtn,
        this,
        menu_selector(MyPopup::onLeftPlayerArrowButton)
    );
    leftplayerarrowbutton->setPosition(
        hacksbackground->getPositionX() - hacksbackground->getContentSize().width / 2 - 10.f,
        hacksbackground->getPositionY()
    );
        // right arrow for the misc menu
    rightmiscarrowbtn = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");
    rightmiscarrowbtn->setFlipX(true);

    auto rightmiscarrowbutton = CCMenuItemSpriteExtra::create(
        rightmiscarrowbtn,
        rightmiscarrowbtn,
        this,
        menu_selector(MyPopup::onRightMiscArrowButton)
    );
    rightmiscarrowbutton->setPosition(
        hacksbackground->getPositionX() + hacksbackground->getContentSize().width / 2 + 10.f,
        hacksbackground->getPositionY()
    );
        // left arrow for the misc menu
    leftmiscarrowbtn = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");
    leftmiscarrowbtn->setFlipX(false);

    auto leftmiscarrowbutton = CCMenuItemSpriteExtra::create(
        leftmiscarrowbtn,
        leftmiscarrowbtn,
        this,
        menu_selector(MyPopup::onLeftMiscArrowButton)
    );
    leftmiscarrowbutton->setPosition(
        hacksbackground->getPositionX() - hacksbackground->getContentSize().width / 2 + 10.f,
        hacksbackground->getPositionY()
    );
    // thing so it wont show the labels from misc when opening the menu
        layoutmodelabel->setVisible(false);
        practicemusichacklabel->setVisible(false);
        instantrespawnlabel->setVisible(false);
        speedhacklabel->setVisible(false);
        iconhacklabel->setVisible(false);
        colorhacklabel->setVisible(false);
        leftmiscarrowbtn->setVisible(false);
        rightmiscarrowbtn->setVisible(false);
        showtrajectorylabel->setVisible(false);
        rgbiconslabel->setVisible(false);
        // checkbox setup
    auto checkboxOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
    auto checkboxOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
// noclip checkbox
bool noclipEnabled = Mod::get()->getSavedValue<bool>("enable-noclip", false);
    noclipcheckbox = CCMenuItemToggler::create(
        checkboxOff,
        checkboxOn,
        this,
        menu_selector(MyPopup::onNoclipCheckbox)
            );
        noclipcheckbox->setPosition(
            jumphacklabel->getPositionX() + 95.f,
            jumphacklabel->getPositionY() + 60.f
           );
        noclipcheckbox->setScale(0.9f);
        noclipcheckbox->toggle(noclipEnabled);
        // mmm yes
    auto menu = cocos2d::CCMenu::create();
    menu->addChild(hacksbackground, -1);
    menu->addChild(playerbutton);
    menu->addChild(miscbutton);
    menu->addChild(creatorbutton);
    menu->addChild(creditsbutton);
    menu->addChild(label);
    menu->addChild(playerbackground);
    menu->addChild(noclipcheckbox);
    menu->addChild(rightplayerarrowbutton);
    menu->addChild(leftplayerarrowbutton);
    menu->addChild(rightmiscarrowbutton);
    menu->addChild(leftmiscarrowbutton);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
    return true;
}

    void onNoclipCheckbox(cocos2d::CCObject* sender) {
        auto checkbox = static_cast<CCMenuItemToggler*>(sender);
        bool toggled = checkbox->isToggled();
        Mod::get()->setSavedValue("enable-noclip", toggled);
   }
    void onRightPlayerArrowButton(cocos2d::CCObject* sender) {
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
        noclipcheckbox->setVisible(false);   
   }
    void onLeftPlayerArrowButton(cocos2d::CCObject* sender) {
        nocliplabel->setVisible(true);
        jumphacklabel->setVisible(true);
        ignoreinputslabel->setVisible(true);
        autoclickerlabel->setVisible(true);
        noclipcheckbox->setVisible(true);   
   }
    void onRightMiscArrowButton(cocos2d::CCObject* sender) {
        practicemusichacklabel->setVisible(false);
        speedhacklabel->setVisible(false);
        iconhacklabel->setVisible(false);
        colorhacklabel->setVisible(false);
        layoutmodelabel->setVisible(false);
        rgbiconslabel->setVisible(true);
        showtrajectorylabel->setVisible(true);
   }
    void onLeftMiscArrowButton(cocos2d::CCObject* sender) {
        practicemusichacklabel->setVisible(true);
        speedhacklabel->setVisible(true);
        iconhacklabel->setVisible(true);
        layoutmodelabel->setVisible(true);
        colorhacklabel->setVisible(true);
        rgbiconslabel->setVisible(false);
        showtrajectorylabel->setVisible(false);
   }
    void onMiscButton(cocos2d::CCObject*) {
        this->setTitle("Misc");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
        noclipcheckbox->setVisible(false);
        layoutmodelabel->setVisible(true);
        practicemusichacklabel->setVisible(true);
        speedhacklabel->setVisible(true);
        iconhacklabel->setVisible(true);
        colorhacklabel->setVisible(true);
        instantrespawnlabel->setVisible(false);
        rgbiconslabel->setVisible(false);
        showtrajectorylabel->setVisible(false);
        leftplayerarrowbtn->setVisible(false);
        rightplayerarrowbtn->setVisible(false);
        rightmiscarrowbtn->setVisible(true);
        leftmiscarrowbtn->setVisible(true);
    }
    void onPlayerButton(cocos2d::CCObject*) {
        this->setTitle("Player");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(true);
        jumphacklabel->setVisible(true);
        ignoreinputslabel->setVisible(true);
        autoclickerlabel->setVisible(true);
        noclipcheckbox->setVisible(true);
        layoutmodelabel->setVisible(false);
        practicemusichacklabel->setVisible(false);
        instantrespawnlabel->setVisible(false);
        speedhacklabel->setVisible(false);
        iconhacklabel->setVisible(false);
        colorhacklabel->setVisible(false);
        rgbiconslabel->setVisible(false);
        showtrajectorylabel->setVisible(false);
        leftplayerarrowbtn->setVisible(true);
        rightplayerarrowbtn->setVisible(true);
        rightmiscarrowbtn->setVisible(false);
        leftmiscarrowbtn->setVisible(false);
    }
    void onCreatorButton(cocos2d::CCObject*) {
        this->setTitle("Editor");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
        noclipcheckbox->setVisible(false);
        layoutmodelabel->setVisible(false);
        practicemusichacklabel->setVisible(false);
        instantrespawnlabel->setVisible(false);
        speedhacklabel->setVisible(false);
        iconhacklabel->setVisible(false);
        colorhacklabel->setVisible(false);
        rgbiconslabel->setVisible(false);
        showtrajectorylabel->setVisible(false);
        leftplayerarrowbtn->setVisible(false);
        rightplayerarrowbtn->setVisible(false);
        rightmiscarrowbtn->setVisible(false);
        leftmiscarrowbtn->setVisible(false);
    }
    void onCreditsButton(cocos2d::CCObject*) {
        this->setTitle("Credits");
        this->m_title->setScale(1.2f);
        nocliplabel->setVisible(false);
        jumphacklabel->setVisible(false);
        ignoreinputslabel->setVisible(false);
        autoclickerlabel->setVisible(false);
        noclipcheckbox->setVisible(false);
        layoutmodelabel->setVisible(false);
        practicemusichacklabel->setVisible(false);
        instantrespawnlabel->setVisible(false);
        speedhacklabel->setVisible(false);
        iconhacklabel->setVisible(false);
        colorhacklabel->setVisible(false);
        rgbiconslabel->setVisible(false);
        showtrajectorylabel->setVisible(false);
        leftplayerarrowbtn->setVisible(false);
        rightplayerarrowbtn->setVisible(false);
        rightmiscarrowbtn->setVisible(false);
        leftmiscarrowbtn->setVisible(false);
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
