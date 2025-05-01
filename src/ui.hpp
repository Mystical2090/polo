#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MyPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        this->setTitle("Hi mom!");

        m_bgLayer->setColor({0, 0, 0});
        m_bgLayer->setOpacity(255);

        auto outline = CCDrawNode::create();
        auto size = m_bgLayer->getContentSize();
        ccColor4F borderColor = {0.4f, 0.8f, 1.0f, 1.0f}; // RGBA
        outline->drawRect({0, 0}, {size.width, size.height}, borderColor);
        outline->setPosition({0, 0});
        m_bgLayer->addChild(outline, 999);

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        label->setColor({100, 200, 255});
        m_mainLayer->addChildAtPosition(label, Anchor::Center);

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
