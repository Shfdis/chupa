#pragma once
#ifndef CHUPA_FIREBALL_H
#define CHUPA_FIREBALL_H
#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>

#include "game_obj.h"
using namespace std;
using namespace sf;
class Fireball : public game_obj {
   protected:
    float vx, vy;
    int num;
   public:
    explicit Fireball(float ww, float hh, float xx, float yy) : game_obj(ww, hh, xx, yy) {}
    bool move(float t, vector<game_obj *> &obs);
    void explode(game_obj * vict);
    void setv(float v);
    Fireball(float ww, float hh, float xx, float yy, float vel) : game_obj(ww, hh, xx, yy) { this->vx = vel; }
};
#endif  // CHUPA_FIREBALL_H