#ifndef GRAFOS_H
#define GRAFOS_H

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice; // vertice de destino
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    struct adjacencia *prox; // O pr�ximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice {
    char nome[50];
    ADJACENCIA *cab; //possui apenas a cabeça da lista de adjacencia
}VERTICE;

typedef struct grafo { //lembrando que cada grafo possui:
    int vertices; // numero de vertice total do grafo
    int arestas; // numero de arestas totais do grafo
    VERTICE *adj; // Arranjo de vertices da estrutura
}GRAFO;

typedef struct Fila {
    int *dados;
    int frente;
    int tras;
    int capacidade;
} FILA;

GRAFO *criaGrafo (int v);
void inicializaNomes(GRAFO *gr, char nomes[][50]);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);
bool criaArestaND(GRAFO *gr, int vi, int vf, TIPOPESO p);
void imprime(GRAFO *gr);

void buscaLargura(GRAFO *gr, int vi);
void buscaProfun(GRAFO *gr);
void visitaP(GRAFO *gr, int u, int *cor);

void primMST(GRAFO *g, int start);
void dijkstra(GRAFO *g, int s, int *dist, int *pred);
void imprimeCaminho(int s, int t, int *pred, GRAFO *g);

#endif //GRAFOS_H
