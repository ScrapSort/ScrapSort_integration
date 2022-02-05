
#ifndef SCRAPSORT_INTEGRATION_SORTER_H
#define SCRAPSORT_INTEGRATION_SORTER_H

#define NUM_TYPES 6

#include "Queue.h"
#include "utils.h"

class Sorter {
public:
  Sorter() = default;

  // Add item type prediction from CNN when first IR sensor detects an object
  void add_item(int type);

  /*
   * Update queues when a flipper's IR sensor detects an object
   * Returns: true if flipper should activate
   */
  bool detected_item(int flipper);

private:
  Queue queues[NUM_TYPES];
};

#endif // SCRAPSORT_INTEGRATION_SORTER_H
