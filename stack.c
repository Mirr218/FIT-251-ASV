#include "stack.h"
#include <stdlib.h>

#define SUCCESS_STACK 1
#define ERROR_STACK 0

void init_stack(Stack *s, int size) {
  if (size <= 0 || size > MAX_SIZE) {
    s->data = NULL;
    s->top = -1;
    s->size = 0;
    return;
  }

  s->data = (int *)malloc(size * sizeof(int));
  if (s->data == NULL) {
    s->top = -1;
    s->size = 0;
    return;
  }

  s->top = -1;
  s->size = size;
}

void destroy_stack(Stack *s) {
  if (s->data != NULL) {
    free(s->data);
    s->data = NULL;
  }
  s->top = -1;
  s->size = 0;
}

int is_empty(Stack *s) { return s->top == -1; }

int push(Stack *s, int value) {
  if (s->data == NULL || s->top >= s->size - 1) {
    return ERROR_STACK;
  }
  s->data[++s->top] = value;
  return SUCCESS_STACK;
}

int pop(Stack *s, int *result) {
  if (s->data == NULL || is_empty(s)) {
    return ERROR_STACK;
  }
  *result = s->data[s->top--];
  return SUCCESS_STACK;
}
