#pragma once
#ifndef GAMEOBJ
#define GAMEOBJ
#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>

#include "texture_handler.h"
using namespace std;
using namespace sf;
class game_obj {
   protected:
    float w, h, x, y;
    RectangleShape texture;

   public:
    bool explodes = false;
    game_obj() = default;
    game_obj(float ww, float hh, float xx, float yy);
    RectangleShape &get_texture();
    pair<float, float> collision_handler(game_obj *ob);
    int collision_detector(vector<game_obj *> &obs);
    bool detect_bottom_collision(vector<game_obj *> &obs);
    virtual void explode();
    virtual bool update(float t);
    float get_x();
    float get_y();
};
#endif