#include "fireball.h"
using namespace std;
using namespace sf;
bool Fireball::move(float t, vector<game_obj>& obs) {
    int coll = collision_detector(obs);
    if (coll != -1) {
        return explode(obs[coll]);
    }
    x += t * vx;
    y += t * vy;
    return false;
}
bool Fireball::explode(game_obj& obj) {
    return true;
}