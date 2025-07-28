#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

enum SettingPage {
    Tab1,
    Tab2,
    Tab3,
    Tab4
};

enum SettingCellType {
    Default,
    Button
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

    static bool isLabel1Enabled() { return GameManager::get()->getGameVariable("label1"); }
    static bool isLabel2Enabled() { return GameManager::get()->getGameVariable("label2"); }
    static bool isLabel3Enabled() { return GameManager::get()->getGameVariable("label3"); }
    static bool isLabel4Enabled() { return GameManager::get()->getGameVariable("label4"); }
};

inline bool label1Enabled() { return SettingsLayer::isLabel1Enabled(); }
inline bool label2;
