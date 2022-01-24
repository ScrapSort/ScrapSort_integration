
#include "Sorter.h"

void Sorter::add_item(int type) {
  for (int i = 0; i < NUM_TYPES; i++) {
    queues[i].push(i == type);
  }
}

bool Sorter::detected_item(int flipper) {
  return queues[flipper].pop();
}
