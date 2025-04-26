#ifndef CHUPA_TEXTURE_HANDLER_H
#define CHUPA_TEXTURE_HANDLER_H
#include <unistd.h>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class handler {
  public:
    Texture txt[21];
    vector<Texture*> right;
    vector<Texture*> left;
    Texture *wall;
    Texture *fireball, *throw_left, *throw_right;
    Texture *target, *left_fire, *stay_left, *right_fire, *stay_right;
    vector<Texture*> explode;
    Texture *background;
    handler();
    ~handler();
};
#endif