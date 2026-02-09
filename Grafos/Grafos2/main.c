#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
    GRAFO * gr = criaGrafo(6);
    char nomes[6][50] = {"Uberlandia", "Araguari", "Uberaba", "Patos de Minas", "Monte Alegre", "Ituiutaba"};
    inicializaNomes(gr, nomes);

    int dist[6], pred[6];

    // Uberlandia até
    criaArestaND(gr, 0, 1, 38); // Araguari
    criaArestaND(gr, 0, 2, 105); // Uberaba
    criaArestaND(gr, 0, 3, 216); // Patos de Minas
    criaArestaND(gr, 0, 4, 69); // Monte Alegre
    criaArestaND(gr, 0, 5, 138); // Ituiutaba

    // Araguari até
    //criaAresta(gr, 1, 0, 38); // Uberlandia
    criaArestaND(gr, 1, 2, 140); // Uberaba
    criaArestaND(gr, 1, 3, 215); // Patos de Minas
    criaArestaND(gr, 1, 4, 170); // Monte Alegre
    criaArestaND(gr, 1, 5, 170); // Ituiutaba

    // Uberaba até
    //criaAresta(gr, 2, 0, 105); // Uberlandia
    //criaAresta(gr, 2, 1, 140); // Araguari
    criaArestaND(gr, 2, 3, 315); // Patos de Minas
    criaArestaND(gr, 2, 4, 174); // Monte Alegre
    criaArestaND(gr, 2, 5, 237); // Ituiutaba

    // Patos de Minas até
    //criaAresta(gr, 3, 0, 216); // Uberlandia
    //criaAresta(gr, 3, 1, 215); // Araguari
    //criaAresta(gr, 3, 2, 315); // Uberaba
    criaArestaND(gr, 3, 4, 170); // Monte Alegre
    criaArestaND(gr, 3, 5, 300); // Ituiutaba

    // Monte Alegre até
    //criaAresta(gr, 4, 0, 69); // Uberlandia
    //criaAresta(gr, 4, 1, 170); // Araguari
    //criaAresta(gr, 4, 2, 174); // Uberaba
    //criaAresta(gr, 4, 3, 170); // Patos de Minas
    criaArestaND(gr, 4, 5, 68); // Ituiutaba

    // Ituiutaba até
    //criaAresta(gr, 5, 0, 138); // Uberlandia
    //criaAresta(gr, 5, 1, 170); // Araguari
    //criaAresta(gr, 5, 2, 237); // Uberaba
    //criaAresta(gr, 5, 3, 300); // Patos de Minas
    //criaAresta(gr, 5, 4, 68); // Monte Alegre

    imprime(gr);

    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n\n");
    buscaLargura(gr, 0);

    printf("\n-------------------------------------------\n");
    buscaProfun(gr);

    printf("\n-------------------------------------------\n");
    primMST(gr, 0);
    printf("\n-------------------------------------------\n");
    dijkstra(gr, 0, dist, pred);
    printf("Caminho mais curto de Uberlandia ate Ituiutaba:\n");
    imprimeCaminho(0, 5, pred, gr);
    printf("\nDistancia total: %d KM\n", dist[5]);
}