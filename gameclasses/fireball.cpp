#include "fireball.h"
using namespace std;
using namespace sf;
bool Fireball::move(float t, vector<game_obj*>& obs) {
    int coll = collision_detector(obs);
    if (coll != -1) {
        if (explode(obs[coll])) {
            obs.erase(obs.begin() + coll);
        }
        return true;
    }
    x += t * vx;
    y += t * vy;
    texture.setPosition(x, y);
    return false;
}
bool Fireball::explode(game_obj* obj) {
    return obj->explode();
}
void Fireball::setv(float v) {
    vx = v;
}
