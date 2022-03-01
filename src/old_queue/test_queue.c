#include "test_queue.h"

bool test_queue__create_queue() {
  queue q = Queue();

  assert(q.num_nodes == 0);
  assert(q.front == NULL);
  assert(q.back == NULL);

  return true;
}

bool test_queue__push() {
  queue q = Queue();

  queue__push(&q, 1);
  queue__push(&q, 2);
  queue__push(&q, 3);

  assert(q.front->item_type == 1);
  assert(q.front->next->item_type == 2);
  assert(q.back->item_type == 3);

  return true;
}

bool test_queue__pop() {
  queue q = Queue();

  for (int i = 0; i < 10; i++)
    queue__push(&q, i);

  for (int i = 0; i < 10; i++) {
    assert(i == queue__pop(&q));
  }

  return true;
}

bool test_queue__size() {
  queue q = Queue();

  assert(queue__size(&q) == 0);

  for (int i = 1; i <= 10; i++) {
    queue__push(&q, i);
    assert(queue__size(&q) == i);
  }

  for (int i = 9; i > 0; i--) {
    queue__pop(&q);
    assert(queue__size(&q) == i);
  }

  return true;
}

bool test_queue__empty() {
  queue q = Queue();

  assert(queue__empty(&q));

  for (int i = 1; i <= 10; i++) {
    queue__push(&q, i);
    assert(!queue__empty(&q));
  }

  for (int i = 10; i > 1; i--) {
    queue__pop(&q);
    assert(!queue__empty(&q));
  }

  queue__pop(&q);
  assert(queue__empty(&q));

  return true;
}
