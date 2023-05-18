#include "texture_handler.h"

handler::handler() {
    txt[0].loadFromFile("./textures/wall.png");
    txt[1].loadFromFile("./textures/left_fire.png");
    txt[2].loadFromFile("./textures/right_fire.png");
    txt[3].loadFromFile("./textures/ani1.png");
    txt[4].loadFromFile("./textures/ani2.png");
    txt[5].loadFromFile("./textures/ani3.png");
    txt[6].loadFromFile("./textures/ani4.png");
    txt[7].loadFromFile("./textures/ani5.png");
    txt[8].loadFromFile("./textures/lt1.png");
    txt[9].loadFromFile("./textures/lt2.png");
    txt[10].loadFromFile("./textures/lt3.png");
    txt[11].loadFromFile("./textures/lt4.png");
    txt[12].loadFromFile("./textures/rt1.png");
    txt[13].loadFromFile("./textures/rt2.png");
    txt[14].loadFromFile("./textures/rt3.png");
    txt[15].loadFromFile("./textures/rt4.png");
    txt[16].loadFromFile("./textures/stl.png");
    txt[17].loadFromFile("./textures/str.png");
    txt[18].loadFromFile("./textures/thl.png");
    txt[19].loadFromFile("./textures/thr.png");
    wall = &txt[0];
    left_fire = &txt[1];
    right_fire = &txt[2];
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
