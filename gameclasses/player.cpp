//
// Created by artem on 13.12.22.
//
#include "player.h"
using namespace std;
using namespace sf;

float Player::get_h() { return h; }

float Player::get_w() { return w; }

void Player::move(float t, vector<game_obj *> &obs) {
    if (patience + t >= 0.18 && fire) {
        fire = false;
        slide = 0;
        patience = 0;
    }
    if (!fire) {
        if (detect_bottom_collision(obs)) {
            if (patience + t >= 0.15f && velx != 0) {
                slide++;
                slide %= 6;
                patience = 0;
            } else if (velx == 0) {
                slide = 0;
                patience = 0.17;
            } else {
                patience += t;
            }
            if (right) {
                this->get_texture().setTexture(
                    slide == -1 ? Handle->stay_right : Handle->right[slide],
                    true);
            } else {
                this->get_texture().setTexture(
                    slide == -1 ? Handle->stay_left : Handle->left[slide],
                    true);
            }
        } else {
            if (right) {
                this->get_texture().setTexture(
                    slide == -1 ? Handle->stay_right : Handle->right[slide],
                    true);
            } else {
                this->get_texture().setTexture(
                    slide == -1 ? Handle->stay_left : Handle->left[slide],
                    true);
            }
        }
        if (slide == 1) {
            get_texture().setScale(Vector2f(1.09375, 1));
        } else if (slide == 4) {
            get_texture().setScale(Vector2f(1.0781, 1));
        } else {
            get_texture().setScale(Vector2f(1, 1));
        }
    } else {
        get_texture().setScale(Vector2f(1.276, 1));
        patience += t;
    }
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
        if (tmp.second < 0) vely = min(0.f, vely);
        if (tmp.second > 0) vely = max(0.f, vely);
        x += tmp.first;
        y += tmp.second;
    }
}

void Player::jump(vector<game_obj *> &obs) {
    if (Player::detect_bottom_collision(obs)) {
        vely = -600;
    }
}

void Player::go_left(vector<game_obj *> &obs) {
    velx = -300;
    right = false;
}
void Player::go_right(vector<game_obj *> &obs) {
    velx = 300;
    right = true;
}

Player::Player(float g, float x, float y, handler *H) {
    slide = -1;
    this->Handle = H;
    patience = 0;
    texture = RectangleShape(Vector2f(60.f, 60.f));
    texture.setTexture(H->stay_right, true);
    texture.move(x, y);
    right = true;
    this->g = g;
    this->x = x;
    this->y = y;
    this->h = texture.getSize().y;
    this->w = texture.getSize().x;
}

void Player::cast(float cur_t) {
    if (cur_t - last_fire < 0.3) {
        return;
    }
    last_fire = cur_t;
    fire = true;
    patience = 0;
    if (right) {
        this->get_texture().setTexture(Handle->throw_right, true);
        Fireball t(36.f, 15.f, this->x + this->w, this->y + this->h / 2);
        t.get_texture().setTexture(Handle->right_fire);
        t.setv(700.f);
        fireballs.push_back(t);
    } else {
        this->get_texture().setTexture(Handle->throw_left, true);
        Fireball t(36.f, 15.f, this->x - 36, this->y + this->h / 2);
        t.get_texture().setTexture(Handle->left_fire);
        t.setv(-700.f);
        fireballs.push_back(t);
    }
}

vector<Fireball> Player::get_fireballs() { return fireballs; }