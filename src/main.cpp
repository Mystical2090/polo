#include <Geode/Geode.hpp>
#include "src/hacks/Global/Speedhack.cpp"

void loadPlayerHacks();
void loadGlobalHacks();

$on_mod(Loaded) {
    loadGlobalHacks();
}
