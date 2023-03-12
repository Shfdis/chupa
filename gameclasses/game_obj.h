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
    bool detect_bottom_collision(vector<game_obj> &obs);
    bool detect_top_collision(vector<game_obj> &obs);
    bool detect_left_collision(vector<game_obj> &obs);
    bool detect_right_collision(vector<game_obj> &obs);
};
#endif