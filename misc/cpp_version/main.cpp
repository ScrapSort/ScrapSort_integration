#include <iostream>

#include "Queue.h"
#include "Sorter.h"

int main() {

  // TEST QUEUE

  Queue q;

  q.push(true);
  q.push(true);
  q.push(false);
  q.push(true);

  std::cout << q.pop() << std::endl; // T
  std::cout << q.pop() << std::endl; // T
  std::cout << q.pop() << std::endl; // F
  std::cout << q.pop() << std::endl; // T

  // TEST SORTER

  Sorter s;

  s.add_item(2);
  s.add_item(1);

  std::cout << s.detected_item(0) << std::endl; // F
  std::cout << s.detected_item(1) << std::endl; // F
  std::cout << s.detected_item(2) << std::endl; // T
  std::cout << s.detected_item(0) << std::endl; // F
  std::cout << s.detected_item(1) << std::endl; // T

}