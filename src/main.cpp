#include <Geode/Geode.hpp>

void loadPlayerHacks();
void loadGlobalHacks();

$on_mod(Loaded) {
    loadPlayerHacks();
    loadGlobalHacks();
}