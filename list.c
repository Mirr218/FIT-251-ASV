#include <stdio.h>
#include <stdlib.h>


// Структура узла
struct Node {
    int y;              
    struct Node* next;   // указатель на следующий
};

// Функция создания нового узла (f)
struct Node* f(int x) {
    struct Node* nov = malloc(sizeof(struct Node));
    nov->y = x;
    nov->next = NULL;
    return nov;
}

// Добавление в начало (f1)
struct Node* f1(struct Node* start, int x) {
    struct Node* nov = f(x);
    nov->next = start;
    return nov;
}

// Добавление в конец (f2)
struct Node* f2(struct Node* start, int x) {
    struct Node* nov = f(x);
    
    if (start == NULL) {
        return nov;
    }
    
    struct Node* a = start;  
    while (a->next != NULL) {
        a = a->next;
    }
    
    a->next = nov;
    return start;
}

// Добавление по позиции (f3)
struct Node* f3(struct Node* start, int x, int n) {      if (n == 0) {
        return f1(start, x);
    }
    
    struct Node* nov = f(x);
    struct Node* a = start;
    
    for (int i = 0; i < n - 1; i++) {
        a = a->next;
    }
    
    nov->next = a->next;
    a->next = nov;
    
    return start;
}

// Удаление по позиции (f4)
struct Node* f4(struct Node* start, int n) {
    if (n == 0) {
        struct Node* vr = start;   
        start = start->next;
        free(vr);
        return start;
    }
    
    struct Node* a = start;
    
    for (int i = 0; i < n - 1; i++) {
        a = a->next;
    }
    
    struct Node* vr = a->next;
    a->next = vr->next;
    free(vr);
    
    return start;
}

// Поиск по позиции (f5)
int f5(struct Node* start, int n) {
    struct Node* a = start;
    
    for (int i = 0; i < n; i++) {
        a = a->next;
    }
    
    return a->y;
}

// Подсчет элементов (f6)
int f6(struct Node* start) {
    int kol = 0;              
    struct Node* a = start;
    
    while (a != NULL) {
        kol++;
        a = a->next;
    }
    
    return kol;
}

// Печать списка (f7)
void f7(struct Node* start) {
    struct Node* a = start;
    
    printf("Список: ");
    while (a != NULL) {
        printf("%d ", a->y);
        a = a->next;
    }
    printf("\n");
}

// Очистка памяти (f8)
void f8(struct Node* start) {
    struct Node* a = start;
    
    while (a != NULL) {
        struct Node* vr = a;
        a = a->next;
        free(vr);
    }
}
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