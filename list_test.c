#include "list.h"
int main() {
  struct Node *start = NULL;
  int k, x, n;

  // 1 - Добавление в начало 3,2,1;
  start = f1(start, 3);
  start = f1(start, 2);
  start = f1(start, 1);
  if (f5(start, 0) != 1 || f5(start, 1) != 2 || f5(start, 2) != 3) {
    return 1;
  }

  // 2 - Добавление в конец 5,6
  start = f2(start, 5);
  start = f2(start, 6);
  if (f5(start, 3) != 5 || f5(start, 4) != 6) {
    return 1;
  }

  // 3 - Добавление 4 по номеру 3
  start = f3(start, 4, 3);
  if (f5(start, 3) != 4) {
    return 1;
  }

  // 4 - Удаление по  номеру 0
  start = f4(start, 0);
  if (f5(start, 0) != 2) {
    return 1;
  }

  // 5 - Найти по  номеру 1
  x = f5(start, 1);
  if (x != 3) {
    return 1;
  }

  n = f6(start);
  if (n != 5) {
    return 1;
  }

  return 0;
}