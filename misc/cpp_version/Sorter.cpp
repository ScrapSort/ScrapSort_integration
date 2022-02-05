
#include "Sorter.h"

void Sorter::add_item(int type) {
  D(std::cout << "add_item(" << type << ")" << std::endl);

  for (int i = 0; i < type; i++) {
    queues[i].push(false);
  }

  queues[type].push(true);
}

bool Sorter::detected_item(int flipper) {
  D(std::cout << "detected_item(" << flipper << ")" << std::endl);

  return queues[flipper].pop();
}
