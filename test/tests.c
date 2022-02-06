#include "tests.h"
#include "test_helpers.h"

void initialize_tests(tests *t) {
  tests__add_test(t, "queue__create_queue", test_queue__create_queue);
  tests__add_test(t, "queue__push", test_queue__push);
  tests__add_test(t, "queue__pop", test_queue__pop);
  tests__add_test(t, "queue__size", test_queue__size);
  tests__add_test(t, "queue__empty", test_queue__empty);
}
