#include "list.h"
int main() {
    struct Node* start = NULL;  
    int k, x, n;           
    
    while (1) {
        printf("\nМЕНЮ \n");
        printf("1 - Добавить в начало\n");
        printf("2 - Добавить в конец\n");
        printf("3 - Добавить по номеру\n");
        printf("4 - Удалить по  номеру\n");
        printf("5 - Найти по  номеру\n");
        printf("6 - Посчитать элементы\n");
        printf("7 - Показать список\n");
        printf("0 - Выход\n");
        printf("Выберите: ");
        scanf("%d", &k);
        
        if (k == 1) {
            printf("Введите число: ");
            scanf("%d", &x);
            start = f1(start, x);
            f7(start);
        }
        else if (k == 2) {
            printf("Введите число: ");
            scanf("%d", &x);
            start = f2(start, x);
            f7(start);
        }
        else if (k == 3) {
            printf("Введите число: ");
            scanf("%d", &x);
            printf("Введите  номер : ");
            scanf("%d", &n);
            start = f3(start, x, n);
            f7(start);
        }
        else if (k == 4) {
            printf("Введите  номер: ");
            scanf("%d", &n);
            start = f4(start, n);
            f7(start);
        }
        else if (k == 5) {
            printf("Введите  номер: ");
            scanf("%d", &n);
            x = f5(start, n);
            printf("На позиции %d число: %d\n", n, x);
        }
        else if (k == 6) {
            printf("Количество элементов: %d\n", f6(start));
        }
        else if (k == 7) {
            f7(start);
        }
        else if (k == 0) {
            printf("Программа завершена\n");
            f8(start);
            break;
        }
        
    }
    
    return 0;
}