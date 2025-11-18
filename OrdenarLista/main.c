#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    Descriptor list;
    initList(&list);

    // testando addAt
    addAtBeginning(&list, 1);
    addAtEnd(&list, 3);
    addAtBeginning(&list, 2);
    addAtEnd(&list, 7);
    addAtBeginning(&list, 5);
    addAtEnd(&list, 8);
    addAtBeginning(&list, 7);
    addAtEnd(&list, 6);
    addAtBeginning(&list, 10);
    addAtEnd(&list, 9);
    showList(&list);

    insertionSort(&list);
    showList(&list);
}
