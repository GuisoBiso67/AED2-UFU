#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main() {
    // QUESTAO 1
    /* RESULTADO DA IMPRESSÃO DA QUESTAO 1, MUITO FODA.
     * ---------------
        0: NULL
        1: 9 -> NULL
        2: NULL
        3: NULL
        4: 11 -> 10 -> NULL
        5: 7 -> 4 -> 2 -> NULL
        6: 8 -> 6 -> NULL
        7: 5 -> 1 -> NULL
        8: NULL
        9: 3 -> NULL
        10: NULL
    ---------------------

    int tam = 11;
    Hash *tab = criaHash(tam);
    struct number num, n[11]={
        {1, 12},
        {2, 44},
        {3, 13},
        {4, 88},
        {5, 23},
        {6, 94},
        {7, 11},
        {8, 39},
        {9, 20},
        {10, 16},
        {11, 5}
    };
    for (int i = 0; i < tam; i++) {
        insereHash_EncadSep(tab, n[i]);
    }
    for (int i = 0; i < tam; i++) {
        printf("%d: ", i);
        struct number *aux = tab->itens[i];
        while (aux != NULL) {
            printf("%d -> ", aux->n);  // ou aux->n, dependendo do que quer mostrar
            aux = aux->next;
        }
        printf("\n");
    }
    liberaHash(tab);
    */

    /* QUESTAO 2
    int tam = 10;
    Hash *tabela = criaHash(tam);
    int totalColisoes = 0;
    struct number num, n[6]={{1, 371},
                    {2, 121},
                    {3, 173},
                    {4, 203},
                    {5, 11},
                    {6, 24}};
    for (int i = 0; i < 6; i++) {
        insereHash_Contando(tabela, n[i], &totalColisoes);
    }

    printf("Total de Colisoes: %d\n", totalColisoes);
    /*
     * SondagemLinear2 = 8 colisoes;
     * SondagemQuadratica2 = 6 colisoes;
     * SondagemQuadratica3 = 5 colisoes;
     * DuploHash2 = 0 colisoes;

    liberaHash(tabela);
    */

    /*
    // QUESTAO 3 // Saida do J = 2: J -> S -> A -> G -> M -> D ->;
    int quantItens = 13;
    int tam = 3;
    Hash *tab = criaHash(tam);
    struct number num, n[13]={
        {2, 'D'},
        {0, 'Q'},
        {0, 'B'},
        {1, 'I'},
        {2, 'M'},
        {0, 'H'},
        {2, 'G'},
        {1, 'U'},
        {2, 'A'},
        {1, 'C'},
        {1, 'R'},
        {1, 'S'},
        {2, 'J'}
    };
    for (int i = 0; i < quantItens; i++) {
        insereHash_EncadSep(tab, n[i]);
    }
    for (int i = 0; i < tam; i++) {
        printf("%d: ", i);
        struct number *aux = tab->itens[i];
        while (aux != NULL) {
            printf("%c -> ", aux->key);
            aux = aux->next;
        }
        printf("\n");
    }
    liberaHash(tab);
    */

    // QUESTAO 4, nao entendi muito bem
    // Saída: I -> C -> W -> Y -> L -> Z -> E -> O -> K -> P ->
    int quantItens = 10;
    int tam = 10;
    Hash *tab = criaHash(tam);
    struct number num, n[10]={
        {3, 'I'},
        {7, 'C'},
        {7, 'W'},
        {9, 'Y'},
        {6, 'L'},
        {0, 'Z'},
        {9, 'E'},
        {9, 'O'},
        {5, 'K'},
        {0, 'P'}
    };
    for (int i = 0; i < quantItens; i++) {
        insereHash_EnderAberto(tab, n[i]);
    }
    for (int i = 0; i < tam; i++) {
        printf("%c -> ", n[i].key);
    }
    liberaHash(tab);



}