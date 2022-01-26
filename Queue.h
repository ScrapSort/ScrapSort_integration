#ifndef SCRAPSORT_INTEGRATION_QUEUE_H
#define SCRAPSORT_INTEGRATION_QUEUE_H

#include <iostream>

#include "utils.h"

struct QueueNode {
  bool push_into_bucket;
  QueueNode *next;

  QueueNode(bool p) : push_into_bucket(p) {}
};

class Queue {
public:
  Queue() : num_nodes(0), front(nullptr), back(nullptr) {}
  void push(bool push_into_bucket);
  bool pop();
  int size();
  bool empty();

private:
  QueueNode *front;
  QueueNode *back;
  int num_nodes;
};

#endif // SCRAPSORT_INTEGRATION_QUEUE_H
