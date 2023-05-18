#pragma once
#ifndef CHUPA_TARGET_H
#define CHUPA_TARGET_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "game_obj.h"
class target : public game_obj { 
  public:
    double time = 0;
    int slide = 0;
    handler *hd;
    explicit target(float w, float h, float x, float y) : game_obj(w, h, x, y) {};
    void explode() override;
    bool update(float t) override;
  
};
#endif