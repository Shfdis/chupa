#include "game_obj.h"
int t = 0;
pair<float, float> game_obj::collision_handler(game_obj ob) {
    float dx = 1e9 + 7;
    if (abs(dx) > abs(ob.x - x - w)) {
        dx = ob.x - x - w;
    }
    if (abs(dx) > abs(x - ob.x - ob.w)) {
        dx = ob.x + ob.w - x;
    }
    float dy = 1e9 + 7;
    if (abs(dy) > abs(ob.y - y - h)) {
        dy = ob.y - y - h;
    }
    if (abs(dy) > abs(y - ob.y - ob.h)) {
        dy = ob.y + ob.h - y;
    }
    if (abs(dx) < abs(dy)) {
        return {dx, 0};
    } else {
        return {0, dy};
    }
}
int game_obj::collision_detector(vector<game_obj> obs) {
    for (int j = 0; j < obs.size(); j++) {
        game_obj i = obs[j];
        if (x < i.x + i.w && x + w > i.x && y < i.y + i.h && h + y > i.y) {
            // Collision detected!
            return j;
        }
    }
    return -1;
}
bool game_obj::detect_bottom_collision(vector<game_obj> &obs) {
    for (auto i : obs) {
        if (y + h >= i.y && x + w >= i.x + 1 && x <= i.x + i.w - 1 && y <= i.y + i.h) {
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