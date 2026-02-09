#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../grafo.h"

// Lista de Adjacência;

int main() {
    Grafo *gr;
    gr = cria_grafo(10,7,0);
    insereAresta(gr,0,1,0,0);
    insereAresta(gr,1,3,0,0);
    removerAresta(gr,0,1,0);

    libera_grafo(gr);
}
