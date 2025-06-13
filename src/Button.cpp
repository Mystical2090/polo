#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
public:
    void customSetup() override;
    void onSettingsButton(cocos2d::CCObject*);
};

void PauseWithImageButton::customSetup() {
    PauseLayer::customSetup();

    auto sprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");

    auto button = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        menu_selector(PauseWithImageButton::onSettingsButton)
    );

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    button->setPosition({ winSize.width - 40.f, winSize.height / 2 });

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(button);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
}

void PauseWithImageButton::onSettingsButton(cocos2d::CCObject*) {
    	geode::openSettingsPopup(Mod::get(), true);
}

class $modify(MainMenuWithImageButton, MenuLayer) {
public:
    bool init() override;
    void onSettingsButton(cocos2d::CCObject*);
};

bool MainMenuWithImageButton::init() {
    if (!MenuLayer::init()) return false;

    auto sprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");

    auto button = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        menu_selector(MainMenuWithImageButton::onSettingsButton)
    );

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    button->setPosition({ 40.f, winSize.height / 2 }); // Top-left

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(button);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);

    return true;
}

void MainMenuWithImageButton::onSettingsButton(cocos2d::CCObject*) {
     geode::openSettingsPopup(Mod::get(), true);
}
