#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* v, int n) {
    int temp;
    int cont=0;
    for (int i=0;i<=14;i++) {
        if (v[i]>v[i+1]) {
            temp = v[i];
            v[i] = v[i+1];
            v[i+1] = temp;
            cont++;
        }
    }
    if (cont == 0) { // verifica se alguma mudança foi feita. Se sim, ele para as iterações;
        return;
    }
    bubbleSort(v,n-1);
}

int main() {
    int n; // tamnho do vetor
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

    bubbleSort(v,n);
    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
