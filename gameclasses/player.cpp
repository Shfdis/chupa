//
// Created by artem on 13.12.22.
//
#include "player.h"
using namespace std;
using namespace sf;

float Player::get_h() { return h; }

float Player::get_w() { return w; }

void Player::move(float t, vector<game_obj> &obs) {
    x += velx * t;
    y += vely * t;
    vector<int> to_delete;
    for (int j = 0; j < fireballs.size(); j++) {
        Fireball &i = fireballs[j];
        if (i.move(t, obs)) {
            to_delete.push_back(j);
        }
    }
    for (int i = to_delete.size() - 1; i >= 0; i--) {
        fireballs.erase(fireballs.begin() + to_delete[i]);
    }
    velx = 0;
    texture.setPosition(x, y);
    if (!Player::detect_bottom_collision(obs)) {
        vely += g * t;
    }
    int i = 0;
    while (i != -1) {
        i = collision_detector(obs);
        pair<float, float> tmp = {0, 0};
        if (i != -1) {
            tmp = collision_handler(obs[i]);
        }
        if (tmp.first != 0) velx = 0;
        if (tmp.second != 0) vely = 0;
        x += tmp.first;
        y += tmp.second;
    }
}

void Player::jump(vector<game_obj> &obs) {
    if (Player::detect_bottom_collision(obs)) {
        vely = -500;
    }
}

void Player::go_left(vector<game_obj> &obs) {
    velx = -500;
    right = false;
}
void Player::go_right(vector<game_obj> &obs) {
    velx = 500;
    right = true;
}

Player::Player(float g, float x, float y) {
    texture = RectangleShape(Vector2f(100.f, 100.f));
    texture.move(x, y);
    texture.setFillColor(Color::Green);
    right =  true;
    this->g = g;
    this->x = x;
    this->y = y;
    this->h = texture.getSize().y;
    this->w = texture.getSize().x;
}

void Player::cast(float cur_t) {
    if (cur_t - last_fire < 0.5) {
        return;
    }
    last_fire = cur_t;
    if (right) {
        Fireball t(30.f, 30.f, this->x + this->w, this->y + this->h / 2);
        t.setv(700.f);
        fireballs.push_back(t);
    }
    else {
        Fireball t(30.f, 30.f,  this->x - 30, this->y + this->h / 2);
        t.setv(-700.f);
        fireballs.push_back(t);
    }
}

vector<Fireball> Player::get_fireballs() { return fireballs; }