#include "texture_handler.h"

handler::handler() {
  Texture txt;
  txt.loadFromFile("./textures/wall.png");
  wall = &txt;
  txt.loadFromFile("./textures/left_fire.png");
  left_fire = &txt;
  txt.loadFromFile("./textures/right_fire.png");
  right_fire = &txt;
  txt.loadFromFile("./textures/ani1.png");
  explode.push_back(&txt);
  txt.loadFromFile("./textures/ani2.png");
  explode.push_back(&txt);
  txt.loadFromFile("./textures/ani3.png");
  explode.push_back(&txt);
  txt.loadFromFile("./textures/ani4.png");
  explode.push_back(&txt);
  txt.loadFromFile("./textures/ani5.png");
  explode.push_back(&txt);
  txt.loadFromFile("./textures/lt1.png");
  left.push_back(&txt);
  txt.loadFromFile("./textures/lt2.png");
  left.push_back(&txt);
  txt.loadFromFile("./textures/lt3.png");
  left.push_back(&txt);
  txt.loadFromFile("./textures/lt4.png");
  left.push_back(&txt);
  txt.loadFromFile("./textures/rt1.png");
  right.push_back(&txt);
  txt.loadFromFile("./textures/rt2.png");
  right.push_back(&txt);
  txt.loadFromFile("./textures/rt3.png");
  right.push_back(&txt);
  txt.loadFromFile("./textures/rt4.png");
  right.push_back(&txt);
  txt.loadFromFile("./textures/stl.png");
  stay_left = &txt;
  txt.loadFromFile("./textures/str.png");
  stay_right = &txt;
  txt.loadFromFile("./textures/thl.png");
  throw_left = &txt;
  txt.loadFromFile("./textures/thr.png");
  throw_right = &txt;
}
