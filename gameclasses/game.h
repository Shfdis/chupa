//
// Created by artem on 17.12.22.
//
#pragma once
#ifndef CHUPA_GAME_H
#define CHUPA_GAME_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "player.h"
#include "target.h"
#include "texture_handler.h"
using namespace sf;


class Game {
private:
    int to_dest = 6;
    int Window_h = 1000, Window_w = 800;
    float g = 1000;
    RenderWindow w;
    vector<game_obj*> obs;
    void draw(Player& player, float t);
    handler *Handle;
    RectangleShape *bg;
public:
    int get_window_h();

    int get_window_w();

    void init(Player& player);

    Game();

    ~Game();
};


#endif //CHUPA_GAME_H
