#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // tamanho do balde
struct bucket {
    int qtd;
    int values[SIZE];
};

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

void bucketSort(int* v, int n) {
    int i, j, bigger, smaller, numBuckets, pos;
    struct bucket *bkt;

    // acha maior e menor valor
    bigger = smaller = v[0];
    for (i=1;i<n;i++) {
        if (v[i]>bigger) bigger = v[i];
        if (v[i]<smaller) smaller = v[i];
    }

    // inicializa baldes
    numBuckets = (bigger - smaller) / SIZE + 1;
    bkt = (struct bucket*)malloc(sizeof(struct bucket) * numBuckets); // separa espaço de memória para o struct bkt;
    for (i=0;i<numBuckets;i++) bkt[i].qtd = 0; // zera as posições so bkt;

    // distribui os valores nos baldes;
    for (i=0;i<n;i++) {
        pos = (v[i]-smaller)/SIZE; // Calcula em qual balde (pos) o valor v[i] deve ser colocado;
        // Insere o valor v[i] no próximo slot livre do balde pos;
        // bkt[pos].qtd é a quantidade atual de elementos no balde;
        // usá-la como índice coloca o novo valor na próxima posição disponível do array values do balde;
        bkt[pos].values[bkt[pos].qtd] = v[i];
        bkt[pos].qtd++;
    }
    // ordena baldes e coloca no array;
    pos = 0;
    for (i=0;i<numBuckets;i++) {
        bubbleSort(bkt[i].values,bkt[i].qtd);
        // copia os valores ordenados do balde para o vetor original;
        for (j=0;j<bkt[i].qtd;j++) {
            v[pos] = bkt[i].values[j];
            pos++;
        }
    }
    free(bkt);
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

    bucketSort(v,n);

    printf("Vetor Ordenado: ");
    for (int i=0;i<n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    free(v);
}
