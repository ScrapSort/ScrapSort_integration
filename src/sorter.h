#ifndef SCRAPSORT_INTEGRATION_SORTER_H
#define SCRAPSORT_INTEGRATION_SORTER_H

#define NUM_TYPES 6

#include "queue.h"

typedef struct sorter {
  struct queue queues[NUM_TYPES];

  // Add item type prediction from CNN when first IR sensor detects an object
  void (*add_item)(int type);

  /*
   * Update queues when a flipper's IR sensor detects an object
   * Returns: true if flipper should activate
   */
  bool (*detected_item)(int flipper);

} sorter;

void sorter__add_item(sorter *s, int item_type);
bool sorter__detected_item(sorter *s, int flipper);

sorter Sorter();

#endif // SCRAPSORT_INTEGRATION_SORTER_H