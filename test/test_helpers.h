#ifndef SCRAPSORT_INTEGRATION_TEST_HELPERS_H
#define SCRAPSORT_INTEGRATION_TEST_HELPERS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void __assert_fn(const char *msg, const char *file, int line);
#define __assert(x) (bool)((x) || (__assert_fn(#x, __FILE__, __LINE__), 0))
#define assert(x)                                                              \
  if (!__assert(x))                                                            \
  return false

typedef struct test {
  char *name;
  bool (*fn)();
  struct test *next;
} test;

test *Test(char *name, bool (*fn)());

bool test__run_test(test *t);

typedef struct tests {
  int num_tests;
  test *front;
  test *back;

} tests;

tests Tests();

void tests__add_test(tests *t, char *name, bool (*fn)());
void tests__run_tests(tests *t);
void tests__run_test(tests *t, char *name);

#endif // SCRAPSORT_INTEGRATION_TEST_HELPERS_H
