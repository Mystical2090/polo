#pragma once

#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class PoloUI : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        this->setTitle("Polo Mod Menu");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        m_mainLayer->addChildAtPosition(label, Anchor::Center);

        return true;
    }

public:
    static PoloUI* create(std::string const& text) {
        auto ret = new PoloUI();
        if (ret->initAnchored(240.f, 160.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};
