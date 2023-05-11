#ifndef CHUPA_TEXTURE_HANDLER_H
#define CHUPA_TEXTURE_HANDLER_H
#include <unistd.h>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class handler {
  public:
    vector<Texture*> right;
    vector<Texture*> left;
    Texture* wall;
    Texture* fireball;
    Texture* target;
    vector<Texture*> explode;
    handler() {
      
    }
};
#endif