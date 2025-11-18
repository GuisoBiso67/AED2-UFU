#ifndef TABELAHASH_H
#define TABELAHASH_H

// hashing universal = usar uma familia de funçoes de hashing para evitar colisoes;

struct aluno {
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);

int valorString(char *str);

int insereHash_SemColisao(Hash* ha, struct aluno al);
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al);

// endereçamento aberto serve para resolver o problema das colisões;
int insereHash_EnderAberto(Hash* ha, struct aluno al);
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al);

int chaveDivisao(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);

int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHash(int H1, int chave, int i, int TABLE_SIZE);

#endif //TABELAHASH_H
