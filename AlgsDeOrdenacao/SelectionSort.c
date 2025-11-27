#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* v, int n) {
    int temp, pmin;
    for (int i = 0; i < n; i++) {
        pmin = i; // salva valor de i
        for (int j = i + 1; j < n; j++) { // loop para achar a posição do menor valor;
            if (v[j] < v[pmin]) { // se o valor do proximo é menor;
                pmin = j; // o pmin vira o j (que é a posição do menor);
            }
        }
        // troca tipo um bubble;
        temp = v[pmin];
        v[pmin] = v[i];
        v[i] = temp;
        // repete com i + 1 para achar o proximo menor valor;
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

    selectionSort(v,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
