#include <stdio.h>

#include "queue.h"
#include "sorter.h"
#include "stats.h"

#define NUM_TYPES 6
#define QUEUE_SIZE 10

int main() {

  // TEST QUEUE

  queue q = Queue(5);

  queue__push(&q, 1);
  queue__push(&q, 3);
  queue__push(&q, 2);
  queue__push(&q, 4);

  printf("%i\n", queue__pop(&q)); // 1
  printf("%i\n", queue__pop(&q)); // 3
  printf("%i\n", queue__pop(&q)); // 2
  printf("%i\n", queue__pop(&q)); // 4
  printf("\n");

  // TEST SORTER

  sorter s = Sorter(NUM_TYPES, QUEUE_SIZE);

  sorter__add_item(&s, 2);
  sorter__add_item(&s, 1);

  printf("%i\n", sorter__detected_item(&s, 0)); // F
  printf("%i\n", sorter__detected_item(&s, 1)); // F
  printf("%i\n", sorter__detected_item(&s, 2)); // T
  printf("%i\n", sorter__detected_item(&s, 0)); // F
  printf("%i\n", sorter__detected_item(&s, 1)); // T
  printf("\n");

  // // TEST STATS

  // stats st = Stats(NUM_TYPES);

  // stats__added_item(&st, 0);
  // stats__added_item(&st, 0);
  // stats__added_item(&st, 1);
  // stats__added_item(&st, 2);
  // stats__added_item(&st, 4);
  // stats__added_item(&st, 4);

  // printf("%i\n", st.num_items_active[0]); // 2
  // printf("%i\n", st.num_items_active[1]); // 1
  // printf("%i\n", st.num_items_active[2]); // 1
  // printf("%i\n", st.num_items_active[3]); // 0
  // printf("%i\n", st.num_items_active[4]); // 2
  // printf("%i\n", st.num_items_active[5]); // 0

  // stats__binned_item(&st, 0);
  // stats__binned_item(&st, 0);
  // stats__binned_item(&st, 1);
  // stats__binned_item(&st, 2);
  // stats__binned_item(&st, 4);
  // stats__binned_item(&st, 4);

  // printf("%i %i\n", st.num_items_active[0], st.num_items_binned[0]);  // 0 2
  // printf("%i %i\n", st.num_items_active[1], st.num_items_binned[1]);  // 0 1
  // printf("%i %i\n", st.num_items_active[2], st.num_items_binned[2]);  // 0 1
  // printf("%i %i\n", st.num_items_active[3], st.num_items_binned[3]);  // 0 0
  // printf("%i %i\n", st.num_items_active[4], st.num_items_binned[4]);  // 0 2
  // printf("%i %i\n", st.num_items_active[5], st.num_items_binned[5]);  // 0 0

  // // TEST SORTER PRINT

  // sorter s = Sorter(NUM_TYPES);

  // sorter__add_item(&s, 0);
  // sorter__add_item(&s, 1);
  // sorter__add_item(&s, 4);
  // sorter__add_item(&s, 5);
  // sorter__add_item(&s, 3);
  // sorter__add_item(&s, 2);

  // sorter__print(&s);

  return 0;
}
