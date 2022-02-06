#include "test_helpers.h"

void __assert_fn(const char *msg, const char *file, int line) {
  printf("Assertion failed: %s at %s:%i\n", msg, file, line);
}

test *Test(char *name, bool (*fn)()) {
  test *t = malloc(sizeof(test));

  t->name = name;
  t->fn = fn;
  t->next = NULL;

  return t;
}

tests Tests() {
  tests t;

  t.num_tests = 0;
  t.front = NULL;
  t.back = NULL;

  return t;
}

bool test__run_test(test *t) {
  printf("TEST: %s\n", t->name);
  bool result = t->fn();

  return result;
}

void tests__add_test(tests *t, char *name, bool (*fn)()) {
  t->num_tests++;

  if (!t->front) {
    t->front = t->back = Test(name, fn);
  } else {
    t->back->next = Test(name, fn);
    t->back = t->back->next;
  }
}

void tests__run_tests(tests *t) {
  printf("====[RUNNING TESTS]====\n\n");

  int num_passed = 0;
  test *tst = t->front;

  while (tst) {
    if (test__run_test(tst))
      num_passed++;

    tst = tst->next;
  }

  printf("\nResults: Passed %i/%i (%.2f%%)\n", num_passed, t->num_tests,
         (double)num_passed / t->num_tests * 100);
}

void tests__run_test(tests *t, char *name) {
  printf("====[RUNNING TEST]====\n\n");

  test *tst = t->front;

  while (tst && strcmp(tst->name, name))
    tst = tst->next;

  if (tst) {
    printf("Result: %s\n", test__run_test(tst) ? "PASSED" : "FAILED");

  } else
    printf("No test named '%s'", name);
}
