#include "target.h"
void target::explode() {
  explodes = true;
}
bool target::update(float t) {
  time += t;
  if (time >= 0.07) {
    time = 0;
    slide++;
  }
  if (slide == 5) {
    return true;
  } else {
    get_texture().setTexture(hd->explode[slide], true);
    return false;
  }
}