#ifndef CHUPA_TEXTURE_HANDLER_H
#define CHUPA_TEXTURE_HANDLER_H
#include <unistd.h>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class handler {
  public:
    vector<const Texture*> right;
    vector<const Texture*> left;
    vector<const Texture*> explode;
    const Texture *wall;
    const Texture *left_fire, *right_fire;
    const Texture *target;
    const Texture *stay_left, *stay_right, *throw_left, *throw_right;
    handler();
};
#endif