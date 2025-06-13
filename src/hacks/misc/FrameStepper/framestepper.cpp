#include "framestepper.hpp"

#define MAX_STORED_STATES 240

void SteppedBaseGameLayer::storeState() {
    if (!typeinfo_cast<PlayLayer*>(this))
        return;

    if (m_player1 && m_player1->m_isDead)
        return;

    auto fields = m_fields.self();

    if (fields->states.size() + 1 > MAX_STORED_STATES)
        fields->states.erase(fields->states.begin());

    auto cp = as<PlayLayer*>(base_cast<GJBaseGameLayer*>(this))->createCheckpoint();
    fields->states.push_back(cp);

    as<SteppedUILayer*>(m_uiLayer)->updateUI();
}

void SteppedBaseGameLayer::restoreState() {
    if (!typeinfo_cast<PlayLayer*>(this))
        return;

    auto fields = m_fields.self();
    if (fields->states.empty())
        return;

    if (auto cp = fields->states.back()) {
        auto pl = as<PlayLayer*>(base_cast<GJBaseGameLayer*>(this));
        pl->storeCheckpoint(cp);
        pl->resetLevel();
        pl->removeCheckpoint(false);
    }

    fields->states.pop_back();

    as<SteppedUILayer*>(m_uiLayer)->updateUI();
}

void SteppedBaseGameLayer::checkRepellPlayer() {
    GJBaseGameLayer::checkRepellPlayer();
    storeState();
}

void SteppedBaseGameLayer::update(float dt) {
    if (getPausedUpdate())
        return;

    GJBaseGameLayer::update(dt);
}

void SteppedBaseGameLayer::stepFrame() {
    m_fields->steppingUpdate = true;
    GJBaseGameLayer::update(1.0f / 240.0f);
    m_fields->steppingUpdate = false;
}

bool SteppedBaseGameLayer::getPausedUpdate() {
    return m_fields->steppingUpdate ? false : m_fields->paused;
}

bool SteppedUILayer::init(GJBaseGameLayer* bgl) {
    if (!UILayer::init(bgl))
        return false;

    auto menu = CCMenu::create();
    menu->ignoreAnchorPointForPosition(false);
    menu->setContentSize({135, 40});

    auto bg = CCScale9Sprite::create("square02_001.png");
    bg->setScale(1.0f / 3);
    bg->setContentSize(menu->getContentSize() * 3);
    bg->setAnchorPoint(CCPointZero);
    bg->setOpacity(100);

    menu->setPosition({135 / 2 + 25, 40 / 2 + 25});

    m_fields->pause = RepeatableMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_pauseBtn_001.png"),
        this,
        menu_selector(SteppedUILayer::onTogglePaused)
    );
    m_fields->pause->getNormalImage()->setScale(0.8f);

    m_fields->prev = RepeatableMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"),
        this,
        menu_selector(SteppedUILayer::onPreviousFrame)
    );
    m_fields->prev->getNormalImage()->setScale(0.8f);

    auto next = RepeatableMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"),
        this,
        menu_selector(SteppedUILayer::onStepFrame)
    );
    next->getNormalImage()->setScale(0.8f);
    as<CCSprite*>(next->getNormalImage())->setFlipX(true);

    menu->addChildAtPosition(m_fields->pause, Anchor::Center);
    menu->addChildAtPosition(next, Anchor::Right, { -18, 0 });
    menu->addChildAtPosition(m_fields->prev, Anchor::Left, { 18, 0 });
    menu->addChild(bg, -1);

    this->addChild(menu, 69);

    m_fields->menu = menu;
    m_fields->next = next;

    updateUI();

    return true;
}

void SteppedUILayer::onTogglePaused(CCObject*) {
    if (!m_gameLayer) return;

    auto fields = as<SteppedBaseGameLayer*>(m_gameLayer)->m_fields.self();
    fields->paused = !fields->paused;

#ifdef GEODE_IS_MACOS
    FMODAudioEngine::get()->pauseAllMusic(fields->paused);
#else
    if (fields->paused) {
        for (auto& [id, channel] : FMODAudioEngine::get()->m_fmodMusic) {
            auto ch = FMODAudioEngine::get()->channelForChannelID(channel.m_channelID);
            if (ch)
                ch->setPaused(true);
        }
    } else {
        FMODAudioEngine::get()->resumeAllMusic();
    }
#endif

    updateUI();
}

void SteppedUILayer::onPreviousFrame(CCObject*) {
    if (m_gameLayer)
        as<SteppedBaseGameLayer*>(m_gameLayer)->restoreState();

    updateUI();
}

void SteppedUILayer::onStepFrame(CCObject*) {
    if (m_gameLayer)
        as<SteppedBaseGameLayer*>(m_gameLayer)->stepFrame();

    updateUI();
}

void SteppedUILayer::updateUI() {
    if (!m_gameLayer)
        return;

    auto layer = as<SteppedBaseGameLayer*>(m_gameLayer);
    auto states = layer->m_fields->states;

    bool hasStates = !states.empty();
    m_fields->prev->setEnabled(hasStates);
    m_fields->prev->setColor(hasStates ? ccWHITE : ccc3(150, 150, 150));

    if (!typeinfo_cast<PlayLayer*>(m_gameLayer)) {
        m_fields->prev->setEnabled(false);
        m_fields->prev->setColor(ccc3(150, 150, 150));
    }

    const char* spriteName = layer->m_fields->paused ? "GJ_playEditorBtn_001.png" : "GJ_pauseEditorBtn_001.png";
    as<CCSprite*>(m_fields->pause->getNormalImage())->setDisplayFrame(
        CCSpriteFrameCache::get()->spriteFrameByName(spriteName)
    );

    m_fields->menu->setVisible(Mod::get()->getSettingValue<bool>("enabled", true));
    m_fields->menu->setPosition({135 / 2 + 25, 40 / 2 + 25});
    m_fields->menu->setScale(1.0f);
}

$execute {
    Loader::get()->queueInMainThread([] {
        auto mod = Mod::get();

        if (auto bgl = GJBaseGameLayer::get()) {
            if (auto ui = as<SteppedUILayer*>(bgl->m_uiLayer)) {
                ui->m_fields->menu->setVisible(mod->getSettingValue<bool>("enabled", true));
                ui->updateUI();
            }
        }
    });
}
