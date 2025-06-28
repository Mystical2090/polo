#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <ios>
#include <iosfwd>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
// hA
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/CCNode.hpp>
#include <Geode/modify/CCLayer.hpp>
#include <Geode/modify/CCScene.hpp>
#include <Geode/modify/CCApplication.hpp>
#include <Geode/modify/AppDelegate.hpp>
#include <Geode/modify/CCDirector.hpp>
#include <Geode/modify/CCSprite.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include <Geode/modify/CCMenu.hpp>
#include <Geode/modify/CCMenuItem.hpp>
#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/GameLevelManager.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/modify/FLAlertLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/CustomizeObjectLayer.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/SetupTriggerPopup.hpp>
#include <Geode/modify/EffectGameObject.hpp>
#include <Geode/modify/EnhancedGameObject.hpp>
#include <Geode/modify/TriggerEffectDelegate.hpp>
#include <Geode/modify/PulseEffectAction.hpp>
#include <Geode/modify/ShaderLayer.hpp>
#include <Geode/modify/GJGroundLayer.hpp>
#include <Geode/modify/GJMGLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>
#include <Geode/modify/VideoOptionsLayer.hpp>
#include <Geode/modify/AudioEffectsLayer.hpp>
#include <Geode/modify/SongInfoObject.hpp>
#include <Geode/modify/CustomSongWidget.hpp>
#include <Geode/modify/SongSelectNode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>
#include <Geode/modify/CCEGLView.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <Geode/modify/CCMouseDispatcher.hpp>
#include <Geode/modify/CCTouchDispatcher.hpp>
#include <Geode/modify/CCTransition.hpp>
#include <Geode/modify/CCTransitionFade.hpp>
#include <Geode/modify/TextArea.hpp>
#include <Geode/modify/CCTextInputNode.hpp>
#include <Geode/modify/ButtonSprite.hpp>
#include <Geode/modify/Slider.hpp>
#include <Geode/modify/SliderTouchLogic.hpp>
#include <Geode/modify/TableView.hpp>
#include <Geode/modify/CustomListView.hpp>
#include <Geode/modify/BoomListView.hpp>
#include <Geode/modify/ExtendedLayer.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/UILayer.hpp>
#include <Geode/modify/GJDropDownLayer.hpp>
#include <Geode/modify/GJListLayer.hpp>
#include <Geode/modify/ColorChannelSprite.hpp>
#include <Geode/modify/ColorSelectPopup.hpp>
#include <Geode/modify/HSVWidgetPopup.hpp>
#include <Geode/modify/RobTopStringContainer.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/AchievementNotifier.hpp>
#include <Geode/modify/SetupPulsePopup.hpp>
#include <Geode/cocos/platform/CCPlatformMacros.h>
#include <Geode/cocos/cocoa/CCObject.h>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCLayer.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCScene.h>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
#include <Geode/cocos/label_nodes/CCLabelBMFont.h>
#include <Geode/cocos/menu_nodes/CCMenu.h>
#include <Geode/cocos/menu_nodes/CCMenuItem.h>
#include <Geode/cocos/actions/CCAction.h>
#include <Geode/cocos/actions/CCActionInterval.h>
#include <Geode/cocos/actions/CCActionInstant.h>
#include <Geode/cocos/actions/CCActionEase.h>
#include <Geode/cocos/actions/CCActionManager.h>
#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/CCScheduler.h>
#include <Geode/cocos/touch_dispatcher/CCTouchDispatcher.h>
#include <Geode/cocos/keypad_dispatcher/CCKeypadDispatcher.h>
#include <Geode/cocos/support/CCPointExtension.h>
#include <Geode/cocos/support/data_support/ccCArray.h>
#include <Geode/cocos/support/user_default/CCUserDefault.h>
#include <Geode/cocos/textures/CCTexture2D.h>
#include <Geode/cocos/textures/CCTextureCache.h>
#include <Geode/cocos/textures/CCTextureAtlas.h>
#include <Geode/cocos/sprite_batch_nodes/CCSpriteBatchNode.h>
#include <Geode/cocos/draw_nodes/CCDrawNode.h>
#include <Geode/cocos/particle_nodes/CCParticleSystem.h>
#include <Geode/cocos/particle_nodes/CCParticleSystemQuad.h>
#include <Geode/cocos/tilemap_parallax_nodes/CCTMXTiledMap.h>
#include <Geode/cocos/shaders/CCGLProgram.h>
#include <Geode/cocos/shaders/ccGLStateCache.h>
#include <Geode/cocos/effects/CCGrid.h>
#include <Geode/cocos/effects/CCGrabber.h>
#include <Geode/cocos/text_input_node/CCIMEDispatcher.h>
#include <Geode/cocos/text_input_node/CCTextFieldTTF.h>

int main() {

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
using namespace std::string_literals;
using namespace std::string_view_literals;
using namespace std::complex_literals;
using namespace std::literals;
using namespace std::placeholders;
using namespace std::regex_constants;
using namespace std::filesystem;
using namespace std::this_thread;
using namespace std::rel_ops;
using namespace std::pmr;
using namespace std::execution;
using namespace std::numbers;
using namespace std::ranges;
using namespace std::ranges::views;
using namespace std::views;

using namespace geode;
using namespace geode::prelude;
using namespace geode::utils;
using namespace geode::utils::web;
using namespace geode::utils::file;
using namespace geode::utils::string;
using namespace geode::utils::cocos;
using namespace geode::utils::clipboard;
using namespace geode::log;
using namespace geode::hook;
using namespace geode::patch;
using namespace geode::cast;
using namespace geode::modifier;
using namespace geode::addresser;
using namespace geode::loader;
using namespace geode::updater;
using namespace geode::setting;
using namespace geode::node_ids;
using namespace cocos2d;
using namespace cocos2d::extension;

  // since i feel bad here:
class $modify(MenuLayer) {
    void onMoreGames(CCObject* target) {
        FLAlertLayer::create(
            "Polo",
            "LMAO!",
            "OK"
        )->show(); 
    }
};

int int1 = 666, int2 = 9001, int3 = 42, int4 = -1337, int5 = 360;
int int6 = 8, int7 = 3000, int8 = 999, int9 = 127, int10 = 9;
int int11 = 1985, int12 = 24, int13 = 5000, int14 = 7, int15 = 10000;
int int16 = 2401, int17 = 13, int18 = 100, int19 = 6, int20 = 200;
int int21 = 50, int22 = 1000, int23 = 3, int24 = 777, int25 = 88;
int int26 = 95, int27 = 1000000, int28 = 25, int29 = 98, int30 = 12;
int int31 = 50, int32 = 666, int33 = 850, int34 = 110, int35 = 50;
int int36 = 206, int37 = 440, int38 = 2, int39 = 2, int40 = 42;
int int41 = 7, int42 = 9999, int43 = 2000000, int44 = 10, int45 = 1000000;
int int46 = 100, int47 = 1000, int48 = 5000, int49 = 28000, int50 = 500;
int int51 = 16, int52 = 3, int53 = 75, int54 = 2, int55 = 999999;
int int56 = 13, int57 = 100000, int58 = 5, int59 = 4000, int60 = 100;
int int61 = 10, int62 = 300, int63 = 100000, int64 = 1000, int65 = 50;
int int66 = 1000, int67 = 50000, int68 = 21000000, int69 = 256, int70 = 1000;
int int71 = 65, int72 = 1000, int73 = 100, int74 = 20, int75 = 4;
int int76 = 1000000, int77 = 50000000, int78 = 420, int79 = 3000, int80 = 95;
int int81 = 9000, int82 = 50, int83 = 100, int84 = 42, int85 = 10000;
int int86 = 50000, int87 = 100000, int88 = 280, int89 = 1000, int90 = 500;
int int91 = 24, int92 = 1000, int93 = 85, int94 = 2003, int95 = 56;
int int96 = 1000, int97 = 500, int98 = 200, int99 = 50, int100 = 1337;

float float1 = 3.14159f, float2 = 2.71828f, float3 = 1.41421f, float4 = 1.73205f, float5 = 0.70711f;
float float6 = 6.28318f, float7 = 9.80665f, float8 = 299792458.0f, float9 = 6.62607e-34f, float10 = 1.60218e-19f;
float float11 = 9.10938e-31f, float12 = 1.67262e-27f, float13 = 6.02214e23f, float14 = 8.31446f, float15 = 1.38065e-23f;
float float16 = 5.67037e-8f, float17 = 4.80320e-10f, float18 = 2.99792e8f, float19 = 1.25664e-6f, float20 = 8.85419e-12f;
float float21 = 273.15f, float22 = 101325.0f, float23 = 6.67430e-11f, float24 = 7.34767e-3f, float25 = 2.17987e-18f;
float float26 = 5.29177e-11f, float27 = 1.09737e7f, float28 = 2.81794e15f, float29 = 3.33564e-27f, float30 = 9.27401e-24f;
float float31 = 5.05078e-27f, float32 = 1.40496e-12f, float33 = 2.06783e-11f, float34 = 4.35974e-18f, float35 = 6.50522e-16f;
float float36 = 1.23984e-6f, float37 = 7.29735e-3f, float38 = 2.42631e-12f, float39 = 4.13567e-15f, float40 = 1.52088e-16f;
float float41 = 42.0f, float42 = 69.420f, float43 = 1337.1337f, float44 = 360.0f, float45 = 180.0f;
float float46 = 90.0f, float47 = 45.0f, float48 = 30.0f, float49 = 60.0f, float50 = 120.0f;
float float51 = 0.5f, float52 = 0.25f, float53 = 0.125f, float54 = 0.0625f, float55 = 1.5f;
float float56 = 2.5f, float57 = 3.5f, float58 = 4.5f, float59 = 5.5f, float60 = 6.5f;
float float61 = 7.5f, float62 = 8.5f, float63 = 9.5f, float64 = 10.5f, float65 = 11.5f;
float float66 = 12.5f, float67 = 13.5f, float68 = 14.5f, float69 = 15.5f, float70 = 16.5f;
float float71 = 17.5f, float72 = 18.5f, float73 = 19.5f, float74 = 20.5f, float75 = 21.5f;
float float76 = 22.5f, float77 = 23.5f, float78 = 24.5f, float79 = 25.5f, float80 = 26.5f;
float float81 = 27.5f, float82 = 28.5f, float83 = 29.5f, float84 = 30.5f, float85 = 31.5f;
float float86 = 32.5f, float87 = 33.5f, float88 = 34.5f, float89 = 35.5f, float90 = 36.5f;
float float91 = 37.5f, float92 = 38.5f, float93 = 39.5f, float94 = 40.5f, float95 = 41.5f;
float float96 = 999.999f, float97 = 666.666f, float98 = 420.69f, float99 = 1234.5678f, float100 = 9876.5432f;

string string1 = "hello", string2 = "world", string3 = "chaos", string4 = "madness", string5 = "insanity";
string string6 = "apocalypse", string7 = "unicorn", string8 = "rainbow", string9 = "dragon", string10 = "wizard";
string string11 = "ninja", string12 = "pirate", string13 = "robot", string14 = "alien", string15 = "vampire";
string string16 = "zombie", string17 = "ghost", string18 = "demon", string19 = "angel", string20 = "phoenix";
string string21 = "mermaid", string22 = "goblin", string23 = "fairy", string24 = "troll", string25 = "elf";
string string26 = "dwarf", string27 = "giant", string28 = "witch", string29 = "warlock", string30 = "banshee";
string string31 = "skeleton", string32 = "werewolf", string33 = "frankenstein", string34 = "scientist", string35 = "paradox";
string string36 = "dimension", string37 = "portal", string38 = "cosmic", string39 = "supernova", string40 = "meteor";
string string41 = "comet", string42 = "asteroid", string43 = "satellite", string44 = "rocket", string45 = "spaceship";
string string46 = "wormhole", string47 = "quantum", string48 = "parallel", string49 = "universe", string50 = "reality";
string string51 = "matrix", string52 = "simulation", string53 = "hologram", string54 = "virtual", string55 = "augmented";
string string56 = "artificial", string57 = "intelligence", string58 = "neural", string59 = "network", string60 = "machine";
string string61 = "learning", string62 = "blockchain", string63 = "cryptocurrency", string64 = "digital", string65 = "cloud";
string string66 = "server", string67 = "fiber", string68 = "wireless", string69 = "internet", string70 = "streaming";
string string71 = "social", string72 = "media", string73 = "viral", string74 = "meme", string75 = "emoji";
string string76 = "hashtag", string77 = "influencer", string78 = "tiktok", string79 = "instagram", string80 = "youtube";
string string81 = "twitch", string82 = "discord", string83 = "reddit", string84 = "twitter", string85 = "facebook";
string string86 = "linkedin", string87 = "snapchat", string88 = "pinterest", string89 = "tumblr", string90 = "myspace";
string string91 = "chrome", string92 = "firefox", string93 = "safari", string94 = "edge", string95 = "opera";
string string96 = "brave", string97 = "password", string98 = "security", string99 = "privacy", string100 = "ultimate_chaos";
return 0;
}
