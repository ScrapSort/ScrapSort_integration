#ifndef SCRAPSORT_INTEGRATION_TEST_HELPERS_H
#define SCRAPSORT_INTEGRATION_TEST_HELPERS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void __assert_fn(const char *msg, const char *file, int line);
#define __assert(x) (bool)((x) || (__assert_fn(#x, __FILE__, __LINE__), 0))
#define assert(x)                                                              \
  if (!__assert(x))                                                            \
  return false

typedef struct test {
  char *name;
  char *group;
  bool (*fn)();
  struct test *next;
} test;

test *Test(char *name, char *group, bool (*fn)());

typedef struct tests {
  int num_tests;
  test *head;

} tests;

tests Tests();

void tests__add_test(char *name, char *group, bool (*fn)());
void tests__run_tests();
void tests__run_test(char *name);
void tests__run_test_group(char *group);

#endif // SCRAPSORT_INTEGRATION_TEST_HELPERS_H