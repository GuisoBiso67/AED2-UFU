#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int n) {
    int j, temp;
    for (int i = 1; i < n; i++) {
        temp = v[i]; // armazena valor atual;
        j = i - 1; // pega tamanho do vetor que já está ordenado (a esquerda);
        while (temp < v[j] && j>=0) { // entra no loop se o valor atual é menor;
            v[j+1] = v[j]; // o da frente vira o anterior para "abrir espaço";
            j--; // diminui o J para manter o loop, se necessário;
        }
        v[j+1] = temp; // se não entra no loop, ele apenas é adicionado a parte ja ordenada;
    }
}

int main() {
    int n; // tamanho do vetor
    printf("Tamanho do vetor: ");
    scanf("%d",&n);
    int *v = malloc(sizeof(int)*n);
    printf("Digite os valores: ");
    for (int i=0;i<n;i++) {
        scanf("%d",&v[i]);
    }

    printf("Vetor Original: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    insertionSort(v,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
