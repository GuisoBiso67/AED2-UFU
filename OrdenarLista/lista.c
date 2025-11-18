//
// Created by guiso on 11/17/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void initList(Descriptor *list) {
    list->start = NULL;
    list->end = NULL;
    list->quant = 0;
}

void addAtBeginning(Descriptor *list, int value) {
    Node *newNode = malloc(sizeof(Node)); // aloca espaço para o nó
    newNode->value = value; // coloca o valor no nó
    newNode->next = list->start; // aponta para o antigo inicio da lista
    if (list->start == NULL && list->end == NULL) { // caso se não existir nenhum elemento
        list->start = newNode;
        list->end = newNode;
        list->quant += 1;
    }else {
        if (list->quant == 1) list->end = list->start; // se quantidade é 1, end e start são o mesmo nó
        list->start = newNode; // novo nó é o primeiro
        list->quant += 1; // incrementa quantidade
    }
}

void addAtEnd(Descriptor *list, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL; // último nó aponta para NULL
    if (list->start == NULL && list->end == NULL) { // caso se não tiver nenhum elemento
        list->start = newNode;
        list->end = newNode;
        list->quant += 1;
    }else {
        list->end->next = newNode; // o next do atual fim será o novo último nó
        list->end = newNode; // list->end é o novo nó
        list->quant += 1;
    }
}

void removeFromBeginning(Descriptor *list) {
    if (list->quant == 0) printf("Lista vazia\n"); // se a quantidade é zero, não tem o que remover
    Node *temp = list->start; // nó temporário
    list->start = list->start->next; // nó de inicio é o proximo
    free(temp); // libera o antigo nó de inicio
    list->quant -= 1; // decrementa a quantidade
}
void removeFromEnd(Descriptor *list) {
    if (list->quant == 0) printf("Lista vazia\n");
    Node *temp = list->end; // nó temporário
    Node *temp2 = list->start; // ponteiro para percorrer a lista
    while (temp2->next != list->end) { // percorre lista até o penúltimo
        temp2 = temp2->next;
    }
    list->end = temp2; // fim será o penúltimo
    free(temp); // libera o antigo último nó
    temp2->next = NULL; // next do último nó aponta para NULL pq é o fim da lista
    list->quant -= 1; // decrementa a quantidade
}

void removeElement(Descriptor *list, int element) {
    if (list->quant == 0) printf("Lista vazia\n");
    Node *current = list->start; // atual é o início
    Node *before = NULL; // anterior é NULL
    while (current != NULL && current->value != element) { // loop para verificar se o elemento existe
        before = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Elemento nao encontrado!\n");
    }else {
        if (current == list->start) { // se o elemento é o primeiro
            removeFromBeginning(list);
        }else if (current == list->end) { // se o elemento é o último
            removeFromEnd(list);
        }else { // se o elemento está no meio da lista
            before->next = current->next; // before pula o nó current e aponta para o proximo
            free(current); // libera current
            list->quant -= 1; // decrementa quantidade
        }
    }
}
void showList(Descriptor *list) {
    Node *temp = list->start;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\nFirst Element: %d\n", list->start->value);
    printf("Last Element: %d\n", list->end->value);
    printf("Quantity of Elements: %d\n", list->quant);
}

void insertionSort(Descriptor *list) {
    if (list->quant == 0) {
        printf("Lista vazia\n");
        return;
    }
    Node *sortedList = NULL;        // lista que vai ficando ordenada
    Node *current = list->start;    // percorre a lista original
    while (current != NULL) {
        // Guarda o próximo nó ANTES de mexer nos ponteiros
        Node *next = current->next;
        /*
            AGORA vamos inserir 'current' dentro da sortedList.
            MESMA IDEIA DO INSERTION SORT:
            -> achar a posição correta
            -> inserir lá
        */
        // Caso 1: sortedList vazia
        if (sortedList == NULL) {
            sortedList = current;
            current->next = NULL;
        }
        // Caso 2: current deve ir no início da lista ordenada
        else if (current->value < sortedList->value) {
            current->next = sortedList;
            sortedList = current;
        }
        // Caso 3: inserir no meio ou no fim
        else {
            Node *prev = sortedList;
            Node *scan = sortedList->next;
            // Anda até encontrar onde o valor deve entrar
            while (scan != NULL && current->value >= scan->value) {
                prev = scan;
                scan = scan->next;
            }
            // Insere entre 'prev' e 'scan'
            prev->next = current;
            current->next = scan;
        }
        // Avança na lista original
        current = next;
    }
    // Atualiza descritor
    list->start = sortedList;
    // Acha o último nó para atualizar o 'end'
    Node* scan = sortedList;
    while (scan->next != NULL) {
        scan = scan->next;
    }
    list->end = scan;
}


