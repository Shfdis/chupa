//
// Created by artem on 13.12.22.
//
#pragma once
#ifndef CHUPA_PLAYER_H
#define CHUPA_PLAYER_H
#include "game_obj.h"
#include "fireball.h"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace sf;

class Player : public game_obj {
  private:
    // float h, w;
    // float x, y;
    float velx = 0, vely = 0;
    float g;
    vector<Fireball> fireballs;
    bool right;
  public:
    float get_h();

    float get_w();

    void move(float t, vector<game_obj> &obs);

    void jump(vector<game_obj> &obs);

    void go_left(vector<game_obj> &obs);

    void go_right(vector<game_obj> &obs);

    Player(float g, float x, float y);

    vector<Fireball> get_fireballs();
};

#endif // CHUPA_PLAYER_H
