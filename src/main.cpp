// i copied the excat code from geode docs
// this doesnt really do anything
// exccept for make it take a longer time to compile
#include <Geode/loader/SettingV3.hpp>
#include <Geode/loader/Mod.hpp>

using namespace geode::prelude;

enum class MyCustomEnum {
    ValidEnumValue,
    OtherValidEnumValue,
};

template <>
struct matjson::Serialize<MyCustomEnum> {
    static matjson::Value toJson(MyCustomEnum value) {
        return matjson::Value(static_cast<int>(value));
    }

    static MyCustomEnum fromJson(const matjson::Value& val) {
        auto res = val.tryGet<int>();
        if (!res) {
            throw std::runtime_error("Failed to parse MyCustomEnum: not an int");
        }
        int v = *res;
        switch (v) {
            case 0: return MyCustomEnum::ValidEnumValue;
            case 1: return MyCustomEnum::OtherValidEnumValue;
            default: throw std::runtime_error("Invalid value for MyCustomEnum");
        }
    }
};

class MyCustomSettingV3 : public SettingBaseValueV3<MyCustomEnum> {
protected:
    bool m_splorgy = false;

public:
    static Result<std::shared_ptr<SettingV3>> parse(
        std::string const& key,
        std::string const& modID,
        matjson::Value const& json
    ) {
        auto res = std::make_shared<MyCustomSettingV3>();

        auto root = checkJson(json, "MyCustomSettingV3");

        res->parseBaseProperties(key, modID, root);

        root.has("splorgy").into(res->m_splorgy);

        root.checkUnknownKeys();

        return root.ok(std::static_pointer_cast<SettingV3>(res));
    }

    SettingNodeV3* createNode(float width) override;
};

template <>
struct geode::SettingTypeForValueType<MyCustomEnum> {
    using SettingType = MyCustomSettingV3;
};

class MyCustomSettingNodeV3 : public SettingValueNodeV3<MyCustomSettingV3> {
protected:
    std::vector<CCMenuItemToggler*> m_toggles;

    bool init(std::shared_ptr<MyCustomSettingV3> setting, float width) {
        if (!SettingValueNodeV3::init(setting, width))
            return false;

        for (auto value : {
            std::make_pair(MyCustomEnum::ValidEnumValue, "GJ_starsIcon_001.png"),
            std::make_pair(MyCustomEnum::OtherValidEnumValue, "currencyOrbIcon_001.png"),
        }) {
            auto offSpr = CCSprite::createWithSpriteFrameName(value.second);
            offSpr->setOpacity(90);
            auto onSpr = CCSprite::createWithSpriteFrameName(value.second);
            auto toggle = CCMenuItemToggler::create(
                offSpr, onSpr, this, menu_selector(MyCustomSettingNodeV3::onToggle)
            );
            toggle->m_notClickable = true;
            toggle->setTag(static_cast<int>(value.first));
            m_toggles.push_back(toggle);

            this->getButtonMenu()->addChild(toggle);
        }

        this->getButtonMenu()->setContentWidth(40);
        this->getButtonMenu()->setLayout(RowLayout::create());

        this->updateState(nullptr);

        return true;
    }

    void updateState(CCNode* invoker) override {
        SettingValueNodeV3::updateState(invoker);

        auto shouldEnable = this->getSetting()->shouldEnable();

        for (auto toggle : m_toggles) {
            toggle->toggle(toggle->getTag() == static_cast<int>(this->getValue()));

            toggle->setEnabled(shouldEnable);
            toggle->setCascadeColorEnabled(true);
            toggle->setCascadeOpacityEnabled(true);
            toggle->setOpacity(shouldEnable ? 255 : 155);
            toggle->setColor(shouldEnable ? ccWHITE : ccGRAY);
        }
    }
    void onToggle(CCObject* sender) {
        this->setValue(
            static_cast<MyCustomEnum>(sender->getTag()),
            static_cast<CCNode*>(sender)
        );
    }

public:
    static MyCustomSettingNodeV3* create(std::shared_ptr<MyCustomSettingV3> setting, float width) {
        auto ret = new MyCustomSettingNodeV3();
        if (ret && ret->init(setting, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

SettingNodeV3* MyCustomSettingV3::createNode(float width) {
    return MyCustomSettingNodeV3::create(
        std::static_pointer_cast<MyCustomSettingV3>(shared_from_this()),
        width
    );
}

$execute {
    (void)Mod::get()->registerCustomSettingType("my-awesome-type", &MyCustomSettingV3::parse);
}
