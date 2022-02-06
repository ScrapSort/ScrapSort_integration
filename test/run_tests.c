#include "test_helpers.h"
#include "tests.h"

int main(int argc, char *argv[]) {
  tests t = Tests();
  initialize_tests(&t);

  if (argc == 2) // Run specific test (name passed as command line argument)
    tests__run_test(&t, argv[1]);
  else // Otherwise run all tests
    tests__run_tests(&t);

  return 0;
}
