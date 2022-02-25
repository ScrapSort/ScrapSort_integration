#include "flags.h"

void f0() { printf("Flipper0 function\n"); }
void f1() { printf("Flipper1 function\n"); }
void f2() { printf("Flipper2 function\n"); }
void f3() { printf("Flipper3 function\n"); }
void f4() { printf("Flipper4 function\n"); }
void f5() { printf("Flipper5 function\n"); }
void f6() { printf("Camera function\n"); }

int main() {
  flag_callback flag_callbacks[num_flags];

  flag_callbacks[0] = f0;
  flag_callbacks[1] = f1;
  flag_callbacks[2] = f2;
  flag_callbacks[3] = f3;
  flag_callbacks[4] = f4;
  flag_callbacks[5] = f5;
  flag_callbacks[6] = f6;

  set_flag(Flipper1);
  set_flag(Flipper2);
  set_flag(Flipper4);
  unset_flag(Flipper1);

  printf("%i\n", is_flag_set(Flipper1));
  printf("%i\n", is_flag_set(Flipper2));
  printf("%i\n", is_flag_set(Flipper4));
  printf("\n");

  for (Flag f = 0; f < num_flags; f++) {
    if (is_flag_set(f)) {
      (*flag_callbacks[f])();
      unset_flag(f);
    }
  }

  return 0;
}
