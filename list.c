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
