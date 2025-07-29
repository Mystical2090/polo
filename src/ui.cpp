#include "ui.hpp"

SearchPopup* SearchPopup::create(SearchCB callback) {
    auto ret = new SearchPopup();
    if (ret && ret->initAnchored(210.f, 130.f, callback)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool SearchPopup::setup(SearchCB callback) {
    m_callback = callback;
    this->setTitle("Search");
    this->setID("SearchPopup"_spr);
    this->m_bgSprite->setID("background");
    this->m_title->setID("title");
    this->m_buttonMenu->setID("button-menu");
    this->m_mainLayer->setID("main-layer");
    this->m_closeBtn->setID("close-button");

    m_input = TextInput::create(150.f, "Query here");
    m_input->setID("search-input");
    m_mainLayer->addChildAtPosition(m_input, Anchor::Center, {0, 7.5f});

    auto btn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Search"), this, menu_selector(SearchPopup::onSearch)
    );
    btn->setID("search-button");
    m_buttonMenu->addChildAtPosition(btn, Anchor::Center, {0, 25});

    return true;
}

void SearchPopup::onSearch(CCObject* sender) {
    m_callback(
        m_input->getString()
    );
    m_closeBtn->activate();
}

SettingCell* SettingCell::create(std::string name, std::string gv, SettingCellType type) {
    auto ret = new SettingCell();
    if (ret && ret->init(name, gv, type)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool SettingCell::init(std::string name, std::string gv, SettingCellType type) {
    setID(name);
    m_name = name;
    m_gameVariable = gv;
    m_type = type;

    auto nameLabel = CCLabelBMFont::create(
        name.c_str(), "bigFont.fnt"
    );
    nameLabel->setID("name-label");
    nameLabel->limitLabelWidth(15.f, 0.9f, 0.5f);
    
    auto menu = CCMenu::create();
    menu->setID("button-menu");

    CCSprite* spr;
    CCMenuItemSpriteExtra* btn;

    auto gameManager = GameManager::sharedState();

    switch (type) {
        case Default:
            m_toggler = CCMenuItemToggler::createWithStandardSprites(
                this,
                menu_selector(SettingCell::onCheckboxToggled),
                0.75f
            );
            m_toggler->setID("toggler");
            m_toggler->toggle(
                GameManager::get()->getGameVariable(gv.c_str())
            );

            spr = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
            spr->setScale(0.65f);
            btn = CCMenuItemSpriteExtra::create(
                spr, this, menu_selector(SettingCell::onInfo)
            );
            btn->setID("info-button");
            btn->setPositionX(-35.f);
            
            menu->addChild(btn);
            menu->addChild(m_toggler);
            break;
        case Button:
            spr = ButtonSprite::create("Yes", "goldFont.fnt", "GJ_button_05.png");
            spr->setScale(0.5f);
            btn = CCMenuItemSpriteExtra::create(
                spr, this, menu_selector(SettingCell::onButton)
            );
            btn->setID("button");
            btn->setPositionX(-10.f);
            menu->addChild(btn);
            break;
    }

    this->addChildAtPosition(nameLabel, Anchor::Left, ccp(10.f, 0.f));
    this->addChildAtPosition(menu, Anchor::Right, ccp(-25.f, 0.f));

    nameLabel->setAnchorPoint({ 0.f, 0.5f });

    this->setContentSize({
        365.f,
        30.f
    });
    
    return true;
}

void SettingCell::onButton(CCObject* sender) {
    log::info("Button clicked for: {}", m_name);
}

void SettingCell::onCheckboxToggled(CCObject* sender) {
    GameManager::get()->setGameVariable(m_gameVariable.c_str(), !m_toggler->isOn());
    log::debug("set gv_{} to {}", m_gameVariable, !m_toggler->isOn());
}

std::string descForGV(std::string gv) {
    std::map<std::string, std::string> descriptions = {
        {"label1_enabled", "Controls Label 1 functionality"},
        {"label2_enabled", "Controls Label 2 functionality"},
        {"label3_enabled", "Controls Label 3 functionality"},
        {"label4_enabled", "Controls Label 4 functionality"},
    };

    if (descriptions.find(gv) != descriptions.end()) {
        return descriptions.at(gv);
    }
    return "No description available.";
}

void SettingCell::onInfo(CCObject* sender) {
    FLAlertLayer::create(
        m_name.c_str(),
        descForGV(m_gameVariable).c_str(),
        "OK"
    )->show();
}

SettingsLayer* SettingsLayer::create() {
    auto ret = new SettingsLayer();
    if (ret && ret->initAnchored(500.f, 280.f)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

CCSprite* createCategoryBtnSprite(std::string name, bool isSelected = false) {
    auto sprite = CCSprite::createWithSpriteFrameName(
        isSelected ? "GJ_longBtn02_001.png" : "GJ_longBtn01_001.png"
    );
    auto text = CCLabelBMFont::create(name.c_str(), "bigFont.fnt");
    text->limitLabelWidth(75.f, 0.7f, 0.1f);
    sprite->setScale(1.f);
    sprite->addChildAtPosition(text, Anchor::Center);
    text->setPositionY(text->getPositionY() + 1.5f);
    return sprite;
}

CCMenuItemSpriteExtra* createCategoryBtn(std::string name, CCObject* target, SettingPage page, SEL_MenuHandler callback) {
    auto btn = CCMenuItemSpriteExtra::create(
        createCategoryBtnSprite(name), target, callback
    );
    btn->setUserObject(CCInteger::create(page));
    btn->setID(name);
    return btn;
}

bool SettingsLayer::setup() {
    this->setID("SettingsLayer"_spr);
    this->m_bgSprite->setID("background");
    this->m_buttonMenu->setID("button-menu");
    this->m_mainLayer->setID("main-layer");
    this->m_closeBtn->setID("close-button");
    m_noElasticity = true;
    auto bg = CCScale9Sprite::create("square02b_001.png");
    bg->setID("tab-background");
    bg->setContentSize({
    	100.f, 245.f
    });
    bg->setColor(ccc3(0,0,0));
    bg->setOpacity(75);

    auto menu = CCMenu::create();

    #define CATEGORY_BTN(name, page) menu->addChild( \
        createCategoryBtn(name, this, page, menu_selector(SettingsLayer::onCategoryBtn)) \
    );

    CATEGORY_BTN("Tab2", SettingPage::Tab2)
    CATEGORY_BTN("Tab3", SettingPage::Tab3)
    CATEGORY_BTN("Tab4", SettingPage::Tab4)

    menu->setLayout(
        ColumnLayout::create()
            ->setAxisAlignment(AxisAlignment::Even)
            ->setAxisReverse(true)
    );
    menu->setID("tab-menu");
    menu->setContentSize(bg->getContentSize());
    menu->setPosition(bg->getPosition());
    menu->setAnchorPoint({ 0.f, 0.f });
    menu->updateLayout();
    menu->setPositionX(
        bg->getContentWidth() / 2 - menu->getContentWidth() / 2
    );
    bg->addChild(menu);

    m_mainLayer->addChildAtPosition(bg, Anchor::Left, ccp(65.f, 0.f));

    switchPage(SettingPage::Tab2, true, typeinfo_cast<CCMenuItemSpriteExtra*>(this->getChildByIDRecursive("Tab2")));

    auto searchBtnSpr = CCSprite::createWithSpriteFrameName("gj_findBtn_001.png");
    auto searchBtn = CCMenuItemSpriteExtra::create(
        searchBtnSpr, this, menu_selector(SettingsLayer::onSearchBtn)
    );
    searchBtn->setID("search-button");

    auto searchBtnOffSpr = CCSprite::createWithSpriteFrameName("gj_findBtnOff_001.png");
    m_searchClearBtn = CCMenuItemSpriteExtra::create(
        searchBtnOffSpr, this, menu_selector(SettingsLayer::onClearSearch)
    );
    m_searchClearBtn->setID("clear-search-button");

    m_searchClearBtn->setVisible(false);

    auto searchMenu = CCMenu::create();
    searchMenu->setLayout(
        RowLayout::create()
            ->setAxisAlignment(AxisAlignment::Start)
            ->setAxisReverse(true)
    );
    searchMenu->setContentSize({70, 35});
    searchMenu->setAnchorPoint({1, 0.5});
    searchMenu->addChild(searchBtn);
    searchMenu->addChild(m_searchClearBtn);
    searchMenu->updateLayout();
    searchMenu->setID("search-menu");
    m_mainLayer->addChildAtPosition(searchMenu, Anchor::TopRight, {15, 0});

    return true;
}

void SettingsLayer::onClearSearch(CCObject* sender) {
    auto page = static_cast<SettingPage>(static_cast<CCInteger*>(
            m_currentBtn->getUserObject()
        )->getValue());

    switchPage(page, false, m_currentBtn);
    m_searchClearBtn->setVisible(false);
}

void SettingsLayer::onSearchBtn(CCObject* sender) {
    SearchPopup::create([this](std::string query) {
        auto newList = CCArray::create();

        using namespace geode::utils::string;

        auto page = static_cast<SettingPage>(static_cast<CCInteger*>(
            m_currentBtn->getUserObject()
        )->getValue());

        switchPage(page, false, m_currentBtn);

        if (query == "") {
            m_searchClearBtn->setVisible(false);
            return;
        }

        m_searchClearBtn->setVisible(true);

        for (auto cell : CCArrayExt<SettingCell*>(m_listItems)) {
            if (toLower(cell->m_name).find(toLower(query)) != std::string::npos) {
                newList->addObject(
                    SettingCell::create(cell->m_name, cell->m_gameVariable, cell->m_type)
                );
            }
        }

        m_listItems = newList;
        m_border->removeFromParent();
        this->refreshList();
    })->show();
}

void SettingsLayer::onCategoryBtn(CCObject* sender) {
    auto node = static_cast<CCMenuItemSpriteExtra*>(sender);
    int page = static_cast<CCInteger*>(
        node->getUserObject()
    )->getValue();

    switchPage(static_cast<SettingPage>(page), false, node);
}

void SettingsLayer::switchPage(SettingPage page, bool isFirstRun, CCMenuItemSpriteExtra* btn) {
    m_listItems = CCArray::create();
    if(m_searchClearBtn){
        m_searchClearBtn->setVisible(false);
    }
    #define SETTING(name, gv) m_listItems->addObject( \
        SettingCell::create(name, gv) \
    );
    #define SETTING_WITH_TYPE(name, gv, type) m_listItems->addObject( \
        SettingCell::create(name, gv, type) \
    );

    switch (page) {
        case Tab2:
            SETTING("Label2", "label2_enabled")
            break;
        case Tab3:
            SETTING("Label3", "label3_enabled")
            break;
        case Tab4:
            SETTING("Label4", "label4_enabled")
            break;
    }
    
    if (!isFirstRun) {
        m_border->removeFromParent();
    }
    
    this->refreshList();

    if (m_currentBtn) {
        m_currentBtn->setSprite(
            createCategoryBtnSprite(m_currentBtn->getID())
        );
    }
    btn->setSprite(
        createCategoryBtnSprite(btn->getID(), true)
    );
    m_currentBtn = btn;
}

void SettingsLayer::refreshList() {
    ListView* listView = ListView::create(m_listItems, 30.f, 365.f, 245.f);
    listView->setID("list-view");
    listView->m_tableView->setID("table-view");
    listView->m_tableView->m_contentLayer->setID("content-layer");

    m_border = Border::create(listView, {0, 0, 0, 75}, {365.f, 245.f});
    m_border->setID("list-border");
    if(CCScale9Sprite* borderSprite = typeinfo_cast<CCScale9Sprite*>(m_border->getChildByID("geode.loader/border_sprite"))) {
        float scaleFactor = 1.5f;
        borderSprite->setContentSize(CCSize{borderSprite->getContentSize().width, borderSprite->getContentSize().height + 1} / scaleFactor);
        borderSprite->setScale(scaleFactor);
        borderSprite->setPositionY(-0.5);
    }
    m_border->ignoreAnchorPointForPosition(false);
    
    for (auto cell : CCArrayExt<CCNode*>(m_listItems)) {
        cell->setContentSize({
            365.f,
            30.f
        });
        cell->updateLayout();
    }
    
    m_mainLayer->addChildAtPosition(m_border, Anchor::Right, ccp(-195.f, 0.f));
}

#ifndef GEODE_IS_IOS
#include <Geode/modify/CCKeyboardDispatcher.hpp>
class $modify(ImGuiKeybindHook, cocos2d::CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
        if (key == cocos2d::enumKeyCodes::KEY_Tab && isKeyDown) {
            SettingsLayer::create()->show();
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
    }
};
#endif
