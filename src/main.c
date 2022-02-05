#include <stdio.h>

#include "queue.h"
#include "sorter.h"

int main() {

  // TEST QUEUE

  queue q = Queue();

  queue__push(&q, 1);
  queue__push(&q, 3);
  queue__push(&q, 2);
  queue__push(&q, 4);

  printf("%i", queue__pop(&q)); // 1
  printf("%i", queue__pop(&q)); // 3
  printf("%i", queue__pop(&q)); // 2
  printf("%i", queue__pop(&q)); // 4

  // TEST SORTER

  struct sorter s = Sorter();

  sorter__add_item(&s, 2);
  sorter__add_item(&s, 1);

  printf("%i", sorter__detected_item(&s, 0)); // F
  printf("%i", sorter__detected_item(&s, 1)); // F
  printf("%i", sorter__detected_item(&s, 2)); // T
  printf("%i", sorter__detected_item(&s, 0)); // F
  printf("%i", sorter__detected_item(&s, 1)); // T

  return 0;
}