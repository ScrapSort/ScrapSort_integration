#include "test_helpers.h"

void __assert_fn(const char *msg, const char *file, int line) {
  printf("Assertion failed: %s at %s:%i\n", msg, file, line);
}

test *Test(char *name, char *group, bool (*fn)()) {
  test *t = malloc(sizeof(test));

  t->name = name;
  t->group = group;
  t->fn = fn;
  t->next = NULL;

  return t;
}

tests Tests() {
  tests t;

  t.num_tests = 0;
  t.head = NULL;

  return t;
}

void tests__add_test(char *name, char *group, bool (*fn)()) {}

void tests__run_tests() {}

void tests__run_test(char *name) {}

void tests__run_test_group(char *group) {}