//
// Created by artem on 13.12.22.
//
#pragma once
#ifndef CHUPA_PLAYER_H
#define CHUPA_PLAYER_H
#include "game_obj.h"
#include "fireball.h"
#include "texture_handler.h"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace sf;

class Player : public game_obj {
  protected:
    // float h, w;
    // float x, y;
    bool fire = false;
    int slide;
    float velx = 0, vely = 0;
    float g, patience;
    float last_fire = -100;
    vector<Fireball> fireballs;
    bool right;
    handler *Handle;
  public:
    float get_h();

    float get_w();

    void move(float t, vector<game_obj*> &obs);

    void jump(vector<game_obj*> &obs);

    void go_left(vector<game_obj*> &obs);

    void go_right(vector<game_obj*> &obs);

    Player(float g, float x, float y, handler *H);

    void cast(float cur_t);

    vector<Fireball> get_fireballs();
};

#endif // CHUPA_PLAYER_H
