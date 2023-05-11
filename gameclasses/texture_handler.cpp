#include "texture_handler.h"

handler::handler() {
    txt.loadFromFile("./textures/wall.png");
    txt1.loadFromFile("./textures/left_fire.png");
    txt2.loadFromFile("./textures/right_fire.png");
    txt3.loadFromFile("./textures/ani1.png");
    txt4.loadFromFile("./textures/ani2.png");
    txt5.loadFromFile("./textures/ani3.png");
    txt6.loadFromFile("./textures/ani4.png");
    txt7.loadFromFile("./textures/ani5.png");
    txt8.loadFromFile("./textures/lt1.png");
    txt9.loadFromFile("./textures/lt2.png");
    txt10.loadFromFile("./textures/lt3.png");
    txt11.loadFromFile("./textures/lt4.png");
    txt12.loadFromFile("./textures/rt1.png");
    txt13.loadFromFile("./textures/rt2.png");
    txt14.loadFromFile("./textures/rt3.png");
    txt15.loadFromFile("./textures/rt4.png");
    txt16.loadFromFile("./textures/stl.png");
    txt17.loadFromFile("./textures/str.png");
    txt18.loadFromFile("./textures/thl.png");
    txt19.loadFromFile("./textures/thr.png");
    wall = &txt;
    left_fire = &txt1;
    right_fire = &txt2;
    explode.push_back(&txt3);
    explode.push_back(&txt4);
    explode.push_back(&txt5);
    explode.push_back(&txt6);
    explode.push_back(&txt7);
    left.push_back(&txt16);
    left.push_back(&txt8);
    left.push_back(&txt9);
    left.push_back(&txt16);
    left.push_back(&txt10);
    left.push_back(&txt11);
    right.push_back(&txt17);
    right.push_back(&txt12);
    right.push_back(&txt13);
    right.push_back(&txt17);
    right.push_back(&txt14);
    right.push_back(&txt15);
    stay_left = &txt16;
    stay_right = &txt17;
    throw_left = &txt18;
    throw_right = &txt19;
}
