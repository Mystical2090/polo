#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

enum SettingPage {
    Player,
    Cosmetic,
    Misc,
    Credits
};

enum SettingCellType {
    Default,
    Button,
    Credit
};

using SearchCB = std::function<void(std::string)>;

class SearchPopup : public geode::Popup<SearchCB> {
protected:
    TextInput* m_input;
    SearchCB m_callback;
    bool setup(SearchCB) override;
    void onSearch(CCObject*);
public:
    static SearchPopup* create(SearchCB callback);
};

class SettingCell : public CCNode {
protected:
    CCMenuItemToggler* m_toggler;
    bool init(std::string name, std::string gv, SettingCellType type);
    void onCheckboxToggled(CCObject* sender);
    void onButton(CCObject*);
    void onInfo(CCObject*);
public:
    std::string m_name;
    std::string m_gameVariable;
    SettingCellType m_type;
    static SettingCell* create(std::string name, std::string gv, SettingCellType type = SettingCellType::Default);
};

class SettingsLayer : public geode::Popup<> {
protected:
    CCArray* m_listItems;
    Border* m_border;
    CCMenuItemSpriteExtra* m_currentBtn;
    CCMenuItemSpriteExtra* m_searchClearBtn;
    bool setup() override;
    void createSettingCheckbox(
        std::string name,
        std::string gv
    );
    void switchPage(SettingPage, bool, CCMenuItemSpriteExtra*);
    void onCategoryBtn(CCObject*);
    void onSearchBtn(CCObject*);
    void onClearSearch(CCObject*);
    void refreshList();
public:
    static SettingsLayer* create();

    static bool isNoclipEnabled() { return GameManager::get()->getGameVariable("noclip_enabled"); }
    static bool isAutoclickerEnabled() { return GameManager::get()->getGameVariable("autoclicker_enabled"); }
    static bool isJumpHackEnabled() { return GameManager::get()->getGameVariable("jumphack_enabled"); }
    static bool isIgnoreInputsEnabled() { return GameManager::get()->getGameVariable("ignore_inputs_enabled"); }
};

inline bool noclipEnabled() { return SettingsLayer::isNoclipEnabled(); }
inline bool autoclickerEnabled() { return SettingsLayer::isAutoclickerEnabled(); }
inline bool jumpHackEnabled() { return SettingsLayer::isJumpHackEnabled(); }
inline bool ignoreInputsEnabled() { return SettingsLayer::isIgnoreInputsEnabled(); }
