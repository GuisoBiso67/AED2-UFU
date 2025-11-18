#ifndef LISTA_H
#define LISTA_H

// Estrutura para representar um nó da lista encadeada
typedef struct Node {
    int value; // Valor armazenado no nó
    struct Node *next; // Ponteiro para o próximo nó
} Node;

// Estrutura para o nó descritor
typedef struct {
    Node *start; // Ponteiro para o início da lista
    Node *end; // Ponteiro para o final da lista
    int quant; // Quantidade de elementos na lista
} Descriptor;

void initList(Descriptor *list);
void addAtBeginning(Descriptor *list, int value);
void addAtEnd(Descriptor *list, int value);
void removeFromBeginning(Descriptor *list);
void removeFromEnd(Descriptor *list);
void removeElement(Descriptor *list, int element);
void showList(Descriptor *list);

void insertionSort(Descriptor *list);

#endif //LISTA_H
