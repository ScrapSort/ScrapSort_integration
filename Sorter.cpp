
#include "Sorter.h"

void Sorter::add_item(int type) {
  for (int i = 0; i < type; i++) {
    queues[i].push(false);
  }

  queues[type].push(true);
}

bool Sorter::detected_item(int flipper) {
  return queues[flipper].pop();
}
