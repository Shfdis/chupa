#include "fireball.h"
using namespace std;
using namespace sf;
bool Fireball::move(float t, vector<game_obj*>& obs) {
    int coll = collision_detector(obs);
    if (coll != -1) {
        explode(obs[coll]);
        return true;
    }
    x += t * vx;
    y += t * vy;
    texture.setPosition(x, y);
    return false;
}
void Fireball::explode(game_obj* obj) {
    obj->explode();
}
void Fireball::setv(float v) {
    vx = v;
}

Fireball::Fireball(float ww, float hh, float xx, float yy, float velx) : game_obj(ww, hh, xx, yy) {
    this->vx = velx;
    this->vy = 0;
}