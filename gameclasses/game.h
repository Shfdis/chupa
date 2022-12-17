//
// Created by artem on 17.12.22.
//
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "player.h"
using namespace sf;
#ifndef CHUPA_GAME_H
#define CHUPA_GAME_H


class Game {
private:
    int Window_h = 1000, Window_w = 1000;
    float g = 10;
    RenderWindow w;

public:
    int get_window_h() {
        return Window_h;
    }

    int get_window_w() {
        return Window_w;
    }

    void init(Player& player) {
        while (w.isOpen()) {
            Event event;
            while (w.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    w.close();
                } else if (event.type == Event::KeyPressed) {
                    if (event.key.code == 57) {
                        player.jump();
                    }
                }
                w.clear();
                w.draw(player.get_texture());
                w.display();
            }
        }
    }

    Game() {
        w.create(VideoMode(Window_w, Window_h), "Window");
        Player player(g, 1, 1);
        init(player);
    }
};


#endif //CHUPA_GAME_H
