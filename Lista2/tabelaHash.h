#ifndef TABELAHASH_H
#define TABELAHASH_H

// intervalo de key = [1, 999]
struct number {
    int n;
    char key;
    struct number *next;
};
struct hash{
    int qtd, TABLE_SIZE;
    struct number **itens;
};
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash_SemColisao(Hash* ha, struct number num);
int buscaHash_SemColisao(Hash* ha, int key, struct number* num);
int insereHash_EnderAberto(Hash* ha, struct number num);
int buscaHash_EnderAberto(Hash* ha, int key, struct number* num);

// função que insere has com endereço aberto, mas contando as colisoes
int insereHash_Contando(Hash* ha, struct number num, int* colisoes);
int insereHash_EncadSep(Hash* ha, struct number num);

/*
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHashing(int pos, int chave, int i, int TABLE_SIZE);
*/

#endif //TABELAHASH_H
