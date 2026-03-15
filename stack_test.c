#include "stack.h"

int main() {
  Stack s;
  init_stack(&s);

  if (!is_empty(&s)) {
    return 1;
  }

  if (!push(&s, 10)) {
    return 1;
  }
  if (!push(&s, 20)) {
    return 1;
  }

  if (is_empty(&s)) {
    return 1;
  }

  int val;

  if (!pop(&s, &val) || val != 20) {
    return 1;
  }

  if (!pop(&s, &val) || val != 10) {
    return 1;
  }

  if (!is_empty(&s)) {
    return 1;
  }

  init_stack(&s);
  int i;
  for (i = 0; i < MAX_SIZE; ++i) {
    if (!push(&s, i)) {
      return 1;
    }
  }
  if (push(&s, 123)) {
    return 1;
  }

  init_stack(&s);
  if (pop(&s, &val)) {
    return 1;
  }

  return 0;
}