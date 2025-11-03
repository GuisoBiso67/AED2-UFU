#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int begin, int middle, int end) {
    int *temp, p1, p2, size, i, j, k;
    int end1=0, end2=0;
    size = end-begin+1;
    p1=begin; // inicio vetor a esquerda;
    p2=middle+1; // inicio vetor a direita;
    temp = (int*)malloc(size*sizeof(int)); // vetor temporario;
    if (temp!=NULL) {
        for (i=0;i<size;i++) {
            if (!end1 && !end2) {
                if (v[p1] < v[p2]) temp[i] = v[p1++]; // copia o valor e soma +1;
                else temp[i] = v[p2++];

                if (p1>middle) end1=1; // verifica se vetor acabou;
                if (p2>end) end2=1;
            }else {
                if (!end1) temp[i] = v[p1++]; // se o primeiro vetor ainda tem elementos, adiciona eles no vetor temporario;
                else temp[i] = v[p2++];
            }
        }
        for (j=0, k=begin; j<size; j++, k++) v[k] = temp[j]; // copia temp para o vetor original;
    }
    free(temp);
}

void mergeSort(int* v, int begin, int end) { // função para dividir o vetor
    int middle;
    if (begin < end) {
        middle = floor((begin + end) / 2);
        mergeSort(v, begin, middle);
        mergeSort(v, middle + 1, end);
        merge(v, begin, middle, end);
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

    mergeSort(v,0,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
