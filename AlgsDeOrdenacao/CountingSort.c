#include <stdio.h>
#include <stdlib.h>

#define K 1001
void countingSort(int* v, int n) {
    int i, j, k;
    int buckets[K]; // define um vetor auxiliar de 100 casas;
    for (i=0;i<K;i++) buckets[i] = 0; // zera o vetor auxiliar;

    // incrementa a casa no vetor auxiliar com o número em v[i]; Ex: if v[i] = 5, buckets[5]++;
    for (i=0;i<n;i++) buckets[v[i]]++;

    // reconstruindo o vetor ordenado;
    for (i=0, j=0; j<K; j++) { // para cada número possível (0 a K-1), verifica quantas vezes ele aparece;
        // coloca o número 'j' de volta no vetor v (original), na quantidade registrada em buckets[j];
        for (k = buckets[j]; k > 0; k--) v[i++] = j;
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

    countingSort(v,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
