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
    bool move(float t, vector<game_obj>& obs);
    bool explode(game_obj& vict);
};
#endif  // CHUPA_FIREBALL_H