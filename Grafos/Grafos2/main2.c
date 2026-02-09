#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
    GRAFO * g = criaGrafo(6);
    char nomes[6][50] = {"v0", "v1", "v2", "v3", "v4", "v5"};
    inicializaNomes(g, nomes);

    int dist[6], pred[6];

    criaArestaND(g,0,1,7);
    criaArestaND(g,0,2,9);
    criaArestaND(g,0,5,14);
    criaArestaND(g,1,2,10);
    criaArestaND(g,1,3,15);
    criaArestaND(g,2,3,11);
    criaArestaND(g,2,5,2);
    criaArestaND(g,3,4,6);
    criaArestaND(g,4,5,9);

    primMST(g,0);
    dijkstra(g, 0, dist, pred);
    imprimeCaminho(0, 4, pred, g);
    printf("\nDistancia total: %d\n", dist[4]);
}
