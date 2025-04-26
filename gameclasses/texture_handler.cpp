#include "texture_handler.h"

handler::handler() {
    txt[0].loadFromFile("./chupa/textures/wall.png");
    txt[1].loadFromFile("./chupa/textures/left_fire.png");
    txt[2].loadFromFile("./chupa/textures/right_fire.png");
    txt[3].loadFromFile("./chupa/textures/ani1.png");
    txt[4].loadFromFile("./chupa/textures/ani2.png");
    txt[5].loadFromFile("./chupa/textures/ani3.png");
    txt[6].loadFromFile("./chupa/textures/ani4.png");
    txt[7].loadFromFile("./chupa/textures/ani5.png");
    txt[8].loadFromFile("./chupa/textures/lt1.png");
    txt[9].loadFromFile("./chupa/textures/lt2.png");
    txt[10].loadFromFile("./chupa/textures/lt3.png");
    txt[11].loadFromFile("./chupa/textures/lt4.png");
    txt[12].loadFromFile("./chupa/textures/rt1.png");
    txt[13].loadFromFile("./chupa/textures/rt2.png");
    txt[14].loadFromFile("./chupa/textures/rt3.png");
    txt[15].loadFromFile("./chupa/textures/rt4.png");
    txt[16].loadFromFile("./chupa/textures/stl.png");
    txt[17].loadFromFile("./chupa/textures/str.png");
    txt[18].loadFromFile("./chupa/textures/thl.png");
    txt[19].loadFromFile("./chupa/textures/thr.png");
    txt[20].loadFromFile("./chupa/textures/bg.png");
    wall = &txt[0];
    left_fire = &txt[1];
    right_fire = &txt[2];
    background = &txt[20];
    explode.push_back(&txt[3]);
    explode.push_back(&txt[4]);
    explode.push_back(&txt[5]);
    explode.push_back(&txt[6]);
    explode.push_back(&txt[7]);
    left.push_back(&txt[16]);
    left.push_back(&txt[8]);
    left.push_back(&txt[9]);
    left.push_back(&txt[16]);
    left.push_back(&txt[10]);
    left.push_back(&txt[11]);
    right.push_back(&txt[17]);
    right.push_back(&txt[12]);
    right.push_back(&txt[13]);
    right.push_back(&txt[17]);
    right.push_back(&txt[14]);
    right.push_back(&txt[15]);
    stay_left = &txt[16];
    stay_right = &txt[17];
    throw_left = &txt[18];
    throw_right = &txt[19];
    target = &txt[3];
}
handler::~handler() {
    for (auto& i : left) {
        delete i;
    }
    for (auto& i : right) {
        delete i;
    }
    for (auto& i : explode) {
        delete i;
    }
    delete wall, fireball, throw_left, throw_right, background;
    delete target, left_fire, stay_left, right_fire, stay_right;
}


