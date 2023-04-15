#pragma once
#ifndef GAMEOBJ
#define GAMEOBJ
#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class game_obj {
   protected:
    float w, h, x, y;
    RectangleShape texture;

   public:
    game_obj() = default;
    game_obj(float ww, float hh, float xx, float yy);
    RectangleShape &get_texture();
    void set_texture(string file_name);
    pair<float, float> collision_handler(game_obj *ob);
    int collision_detector(vector<game_obj *> &obs);
    bool detect_bottom_collision(vector<game_obj *> &obs);
    virtual bool explode();
};
#endif