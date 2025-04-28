#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(AutoClicker, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-click")) {
            if (this->m_player1) {
                auto playerPos = m_player1->getPosition();
                
                auto touch = new cocos2d::CCTouch();
                touch->autorelease();
                
                touch->setTouchInfo(0, playerPos.x, playerPos.y);
                
                auto touchSet = cocos2d::CCSet::create();
                touchSet->addObject(touch);
                
                auto dispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();
                dispatcher->touches(touchSet, nullptr, 0); // CCTOUCHBEGAN = 0
                dispatcher->touches(touchSet, nullptr, 2); // CCTOUCHENDED = 2
            }
        }
        PlayLayer::update(dt);
    }
};
