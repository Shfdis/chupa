#pragma once
#ifndef GAMEOBJ
#define GAMEOBJ
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;
class game_obj {
  protected:
    float w, h, x, y;
  public:
    game_obj() = default;
    game_obj(float ww, float hh, float xx, float yy);
    pair<float, float> collision_handler(game_obj ob);
    int collision_detector(vector<game_obj> obs);
    bool detect_bottom_collision(vector<game_obj> &obs);
};
#endif