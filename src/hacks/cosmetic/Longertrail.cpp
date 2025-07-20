
#include <Geode/modify/CCMotionStreak.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

extern bool LongerTrail;
class $modify (CCLongerStreak, CCMotionStreak)
{
    struct Fields
    {
        bool shouldStreakBeLonger = false;
    };

    virtual void update(float delta)
    {
        if (LongerTrail)
            delta /= 3;

        CCMotionStreak::update(delta);
    }

    static void onModify(auto& self)
    {
        (void)self.setHookPriorityPost("cocos2d::CCMotionStreak::update", Priority::Last);
    }
};

class $modify (PlayerObject)
{
    bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
    {
        if (!PlayerObject::init(player, ship, gameLayer, layer, playLayer))
            return false;

        as<CCLongerStreak*>(m_regularTrail)->m_fields->shouldStreakBeLonger = true;

        return true;
    }
};
