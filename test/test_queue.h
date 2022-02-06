#ifndef SCRAPSORT_INTEGRATION_TEST_QUEUE_H
#define SCRAPSORT_INTEGRATION_TEST_QUEUE_H

#include "../src/queue.h"
#include "test_helpers.h"

bool test_queue__create_queue();
bool test_queue__push();
bool test_queue__pop();
bool test_queue__size();
bool test_queue__empty();

#endif // SCRAPSORT_INTEGRATION_TEST_QUEUE_H
