//
// Created by artem on 13.12.22.
//
#include "player.h"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

float Player::get_h() { return h; }

float Player::get_w() { return w; }

void Player::move(float t, vector<game_obj> &obs) {
    x += velx * t;
    y += vely * t;
    velx = 0;
    texture.setPosition(x, y);
    if (!Player::detect_bottom_collision(obs)) {
        vely += g * t;
    } else {
        vely = (vely > 1e-2 ? 0 : vely);
    }
}

void Player::jump(vector<game_obj> &obs) {
    if (Player::detect_bottom_collision(obs)) {
        vely = -100;
    }
}

void Player::go_left(vector<game_obj> &obs) {
    velx = -100;
}
void Player::go_right(vector<game_obj> &obs) {
    velx = 100;
}
RectangleShape &Player::get_texture() { return texture; }

Player::Player(float g, float x, float y) {
    texture = RectangleShape(Vector2f(100.f, 100.f));
    texture.move(x, y);
    texture.setFillColor(Color::Green);
    this->g = g;
    this->x = x;
    this->y = y;
    this->h = texture.getSize().y;
    this->w = texture.getSize().x;
}