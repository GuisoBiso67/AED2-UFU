#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // para strcmp na questao 8;

/*
 * Q1
 * Ordenação: exibir resultados mais relevantes em pesquisas do google;
 * Achar menor: aplicativos de compras quando comparam preços;
 */

// Q2
void bubbleSort(int *v, int n){
    int temp, cont=0;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-1;j++){
            if(v[j]>v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                cont++;
            }
        }
        if (i==0 && cont==0){
            printf("\nORDENADO!\n");
            break;
        }
        if (cont == 0) { // para o 'for' se não houver nenhuma alteração;
            break;
        }
        cont=0;
    }
}

// Q3
void bubbleSortDescending(int *v, int n){
    int temp, cont=0;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-1;j++){
            if(v[j]<v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                cont++;
            }
        }
        if (cont == 0) { // para o 'for' se não houver nenhuma alteração;
            break;
        }
        cont=0;
    }
}

// Q4
void addExtra(int *v, int n, int x) {
    int i=n-1;
    while (i>= 0 && v[i]>x) { // começa de tras para frente;
        v[i+1]=v[i];
        i--;
    }
    v[i+1] = x;
}

// Q5
int findNumber(int *v, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i]==x) {
            return i;
        }
    }
    return -1; // se nao achar;
}

// Q6
int partition(int *v, int begin, int end) {
    int left, right, pivot, aux;
    left = begin;
    right = end;
    pivot = v[begin];
    while (left < right) { // "enquanto a direita estiver a direita";
        while (v[left] <= pivot && left <= end) left++; // anda para a direita se o elemento for menor que o pivô;
        while (v[right] > pivot && right >= 0) right--; // anda para a esquerda se o elemento for maior que o pivô;
        if (left < right) { // se os ponteiros ainda não se cruzaram, troca os elementos fora de posição (maior à esquerda e menor à direita);
            aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }
    }
    // retorna o 'right' que é o index do pivô;
    v[begin] = v[right];
    v[right] = pivot;
    return right;
}

struct pessoa{
    int matricula;
    char nome[30];
    float nota;
};

void bubbleSortName(struct pessoa *v, int n){
    struct pessoa temp;
    int cont=0;
    for (int i=0; i < n - 1; i++) {
        for (int j=0; j < n - 1; j++) {
            if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                cont++;
            }
        }
        if (cont == 0) { // para o 'for' se não houver nenhuma alteração;
            break;
        }
        cont = 0;
    }
}

void bubbleSortMatricula(struct pessoa *v, int n){
    struct pessoa temp;
    int cont=0;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-1;j++){
            if(v[j].matricula>v[j+1].matricula){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                cont++;
            }
        }
        if (cont == 0) { // para o 'for' se não houver nenhuma alteração;
            break;
        }
        cont=0;
    }
}

void bubbleSortNota(struct pessoa *v, int n){
    struct pessoa temp;
    int cont=0;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-1;j++){
            if(v[j].nota>v[j+1].nota){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                cont++;
            }
        }
        if (cont == 0) { // para o 'for' se não houver nenhuma alteração;
            break;
        }
        cont=0;
    }
}


void ordStruct(struct pessoa *v, int n, int op) {
    switch (op) {
        case 1:
            bubbleSortName(v, n);
            break;
        case 2:
            bubbleSortMatricula(v, n);
        case 3:
            bubbleSortNota(v, n);
        default:
            printf("Operacao Invalida!\n");
    }
}

int main() {
    int n;
    printf("Tamanho: ");
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));
    printf("Digite os numeros: ");
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    printf("Vetor original: ");
    for (int i=0;i<n;i++){
        printf("%d ", v[i]);
    }

    // Q2
    bubbleSort(v,n);
    printf("\nQ2 = Vetor Ordenado Crescente: ");
    for (int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    // Q3 (comentei aqui para nao atrapalhar o exercício 4)
    /*
    bubbleSortDescending(v,n);
    printf("\nQ3: Vetor Ordenado Decrescente: ");
    for (int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    */

    // Q4
    int x4;
    printf("Q4 = Numero para adicionar: ");
    scanf("%d",&x4);
    n += 1;
    v = realloc(v,n*sizeof(int));
    addExtra(v,n,x4);
    printf("\nNovo vetor: ");
    for (int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    //Q5
    int x5;
    printf("Q5 = Procurar numero: ");
    scanf("%d", &x5);
    int r = findNumber(v,n,x5);
    if (r == -1) {
        printf("Numero nao encontrado!\n");
    }else {
        printf("Numero encontrado! Posicao: %d", r);
    }
    printf("\n");

    //Q6
    int n2;
    printf("Tamanho do novo vetor: ");
    scanf("%d", &n2);
    int *v2 = malloc(n2 * sizeof(int));
    printf("Digite os numeros do novo vetor: ");
    for(int i=0;i<n2;i++){
        scanf("%d", &v2[i]);
    }
    int pivot = partition(v2,0,n2);
    printf("\nQ6 = Vetor Particionado: ");
    for (int i=0;i<n2;i++){
        printf("%d ", v2[i]);
    }
    printf("\nPivo: %d", v2[pivot]);
    printf("\n");


    //Q7
    /*
    LETRA A: 8, 9, 7, 9, 3, 2, 3, 8, 4, 6;
    1. Bubble Sort
    Passo 1: [8, 7, 9, 3, 2, 3, 8, 4, 6, 9] (9 comparações, 6 trocas)
    Passo 2: [7, 8, 3, 2, 3, 8, 4, 6, 9, 9] (8 comparações, 6 trocas)
    Passo 3: [7, 3, 2, 3, 8, 4, 6, 8, 9, 9] (7 comparações, 4 trocas)
    Passo 4: [3, 2, 3, 7, 4, 6, 8, 8, 9, 9] (6 comparações, 4 trocas)
    Passo 5: [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (5 comparações, 3 trocas)
    Passo 6: [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (4 comparações, 0 trocas)
    Total: 39 Comparações, 23 Trocas.

    2. Selection Sort
    Passo 1 (min=2): [2, 9, 7, 9, 3, 8, 3, 8, 4, 6] (9 comparações, 1 troca)
    Passo 2 (min=3): [2, 3, 7, 9, 9, 8, 3, 8, 4, 6] (8 comparações, 1 troca)
    Passo 3 (min=3): [2, 3, 3, 9, 9, 8, 7, 8, 4, 6] (7 comparações, 1 troca)
    Passo 4 (min=4): [2, 3, 3, 4, 9, 8, 7, 8, 9, 6] (6 comparações, 1 troca)
    Passo 5 (min=6): [2, 3, 3, 4, 6, 8, 7, 8, 9, 9] (5 comparações, 1 troca)
    Passo 6 (min=7): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (4 comparações, 1 troca)
    Passo 7 (min=8): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (3 comparações, 1 troca)
    Passo 8 (min=8): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (2 comparações, 1 troca)
    Passo 9 (min=9): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (1 comparações, 1 troca)
    Total: 45 Comparações, 9 Trocas.

    3. Insertion Sort
    Passo 1 (i=1): [8, 9, 7, 9, 3, 2, 3, 8, 4, 6] (1 comparações, 0 trocas)
    Passo 2 (i=2): [7, 8, 9, 9, 3, 2, 3, 8, 4, 6] (2 comparações, 2 trocas)
    Passo 3 (i=3): [7, 8, 9, 9, 3, 2, 3, 8, 4, 6] (1 comparações, 0 trocas)
    Passo 4 (i=4): [3, 7, 8, 9, 9, 2, 3, 8, 4, 6] (4 comparações, 4 trocas)
    Passo 5 (i=5): [2, 3, 7, 8, 9, 9, 3, 8, 4, 6] (5 comparações, 5 trocas)
    Passo 6 (i=6): [2, 3, 3, 7, 8, 9, 9, 8, 4, 6] (5 comparações, 4 trocas)
    Passo 7 (i=7): [2, 3, 3, 7, 8, 8, 9, 9, 4, 6] (2 comparações, 2 trocas)
    Passo 8 (i=8): [2, 3, 3, 4, 7, 8, 8, 9, 9, 6] (5 comparações, 5 trocas)
    Passo 9 (i=9): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (5 comparações, 5 trocas)
    Total: 30 Comparações, 27 Trocas/Deslocamentos.

    4. Merge Sort
    Divisão 1: [8, 9, 7, 9, 3] | [2, 3, 8, 4, 6]
    Divisão 2: [8, 9, 7] | [9, 3] | [2, 3, 8] | [4, 6]
    Divisão 3: [8] [9] | [7] | [9] [3] | [2] [3] | [8] | [4] [6]
    Merge 1: [8, 9] | [7] | [3, 9] | [2, 3] | [8] | [4, 6]
    Merge 2: [7, 8, 9] | [3, 9] | [2, 3, 8] | [4, 6]
    Merge 3: [3, 7, 8, 9, 9] | [2, 3, 4, 6, 8]
    Merge Final: [2, 3, 3, 4, 6, 7, 8, 8, 9, 9]
    Total: 24 Comparações (depende do tipo de implementação). Usa de 30 a 40 movimentos para arrays auxiliares.

    5. Quick Sort (Pivô = Primeiro Elemento)
    Passo 1 (Pivô=8): [8, 6, 7, 4, 3, 2, 3, 8, 9, 9] (Pivô no index 7)
    Recursão (Esquerda): Particionar [8, 6, 7, 4, 3, 2, 3]
    Passo 2 (Pivô=8): [3, 6, 7, 4, 3, 2, 8, 8, 9, 9] (Pivô no index 6)
    Recursão (Direita): Particionar [9, 9] (sub-array da 1ª chamada)
    Passo 3 (Pivô=9): [3, 6, 7, 4, 3, 2, 8, 8, 9, 9] (Pivô no index 9)
    Recursão (Esquerda): Particionar [3, 6, 7, 4, 3, 2]
    Passo 4 (Pivô=3): [3, 2, 3, 4, 7, 6, 8, 8, 9, 9] (Pivô no index 2)
    Recursão (Esquerda): Particionar [3, 2]
    Passo 5 (Pivô=3): [2, 3, 3, 4, 7, 6, 8, 8, 9, 9] (Pivô no index 1)
    Recursão (Direita): Particionar [4, 7, 6] (sub-array da 4ª chamada)
    Passo 6 (Pivô=4): [2, 3, 3, 4, 7, 6, 8, 8, 9, 9] (Pivô no index 3)
    Recursão (Direita): Particionar [7, 6]
    Passo 7 (Pivô=7): [2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (Pivô no index 5)
    Total (a): 40 Comparações, 11 Trocas.

    LETRA B: 89, 79, 32, 38, 46, 26, 43, 38, 32, 79;
    1. Bubble Sort
    Passo 1: [79, 32, 38, 46, 26, 43, 38, 32, 79, 89] (9 comparações, 8 trocas)
    Passo 2: [32, 38, 46, 26, 43, 38, 32, 79, 79, 89] (8 comparações, 6 trocas)
    Passo 3: [32, 38, 26, 43, 38, 32, 46, 79, 79, 89] (7 comparações, 4 trocas)
    Passo 4: [32, 26, 38, 38, 32, 43, 46, 79, 79, 89] (6 comparações, 3 trocas)
    Passo 5: [26, 32, 38, 32, 38, 43, 46, 79, 79, 89] (5 comparações, 3 trocas)
    Passo 6: [26, 32, 32, 38, 38, 43, 46, 79, 79, 89] (4 comparações, 1 troca)
    Passo 7: [26, 32, 32, 38, 38, 43, 46, 79, 79, 89] (3 comparações, 0 trocas)
    Total: 42 Comparações, 25 Trocas.

    2. Selection Sort
    Passo 1 (min=26): [26, 79, 32, 38, 46, 89, 43, 38, 32, 79] (9 comparações, 1 troca)
    Passo 2 (min=32): [26, 32, 79, 38, 46, 89, 43, 38, 32, 79] (8 comparações, 1 troca)
    Passo 3 (min=32): [26, 32, 32, 38, 46, 89, 43, 38, 79, 79] (7 comparações, 1 troca)
    Passo 4 (min=38): [26, 32, 32, 38, 46, 89, 43, 38, 79, 79] (6 comparações, 1 troca)
    Passo 5 (min=38): [26, 32, 32, 38, 38, 89, 43, 46, 79, 79] (5 comparações, 1 troca)
    Passo 6 (min=43): [26, 32, 32, 38, 38, 43, 89, 46, 79, 79] (4 comparações, 1 troca)
    Passo 7 (min=46): [26, 32, 32, 38, 38, 43, 46, 89, 79, 79] (3 comparações, 1 troca)
    Passo 8 (min=79): [26, 32, 32, 38, 38, 43, 46, 79, 89, 79] (2 comparações, 1 troca)
    Passo 9 (min=79): [26, 32, 32, 38, 38, 43, 46, 79, 79, 89] (1 comparações, 1 troca)
    Total: 45 Comparações, 9 Trocas.

    3. Insertion Sort
    Passo 1 (i=1): [79, 89, 32, 38, 46, 26, 43, 38, 32, 79] (1 comparações, 1 troca)
    Passo 2 (i=2): [32, 79, 89, 38, 46, 26, 43, 38, 32, 79] (2 comparações, 2 trocas)
    Passo 3 (i=3): [32, 38, 79, 89, 46, 26, 43, 38, 32, 79] (2 comparações, 2 trocas)
    Passo 4 (i=4): [32, 38, 46, 79, 89, 26, 43, 38, 32, 79] (2 comparações, 2 trocas)
    Passo 5 (i=5): [26, 32, 38, 46, 79, 89, 43, 38, 32, 79] (5 comparações, 5 trocas)
    Passo 6 (i=6): [26, 32, 38, 43, 46, 79, 89, 38, 32, 79] (3 comparações, 3 trocas)
    Passo 7 (i=7): [26, 32, 38, 38, 43, 46, 79, 89, 32, 79] (3 comparações, 3 trocas)
    Passo 8 (i=8): [26, 32, 32, 38, 38, 43, 46, 79, 89, 79] (7 comparações, 7 trocas)
    Passo 9 (i=9): [26, 32, 32, 38, 38, 43, 46, 79, 79, 89] (2 comparações, 2 trocas)
    Total: 27 Comparações, 27 Trocas/Deslocamentos

    4. Merge Sort
    Divisão 1: [89, 79, 32, 38, 46] | [26, 43, 38, 32, 79]
    Divisão 2: [89, 79, 32] | [38, 46] | [26, 43, 38] | [32, 79]
    Divisão 3: [89] [79] | [32] | [38] [46] | [26] [43] | [38] | [32] [79]
    Merge 1: [79, 89] | [32] | [38, 46] | [26, 43] | [38] | [32, 79]
    Merge 2: [32, 79, 89] | [38, 46] | [26, 38, 43] | [32, 79]
    Merge 3: [32, 38, 46, 79, 89] | [26, 32, 38, 43, 79]
    Merge Final: [26, 32, 32, 38, 38, 43, 46, 79, 79, 89]
    Total: 25 Comparações. Usa mais ou menos 40 movimentos.

    5. Quick Sort (Pivô = Primeiro Elemento)
    Passo 1 (Pivô=89): [79, 79, 32, 38, 46, 26, 43, 38, 32, 89] (Pivô no index 9)
    Recursão (Esquerda): Particionar [79, 79, 32, 38, 46, 26, 43, 38, 32]
    Passo 2 (Pivô=79): [32, 79, 32, 38, 46, 26, 43, 38, 79, 89] (Pivô no index 8)
    Recursão (Esquerda): Particionar [32, 79, 32, 38, 46, 26, 43, 38]
    Passo 3 (Pivô=32): [32, 26, 32, 38, 46, 79, 43, 38, 79, 89] (Pivô no index 2)
    Recursão (Esquerda): Particionar [32, 26]
    Passo 4 (Pivô=32): [26, 32, 32, 38, 46, 79, 43, 38, 79, 89] (Pivô no index 1)
    Recursão (Direita): Particionar [38, 46, 79, 43, 38]
    Passo 5 (Pivô=38): [26, 32, 32, 38, 38, 79, 43, 46, 79, 89] (Pivô no index 4)
    Recursão (Direita): Particionar [79, 43, 46]
    Passo 6 (Pivô=79): [26, 32, 32, 38, 38, 46, 43, 79, 79, 89] (Pivô no index 7)
    Recursão (Esquerda): Particionar [46, 43]
    Passo 7 (Pivô=46): [26, 32, 32, 38, 38, 43, 46, 79, 79, 89] (Pivô no index 6)
    Total (b): 46 Comparações, 9 Trocas.
     */

    //Q8
    int n8, op8;
    struct pessoa *v8;
    printf("Tamanho do vetor de structs: ");
    scanf("%d", &n8);
    v8 = malloc(n8*sizeof(struct pessoa));

    printf("Digite os dados do novo vetor: ");
    for(int i=0;i<n8;i++){
        printf("Nome pessoa %d: ", i);
        scanf(" %[^\n]", &v8[i].nome);
        printf("Matricula pessoa %d: ", i);
        scanf("%d", &v8[i].matricula);
        printf("Nota pessoa %d: ", i);
        scanf("%f", &v8[i].nota);
    }
    printf("1- Nome\n");
    printf("2- Matricula\n");
    printf("3- Nota\n");
    printf("Ordenar por: ");
    scanf("%d", &op8);
    ordStruct(v8,n8,op8);

    for (int i=0;i<n8;i++){
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n", v8[i].nome, v8[i].matricula, v8[i].nota);
    }
    /*
    Teste da questao 8, deu certo :)
    Jose Oliveira
    105
    8.5
    Ana Silva
    102
    9.0
    Carlos Pereira
    108
    7.2
    Mariana Costa
    101
    10.0
    Bruno Ferreira
    109
    6.5
    Zelia Santos
    110
    8.8
    Thiago Almeida
    107
    9.5
    Beatriz Lima
    104
    5.0
    Felipe Azevedo
    103
    7.8
    Gabriela Rocha
    106
    9.2
    */

    free(v);
    free(v2);
    free(v8);
}
