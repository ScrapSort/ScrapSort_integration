#ifndef SCRAPSORT_INTEGRATION_FLAGS_H
#define SCRAPSORT_INTEGRATION_FLAGS_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum Flag {
  Flipper0,
  Flipper1,
  Flipper2,
  Flipper3,
  Flipper4,
  Flipper5,
  Camera,
  num_flags
} Flag;

void set_flag(Flag f);
void unset_flag(Flag f);
bool is_flag_set(Flag f);

typedef void (*flag_callback)(void);

#endif // SCRAPSORT_INTEGRATION_FLAGS_H