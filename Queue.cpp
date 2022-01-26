#include "Queue.h"

void Queue::push(bool push_into_bucket) {
  D(std::cout << "push(" << push_into_bucket << ")" << std::endl);

  num_nodes++;

  if (!front) {
    front = back = new QueueNode(push_into_bucket);
  } else {
    back->next = new QueueNode(push_into_bucket);
    back = back->next;
  }
}

bool Queue::pop() {
  D(std::cout << "pop()" << std::endl);

  if (!num_nodes) {
    D(std::cout << "ERROR: Queue is empty" << std::endl);
    return false;
  }

  bool val = front->push_into_bucket;
  num_nodes--;

  if (!front->next) {
    delete front;
    front = back = nullptr;
  } else {
    QueueNode *tmp = front;
    front = front->next;
    delete tmp;
  }

  return val;
}

int Queue::size() {
  D(std::cout << "size()" << std::endl);

  return num_nodes;
}

bool Queue::empty() {
  D(std::cout << "empty()" << std::endl);

  return !num_nodes;
}
