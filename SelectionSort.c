#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* v, int n) {
    int temp, pmin;
    for (int i = 0; i < n; i++) {
        pmin = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[pmin]) {
                pmin = j;
            }
        }
        temp = v[pmin];
        v[pmin] = v[i];
        v[i] = temp;
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
