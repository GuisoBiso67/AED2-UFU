#include <stdio.h>
#include <stdlib.h>

// estudar melhor!!!

int partition(int *v, int begin, int end) {
    int left, right, pivot, aux;
    left = begin;
    right = end;
    pivot = v[begin]; // nesse caso o pivô é o primeiro elemento;
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

void quickSort(int* v, int begin, int end) {
    int pivot;
    if (begin < end) { // semelhante ao merge;
        pivot = partition(v, begin, end);
        quickSort(v, begin, pivot-1);
        quickSort(v, pivot+1, end);
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

    quickSort(v,0,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
