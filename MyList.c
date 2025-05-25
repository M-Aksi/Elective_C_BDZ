#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "MyList.h"


// Функция для инициализации списка
void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


// Функция выделения памяти под новый узел
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);                                 // аварийное завершение 
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Функция добавления элемента в конец списка
void append(DoublyLinkedList* list, int value) {
    Node* newElement = createNode(value); 
    if (list -> head == NULL){                   // если список пустой
        newElement -> prev = NULL;
        list -> head = newElement;
    }
    else {                                       // уже не пустой
        newElement -> prev = list -> tail;       // связь текущего с предыдущим
        list -> tail -> next = newElement;       // связь предыдущего с текущим
    }
    list -> tail = newElement;                   // переопределение конца(указателя) на новый элемент
    ++(list -> size);                            // увеличение списка
}

// Функция освобождения памяти
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;                 // освобождаем память, запоминая указатель на следующий элемент
        free(temp);
    }
    list->head = NULL;                           // уничтожаем указатели непосредственно списка
    list->tail = NULL;
    list->size = 0;
}

void print_forward(const DoublyLinkedList* list){

}


