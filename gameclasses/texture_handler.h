#ifndef CHUPA_TEXTURE_HANDLER_H
#define CHUPA_TEXTURE_HANDLER_H
#include <unistd.h>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class handler {
  public:
   Texture txt, txt1, txt2, txt3, txt4, txt5, txt6, txt7, txt8, txt9, txt10, txt11, txt12, txt13, txt14, txt15, txt16, txt17, txt18, txt19;
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