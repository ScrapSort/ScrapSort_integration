#include "sorter.h"
#include "queue.h"

void sorter__add_item(sorter *s, int item_type) {
  for (int i = 0; i < item_type; i++) {
    queue__push(&s->queues[i], item_type);
  }

  queue__push(&s->queues[item_type], item_type);
}

bool sorter__detected_item(sorter *s, int flipper) {
  return queue__pop(&s->queues[flipper]) == flipper;
}

sorter Sorter() {
  sorter s;

  for (int i = 0; i < NUM_TYPES; i++) {
    s.queues[i] = Queue();
  }

  return s;
}
