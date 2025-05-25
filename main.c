#include <stdio.h>
#include "MyList.h"
#include <Windows.h>

#define SIZE 10 

int main() {
    printf("It's OK!\n");
    DoublyLinkedList MyList;
    DoublyLinkedList* ptrMyList = &MyList;
    initList(ptrMyList);
    generateRandomList(ptrMyList, SIZE);
    printForward(ptrMyList);

    // задержка отображения в консоли
    Sleep(5000);
    return 0;
}