#include "stack.h"
#include <assert.h>

#define SUCCESS_STACK 1
#define ERROR_STACK 0

void test_init_stack_is_empty() {
  Stack s;

  init_stack(&s, 10);

  assert(is_empty(&s));

  destroy_stack(&s);
}

void test_push_pop_lifo_order() {
  Stack s;
  int val;

  init_stack(&s, 10);
  push(&s, 10);
  push(&s, 20);

  pop(&s, &val);
  assert(val == 20);

  pop(&s, &val);
  assert(val == 10);
  assert(is_empty(&s));

  destroy_stack(&s);
}

void test_push_until_full() {
  Stack s;
  int i;

  init_stack(&s, MAX_SIZE);
  for (i = 0; i < MAX_SIZE; ++i) {
    push(&s, i);
  }

  int result = push(&s, 123);

  assert(result == ERROR_STACK);

  destroy_stack(&s);
}

void test_pop_from_empty_returns_error() {
  Stack s;
  int val;

  init_stack(&s, 10);

  int result = pop(&s, &val);

  assert(result == ERROR_STACK);

  destroy_stack(&s);
}

void test_invalid_size_initialization() {
  Stack s;

  init_stack(&s, 0);

  assert(s.data == NULL);
  assert(s.size == 0);
  assert(is_empty(&s));

  destroy_stack(&s);
}

int main() {
  test_init_stack_is_empty();
  test_push_pop_lifo_order();
  test_push_until_full();
  test_pop_from_empty_returns_error();
  test_invalid_size_initialization();
  return 0;
}
