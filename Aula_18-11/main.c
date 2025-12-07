#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main(){
    /*
    int tamanho = 1024;
    Hash *tabela = criaHash(tamanho);


    struct aluno al, a[4] = {{-100,"Andre",9.5,7.8,8.5},//64
                         {7894,"Ricardo",7.5,8.7,6.8},//726
                         {1124,"Bianca",9.7,6.7,8.4},//379
                         {2148,"Ana",5.7,6.1,7.4}};//173

    int i;
    for(i=0; i < 4; i++){
        insereHash_EnderAberto(tabela,a[i]);
    }

    printf("------------\n\n");

    buscaHash_EnderAberto(tabela, -100, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_EnderAberto(tabela, 1124, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_EnderAberto(tabela, 2148, &al);
    printf("%s, %d\n",al.nome,al.matricula);
    */

    //removeHash_EnderAberto(tabela, 1124);

    /*
    if (buscaHash_EnderAberto(tabela, 1124, &al)) {
        printf("Encontrado: %s\n", al.nome);
    } else {
        printf("Sucesso: Bianca foi removida e nao foi encontrada!\n");
    }
    */

    int tamanho = 2048;
    Hash *tabela = criaHash(tamanho);
    int totalColisoes=0;

    FILE *arq = fopen("alunos.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    struct aluno al;
    int qtdInseridos = 0;

    // Lê matrícula, nome, n1, n2, n3
    while(fscanf(arq, "%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3) != EOF){

        // Chama a função passando o endereço do contador
        if(insereHash_Contando(tabela, al, &totalColisoes)){
            qtdInseridos++;
        }
    }

    printf("------------ RESULTADOS ------------\n");
    printf("Total de Alunos Inseridos: %d\n", qtdInseridos);
    printf("Total de Colisoes (Sondagem Quadratica): %d\n", totalColisoes);

    // Métrica extra interessante: Média de colisões por inserção
    if (qtdInseridos > 0)
        printf("Media de colisoes: %.2f\n", (float)totalColisoes / (float)qtdInseridos);

    fclose(arq);
    liberaHash(tabela);

    return 0;
}
