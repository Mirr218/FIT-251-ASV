#include "list.h"
int main() {
  struct Node *start = NULL;
  int k, x, n;

  printf("1 - Добавление в начало 3,2,1\n");
  start = f1(start, 3);
  start = f1(start, 2);
  start = f1(start, 1);
  f7(start);

  printf("2 - Добавление в конец 5,6\n");
  start = f2(start, 5);
  start = f2(start, 6);
  f7(start);

  printf("3 - Добавление 4 по номеру 3\n");
  start = f3(start, 4, 3);
  f7(start);

  printf("4 - Удаление по  номеру 5\n");
  start = f4(start, 5);
  f7(start);

  printf("5 - Найти по  номеру 0\n");
  x = f5(start, 0);
  printf("Элемент на позиции 0: %d\n", x);

  n = f6(start);
  printf("Количество элементов: %d\n", n);

  printf("7 - Список\n");
  f7(start);

  return 0;
}