//
// Created by artem on 13.12.22.
//
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#ifndef CHUPA_PLAYER_H
#define CHUPA_PLAYER_H
using namespace sf;

class Player {
private:
    int h = 50, w = 10;
    float x, y;
    float velx = 0, vely = 0;
    float ax = 100, ay = 100;
    float g;
    RectangleShape texture;
public:
    int get_h() {
        return h;
    }

    int get_w() {
        return w;
    }

    void move() {
        velx += ax;
        vely += ay;
        x += velx;
        y += vely;
        texture.move(velx, vely);
        if (y > 1e-6) {
            ay += g;
        }
    }

    void jump() {
        if (abs(y) < 2e-6) {
            ay = 20;
        }
    }

    RectangleShape& get_texture() {
        return texture;
    }

    Player(float g, float x, float y) {
        texture.move(x, y);
        texture.setScale(ax, ay);
        texture.setFillColor(Color::Green);
        this->g = -g;
        this->x = x;
        this->y = y;
    }
};


#endif //CHUPA_PLAYER_H
