#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo Grafo;

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_grafo(Grafo *gr);
int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso);
int removerAresta(Grafo *gr, int orig, int dest, int eh_digrafo);

#endif //GRAFO_H
