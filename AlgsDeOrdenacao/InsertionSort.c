#include <stdio.h>
#include <stdlib.h>
/*
 *
EX: 2 1 3 5 4

IT 1
i = 1; j = 0;
temp = 1;
IT 1.1 (temp < 2? sim && 0 >= 0? sim)
v[1] = 2;
j = -1;
PARA IT 1.1
v[0] = 1
VETOR: 1 2 3 5 4

IT 2
i = 2; j = 1;
temp = 3;
IT 2.1 (temp < 1? não)
PARA IT 2.1
v[2] = 3;
VETOR: 1 2 3 5 4

IT 3
i = 3; j = 2;
temp = 5;
IT 3.1 (temp < 3? nao)
PARA IT 3.1
v[3] = 5;
VETOR: 1 2 3 5 4

IT 4
i = 4; j = 3;
temp = 4
IT 4.1 (temp < 5? sim && 3 >= 0? sim)
v[4] = 5;
j = 2;
IT 4.2 (temp < 3? não)
PARA IT 4.1
v[3] = 4
VETOR: 1 2 3 4 5 OK
 ----------------------------------------
EX2: 5 4 3 2 1

IT 1
i = 1; j = 0;
temp = 1;
IT 1.1 (temp < 5? sim && 0 >= 0? sim)
v[1] = 5;
j = -1;
PARA IT 1.1
v[0] = 4
VETOR: 4 5 3 2 1

IT 2
i = 2; j = 1;
temp = 3;
IT 2.1 (temp < 4? sim && 1 >= 0? sim)
v[2] = 5;
j = 0;
IT 2.2 (temp < 4? sim && 0 >= 0? sim)
v[1] = 4;
j = -1
PARA IT 2.2
v[0] = 3
VETOR: 3 4 5 2 1

ja deu pra entender

*/
void insertionSort(int* v, int n) {
    int j, temp;
    for (int i = 1; i < n; i++) {
        temp = v[i]; // guarda o elemento atual; a partir daqui v[i] vira um buraco para deslocar os elementos maiores dentro do while;
        j = i - 1; // pega tamanho do vetor que já está ordenado (a esquerda);
        while (temp < v[j] && j>=0) { // entra no loop se o valor atual é menor;
            v[j+1] = v[j]; // o da frente vira o anterior para "abrir espaço";
            j--; // diminui o J para manter o loop, se necessário;
        }
        v[j+1] = temp; // se não entrar no loop, ele apenas é adicionado a parte ja ordenada;
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
