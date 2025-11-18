#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main() {
    Hash* ha = criaHash(1427); // sempre numero primo e diferente de potencia de 2;
    struct aluno al;
    al.matricula = 1001;
    al.nome[30] = "Guilherme";
    al.n1 = 8.5;
    al.n2 = 7.5;
    al.n3 = 9.5;
    int mat1 = 1001;

    struct aluno al2;
    al2.matricula = 1002;
    al2.nome[30] = "Maria";
    al2.n1 = 8.5;
    al2.n2 = 7.5;
    al2.n3 = 9.5;
    int mat2 = 1002;

    int x = insereHash_SemColisao(ha, al);
    int x2 = buscaHash_SemColisao(ha, mat1, &al);
    int x3 = insereHash_SemColisao(ha, al2);
    int x4 = buscaHash_SemColisao(ha, mat2, &al2);
    printf("%d\n", x);
    printf("%d\n", x2);
    printf("%d\n", x3);
    printf("%d\n", x4);

    liberaHash(ha);
}
