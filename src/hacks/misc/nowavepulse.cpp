#include <Geode/Geode.hpp>
#include <Geode/modify/HardStreak.hpp>

using namespace geode::prelude;

class $modify(HardStreak) {
    void updateStroke(float p0) {
        float pulseValue = Mod::get()->getSettingValue<float>("wave-pulse-size");

        m_pulseSize = pulseValue + 0.5f;

        HardStreak::updateStroke(p0);
    }
};
