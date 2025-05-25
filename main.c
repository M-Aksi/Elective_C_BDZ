#include <stdio.h>
#include "MyList.h"
#include "delay.h"

#define SIZE 10 

int main() {
    
    DoublyLinkedList MyList;
    initList(&MyList);                       
    generateRandomList(&MyList, SIZE);

    printForward(&MyList);                 // десятичный вид
    printBinaryValue(&MyList);             // двоичный вид

    delay_ms(5000);                        // задержка отображения в консоли (Linux|Windows)
    
    freeList(&MyList);                     // освобождение памяти
    return 0;
}