#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Структура узла
struct Node {
  int y;
  struct Node *next;
};

// Объявления функций
struct Node *f(int x);
struct Node *f1(struct Node *start, int x);
struct Node *f2(struct Node *start, int x);
struct Node *f3(struct Node *start, int x, int n);
struct Node *f4(struct Node *start, int n);
int f5(struct Node *start, int n);
int f6(struct Node *start);
void f7(struct Node *start);
void f8(struct Node *start);

#endif