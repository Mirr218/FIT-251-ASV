#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

void init_stack(Stack *s);
int is_empty(Stack *s);
int push(Stack *s, int value);
int pop(Stack *s, int *result);

#endif