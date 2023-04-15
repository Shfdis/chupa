#pragma once
#ifndef CHUPA_TARGET_H
#define CHUPA_TARGET_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "game_obj.h"
class target : public game_obj { 
  public:
    explicit target(float w, float h, float x, float y) : game_obj(w, h, x, y) {};
    bool explode() override;
};
#endif