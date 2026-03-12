#include "stack.h"

void init_stack(Stack *s) { s->top = -1; }

int is_empty(Stack *s) { return s->top == -1; }

int push(Stack *s, int value) {
  if (s->top >= MAX_SIZE - 1) {
    return 0; // ошибка: переполнение
  }
  s->data[++s->top] = value;
  return 1; // успех
}

int pop(Stack *s, int *result) {
  if (is_empty(s)) {
    return 0; // ошибка: стек пуст
  }
  *result = s->data[s->top--];
  return 1; // успех
}