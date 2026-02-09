#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "grafos.h"
#define true 1
#define false 0
#define BRANCO 0 //vamos definir aqui as cores apenas para fim didáticos
#define AMARELO 1
#define VERMELHO 2
#define INF INT_MAX

// estrutura da fila para o Busca em Largura
FILA* criarFila(int n) {
	FILA* f = (FILA*)malloc(sizeof(FILA));
	f->dados = (int*)malloc(n * sizeof(int));
	f->frente = 0;
	f->tras = 0;
	f->capacidade = n;
	return f;
}

void enfileirar(FILA* f, int v) {
	f->dados[f->tras++] = v;
}

int desenfileirar(FILA* f) {
	return f->dados[f->frente++];
}

int filaVazia(FILA* f) {
	return f->frente == f->tras;
}
/* ------------------------------------------------ */

/**função para criar um GRAFO**/
GRAFO *criaGrafo (int v) {
	int i;

	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO)); //aloca espa�o para estrtura grafo
	g->vertices = v; //atualizo o numero de vertice
	g->arestas = 0;  //atualizo o numero de vertice
	g->adj = (VERTICE *)malloc(v*sizeof(VERTICE)); //ler abaixo
	//Dentro da estrutura tem só o arranjo para o ponteiro de vertice, não o arranjo em si
	// ent�o aloco o arranjo com (v) o número de vertice desejado
	for (i=0; i<v; i++){
		g->adj[i].cab=NULL; //coloco NULL em todas arestas
	}
	return(g);
}

void inicializaNomes(GRAFO *gr, char nomes[][50]) {
	for (int i = 0; i < gr->vertices; i++) {
		strcpy(gr->adj[i].nome, nomes[i]);
		gr->adj[i].cab = NULL; // Garante que a lista comece vazia
	}
}

/**função auxiliar para adicionar arestas no GRAFO**/
ADJACENCIA *criaAdj(int v, int peso){
	ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA)); //aloca espa�o para um n�
	temp->vertice = v; //vertice alvo da adjacencia
	temp->peso = peso; //peso da aresta
	temp->prox = NULL;
	return(temp); //retorno endere�o da adjacencia
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { //vai de vi a vf
	if(!gr) return (false);  //valida��es se o grafo existe
	if((vf<0)||(vf >= gr->vertices))return(false); //valida��es se os valores n�o s�o neg
	if((vi<0)||(vi >= gr->vertices))return(false); //ou maiores que o numero de v�rtice do grafo

	ADJACENCIA *novo = criaAdj(vf, p); //crio adjacencia com o v�rtice final e o peso
	//coloco a adjacencia na lista do v�rtice inicial
	novo->prox = gr->adj[vi].cab; //o campo prox da adjacencia vai receber a cabe�a da lista
	gr->adj[vi].cab=novo; // e a cabe�a da lista passa a ser o novo elemento
	gr->arestas++; // atualizo o numero de aresta no grafo
	return (true);
}

bool criaArestaND(GRAFO *gr, int vi, int vf, TIPOPESO p) {
	criaAresta(gr, vi, vf, p);
	criaAresta(gr, vf, vi, p);
}

void imprime(GRAFO *gr){
	//validações se o grafo existe
	printf("Vertices: %d. Arestas: %d. \n",gr->vertices,gr->arestas); //imprime numero de v�rtice e arestas
	int i;

	for(i=0; i<gr->vertices; i++){
		printf("%s: ",gr->adj[i].nome); //Imprimo em qual aresta estou
		ADJACENCIA *ad = gr->adj[i].cab; //chamo a cabe�a da lista de adjacencia desta aresta
			while(ad){ //enquanto as adjacencias n�o forem nula
				printf("%s(%dKM) -> ",gr->adj[ad->vertice].nome,ad->peso); //imprimo a adjacencia e seu peso
				ad=ad->prox; //passo para proxima adjacencia
			}
		printf("\n");
	}
}

void buscaLargura(GRAFO *gr, int vi) {
	if (!gr) return;
	// 1. Crie um array para marcar quem já foi visitado (0 = não, 1 = sim)
	int *visitado = (int*)calloc(gr->vertices, sizeof(int));
	if (visitado == NULL) {
		printf("Erro: Falha ao alocar memória para o array de visitados.\n");
		return;
	}

	// 2. Crie a fila e insira o vértice inicial
	FILA *q = criarFila(gr->vertices);

	visitado[vi] = true;
	enfileirar(q, vi);

	printf("Ordem da Busca em largura partindo de %s:\n", gr->adj[vi].nome);

	while (!filaVazia(q)) {
		// 3. Retire o vértice da vez
		int w = desenfileirar(q);
		printf("[%s] ", gr->adj[w].nome);

		// 4. Explore os vizinhos (adjacentes) de w
		ADJACENCIA *ad = gr->adj[w].cab;
		while(ad) {
			int u = ad->vertice;
			if (!visitado[u]) {
				visitado[u] = true;
				//printf("[%s] ", gr->adj[u].nome);
				enfileirar(q, u);
			}
			ad = ad->prox;
		}
		printf("-> ");
	}
	free(visitado);
	free(q->dados);
	free(q);
}

void buscaProfun(GRAFO *gr){
	int cor[gr->vertices];//crio um vetor com arranjo de cores (o valor tem que bater com o do grafo)

	int u;
	for(u=0;u<gr->vertices;u++){ //inicialmente todos vértices são brancos
		cor[u] = BRANCO;
	}

	printf("Ordem da Busca em profundidade partindo de %s:\n", gr->adj[u].nome);

	for(u=0;u<gr->vertices;u++){
		if (cor[u] == BRANCO) // se for branco visita todos em profundida
			visitaP(gr,u,cor); // repare que é recursivo, visita até o final depois volta
	}
}

void visitaP(GRAFO *gr, int u, int *cor){
	cor[u] = AMARELO; //visitar um nó marca como amarelo
	printf("[%s] -> ", gr->adj[u].nome);

	ADJACENCIA *v = gr->adj[u].cab; //visito adjacencia
	while (v){ //então visitamos sua adjacencia, aresta u e v recursivamente
		if(cor[v->vertice]==BRANCO) //se a cor for branco eu visito
			visitaP(gr,v->vertice,cor); //veja que visito chamando a função de novo, ou seja recursivo
		v = v->prox;
	}
	cor[u] = VERMELHO;
}
/* ----------------------------------------------------------- */

// Prim quer conectar todos os pontos com o menor custo total
void primMST(GRAFO *g, int start) {
    if (!g || start < 0 || start >= g->vertices) return;

    int V = g->vertices;
    int key[V];      // Menor peso para conectar o vértice v à MST
    int parent[V];   // Armazena a estrutura da árvore (pai de v)
    int inMST[V];    // 1 se o vértice v já está na árvore, 0 caso contrário

    // 1) Inicialização
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = 0;
    }

    // O ponto de partida tem peso 0 para ser o primeiro escolhido
    key[start] = 0;
    int custoTotal = 0;

    // 2) Repita V vezes (para incluir todos os vértices)
    for (int count = 0; count < V; count++) {

        // --- BUSCA LINEAR O(V) ---
        // Escolhe o vértice 'u' fora da MST com a menor 'key'
        int min = INF;
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Se u for -1, o grafo é desconexo (não há mais vértices alcançáveis)
        if (u == -1) break;

        // Marcar u como incluído na MST
        inMST[u] = 1;
        if (parent[u] != -1) {
            custoTotal += min;
        }

        // --- ATUALIZAÇÃO DOS VIZINHOS ---
        // Para cada adjacência de u, atualiza as chaves dos vizinhos 'w'
        ADJACENCIA *adj = g->adj[u].cab;
        while (adj) {
            int w = adj->vertice;
            int peso = adj->peso;

            // Se w não está na MST e o peso da aresta (u,w) é menor que a key atual de w
            if (!inMST[w] && peso < key[w]) {
                parent[w] = u;
                key[w] = peso;
            }
            adj = adj->prox;
        }
    }

    // 3) Impressão dos resultados
    printf("\n--- Arvore Geradora Minima (Prim) ---\n");
    for (int i = 0; i < V; i++) {
        if (parent[i] != -1) {
            printf("%s - %s (%d)\n", g->adj[parent[i]].nome, g->adj[i].nome, key[i]);
        }
    }
    printf("Custo Total da MST: %d\n", custoTotal);
}

// Dijkstra quer o caminho mais curto de um ponto específico até os outros.
void dijkstra(GRAFO *g, int s, int *dist, int *pred) {
	if (!g || s < 0 || s >= g->vertices) return;

	int V = g->vertices;
	int visited[V];

	// Inicialização
	for (int i = 0; i < V; i++) {
		dist[i] = INF;
		pred[i] = -1;
		visited[i] = 0;
	}

	dist[s] = 0;

	for (int count = 0; count < V; count++) {
		// 1) Escolha u não visitado com menor dist[u]
		int min = INF;
		int u = -1;

		for (int v = 0; v < V; v++) {
			if (!visited[v] && dist[v] <= min) {
				min = dist[v];
				u = v;
			}
		}

		if (u == -1 || dist[u] == INF) break;

		// 2) Marcar como visitado/fixado
		visited[u] = 1;

		// 3) Relaxamento das arestas
		ADJACENCIA *adj = g->adj[u].cab;
		while (adj) {
			int v = adj->vertice;
			int peso = adj->peso;

			if (!visited[v] && dist[u] + peso < dist[v]) {
				dist[v] = dist[u] + peso;
				pred[v] = u;
			}
			adj = adj->prox;
		}
	}
}

// usa a pilha de recursão para inverter a ordem (já que o pred guarda o caminho de trás para frente);
void imprimeCaminho(int s, int t, int *pred, GRAFO *g) {
	if (s == t) {
		printf("%s", g->adj[s].nome);
		return;
	}

	if (pred[t] == -1) {
		printf("Nao existe caminho de %s ate %s", g->adj[s].nome, g->adj[t].nome);
	} else {
		imprimeCaminho(s, pred[t], pred, g);
		printf(" -> %s", g->adj[t].nome);
	}
}