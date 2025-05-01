#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    this->setTitle("Polo Mod Menu");

    auto size = this->getContentSize();
    cocos2d::CCSize size = this->getContentSize();

    cocos2d::CCLayerColor* bg = CCLayerColor::create({0, 0, 0, 255}, size.width, size.height);
    bg->setPosition({0, 0});
    m_mainLayer->addChild(bg, -1);

    cocos2d::CCDrawNode* outline = CCDrawNode::create();
    ccColor4F borderColor = {0.4f, 0.8f, 1.0f, 1.0f};
    float borderWidth = 2.0f;
    ccColor4F fillColor = {0, 0, 0, 0};

    outline->drawRect({0, 0}, {size.width, size.height}, borderColor, borderWidth, fillColor);
    bg->addChild(outline);

        return true;
    }

public:
    static MyPopup* create(std::string const& text) {
        auto ret = new MyPopup();
        if (ret->initAnchored(240.f, 160.f, text)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
};
