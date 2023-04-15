//
// Created by artem on 17.12.22.
//
#pragma once
#ifndef CHUPA_GAME_H
#define CHUPA_GAME_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <filesystem>
#include "player.h"
#include "target.h"
using namespace sf;


class Game {
private:
    int Window_h = 1000, Window_w = 1000;
    float g = 400;
    RenderWindow w;
    vector<game_obj*> obs;
    void draw(Player& player);
public:
    int get_window_h();

    int get_window_w();

    void init(Player& player);

    Game();
};


#endif //CHUPA_GAME_H
