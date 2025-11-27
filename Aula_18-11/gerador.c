#include <stdio.h>

int main() {
    FILE *f = fopen("alunos.txt", "w");
    if (!f) return 1;

    // Tamanho da sua tabela Hash (ajuste se mudar na main)
    int TABLE_SIZE = 2048;
    
    // Vamos gerar 2000 alunos que colidem propositalmente
    for (int i = 1; i <= 2000; i++) {
        // FÓRMULA DO CAOS:
        // Gera matrículas que são múltiplos exatos do tamanho da tabela + um offset (50).
        // Para o Hash (mat % 4096), TODOS darão o resultado 50.
        int matricula = (i * TABLE_SIZE) + 50; 
        
        fprintf(f, "%d Aluno_Teste_%d 10.0 10.0 10.0\n", matricula, i);
    }

    fclose(f);
    printf("Arquivo 'alunos.txt' gerado com sucesso com o padrao 'Pesadelo'!\n");
    return 0;
}