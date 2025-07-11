#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

extern bool rainbowIconsEnabled;

struct RainbowSettings {
    bool enable;
};

RainbowSettings getModSettings() {
    return {
        rainbowIconsEnabled
    };
}

float g_hue = 0;

void HSVtoRGB(float& r, float& g, float& b, float h, float, float) {
    float c = 1, x = c * (1 - fabs(fmod(h / 60.0, 2) - 1)), m = 0;

    if (h < 60)      { r = c; g = x; b = 0; }
    else if (h < 120){ r = x; g = c; b = 0; }
    else if (h < 180){ r = 0; g = c; b = x; }
    else if (h < 240){ r = 0; g = x; b = c; }
    else if (h < 300){ r = x; g = 0; b = c; }
    else             { r = c; g = 0; b = x; }

    r += m; g += m; b += m;
}

cocos2d::_ccColor3B getRainbow(float offset) {
    float r, g, b;
    HSVtoRGB(r, g, b, fmod(g_hue + offset, 360), 1.0f, 1.0f);
    return { static_cast<unsigned char>(r * 255),
             static_cast<unsigned char>(g * 255),
             static_cast<unsigned char>(b * 255) };
}

void updateHue() {
    if (++g_hue >= 360) g_hue = 0;
}

void applySimpleColor(PlayerObject* player, const cocos2d::_ccColor3B& color) {
    if (!player) return;
    player->setColor(color);
    player->setSecondColor(color);
    player->m_glowColor = color;
    player->updateGlowColor();
}

class $modify(MyPlayLayer, PlayLayer) {
    void postUpdate(float p0) {
        PlayLayer::postUpdate(p0);
        auto settings = getModSettings();
        if (!settings.enable) return;

        updateHue();
        auto color = getRainbow(0);
        applySimpleColor(m_player1, color);
        applySimpleColor(m_player2, color);
    }
};

class $modify(MyLevelEditorLayer, LevelEditorLayer) {
    void postUpdate(float p0) {
        LevelEditorLayer::postUpdate(p0);
        auto settings = getModSettings();
        if (!settings.enable) return;

        updateHue();
        auto color = getRainbow(0);
        applySimpleColor(m_player1, color);
        if (m_player2) applySimpleColor(m_player2, color);
    }
};
