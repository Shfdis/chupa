#include "game_obj.h"
bool game_obj::detect_bottom_collision(vector<game_obj> &obs) {
    for (auto i : obs) {
        if (y + h >= i.y && x + w >= i.x && x <= i.x + i.w && y <= i.y + i.h) {
            return true;
        }
    }
    return false;
}
bool game_obj::detect_top_collision(vector<game_obj> &obs) {
    for (auto i : obs) {
        if (y <= i.y + i.h && y + h >= i.y && x + w >= i.x && x <= i.x + i.w) {
            return true;
        }
    }
    return false;
}
bool game_obj::detect_left_collision(vector<game_obj> &obs) {
    for (auto i : obs) {
        if (y <= i.y + i.h && y + h >= i.y && i.x + i.w >= x && i.x <= x + w) {
            return true;
        }
    }
    return false;
}
bool game_obj::detect_right_collision(vector<game_obj> &obs) {
    for (auto i : obs) {
        if (y <= i.y + i.h && y + h >= i.y && i.x <= x + w && i.x + i.w >= x) {
            return true;
        }
    }
    return false;
}
game_obj::game_obj(float ww, float hh, float xx, float yy) {
    w = ww;
    h = hh;
    x = xx;
    y = yy;
};