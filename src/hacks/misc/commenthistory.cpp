#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
public:
    void loadPageFromUserInfo(GJUserScore* p0) {
        if (Mod::get()->getSettings()->getValue<bool>("disable_comment_history")) {
            auto state = p0->m_commentHistoryStatus;
            p0->m_commentHistoryStatus = 0;

            ProfilePage::loadPageFromUserInfo(p0);

            p0->m_commentHistoryStatus = state;
        }
        else {
            ProfilePage::loadPageFromUserInfo(p0);
        }
    }
};
