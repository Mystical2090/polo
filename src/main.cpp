#include <Geode/Geode.hpp>
#include "src/Speedhack.cpp"

void loadPlayerHacks();
void loadGlobalHacks();

$on_mod(Loaded) {
    loadGlobalHacks();
}
