#include "stack.h"
#include <stdio.h>

int main() {
  Stack s;
  init_stack(&s);

  if (is_empty(&s)) {
    printf("Stack is empty: OK\n");
  }

  push(&s, 10);
  push(&s, 20);

  int val;
  if (pop(&s, &val) && val == 20) {
    printf("Pop 20: OK\n");
  }
  if (pop(&s, &val) && val == 10) {
    printf("Pop 10: OK\n");
  }
  if (is_empty(&s)) {
    printf("Stack is empty again: OK\n");
  }

  printf("All tests passed!\n");
  return 0;
}