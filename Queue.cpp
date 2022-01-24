#include "Queue.h"

void Queue::push(bool push_into_bucket) {
  num_nodes++;

  if (!front) {
    front = back = new QueueNode(push_into_bucket);
  } else {
    back->next = new QueueNode(push_into_bucket);
    back = back->next;
  }
}

bool Queue::pop() {
  if (!num_nodes) {
    std::cout << "ERROR: Queue is empty" << std::endl;
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

int Queue::size() { return num_nodes; }

bool Queue::empty() { return !num_nodes; }
