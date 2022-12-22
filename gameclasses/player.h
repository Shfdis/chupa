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
    float h, w;
    float x, y;
    float velx = 0, vely = 0;
    float ax = 0, ay = 0;
    float g;
    RectangleShape texture;
public:
    float get_h() const {
        return h;
    }

    float get_w() const {
        return w;
    }

    void move() {
        velx += ax;
        vely += ay;
        x += velx;
        y += vely;
        texture.setPosition(x, y);
        std::cout << y - h << '\n';
        if (y - h > 1e-6) {
            ay += g;
        }
    }

    void jump() {
        if (y < 1e-6) {
            ay = 10000;
        }
    }

    RectangleShape& get_texture() {
        return texture;
    }

    Player(float g, float x, float y) {
        texture = RectangleShape(Vector2f(100.f, 100.f));
        texture.move(x, y);
        texture.setFillColor(Color::Green);
        this->g = -g;
        this->x = x;
        this->y = y;
        this->h = texture.getSize().y;
        this->w = texture.getSize().x;
    }
};


#endif //CHUPA_PLAYER_H
