#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(AutoClickHack, PlayLayer) {
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
                dispatcher->touches(touchSet, nullptr, cocos2d::ccTouchBegan);
                dispatcher->touches(touchSet, nullptr, cocos2d::ccTouchEnded);
            }
        }
        PlayLayer::update(dt);
    }
};
