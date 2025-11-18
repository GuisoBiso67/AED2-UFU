#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));
        if (ha->itens == NULL) { // se der errado
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (int i = 0; i < ha->TABLE_SIZE; i++) {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash* ha) {
    if (ha != NULL) {
        for (int i = 0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL) {
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int TABLE_SIZE) {
    // "0x7FFFFFFF" elimina bit de sina do valor chave;
    // & = "E bit-a-bit";
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; // constante: 0 < A < 1
    float val = chave * A;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

int chaveDobra(int chave, int TABLE_SIZE) {
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2); // ou exclusivo
}

// trata string como chave; converte string em inteiro;
int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for (i = 0; i < tam; i++) {
        valor = 31 * valor + (int)str[i];
    }
    return valor;
}

int insereHash_SemColisao(Hash* ha, struct aluno al) {
    // tabela nao existe ou esta cheia;
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0;
    int chave = al.matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if (novo == NULL) return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al) {
    if (ha == NULL) return 0;
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if (ha->itens[pos] == NULL) return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

// problema do agrupamento primario (longa sequencia de espaços ocupados), o que deixa a tabela ineficiente;
int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos+1) & 0x7FFFFFFF) % TABLE_SIZE;
}

// resolve o problema de agrupamento primario, mas gera o secundario;
int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

// tenta espalhar os elementos utilizando duas funções de hash;
int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE-1) + 1;
    return ((H1+H2*i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto(Hash* ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0;
    int chave = al.matricula;
    int i, newPos;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for (i=0;i<ha->TABLE_SIZE;i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL) {
            struct aluno* novo = (struct aluno*) malloc(sizeof(struct aluno));
            if (novo == NULL) return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al) {
    if (ha == NULL) return 0;
    int i, pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for (i=0;i<ha->TABLE_SIZE;i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL) return 0;
        if (ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}
