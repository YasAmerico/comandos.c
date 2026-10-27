//1°
#include <stdio.h>
#include <string.h>

// Definição do registro (struct) ALUNO
struct ALUNO {
    char nome[50];
    float notas[3];
};

int main() {
    struct ALUNO aluno; // Cria uma variável do tipo ALUNO
    float soma = 0.0, media;

    // 1. Leitura dos dados do Registro
    printf("Digite o nome do aluno: ");
    // fgets é mais seguro que scanf para ler nomes com espaços (ex: "João Silva")
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    
    // Remove a quebra de linha (\n) que o fgets armazena automaticamente no fim da string
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    // Leitura das 3 notas utilizando um laço simples
    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno.notas[i]);
        soma += aluno.notas[i]; // Vai somando as notas para o cálculo da média
    }

    // 2. Cálculo da Média
    media = soma / 3.0;

    // 3. Exibição do Registro e do Resultado
    printf("\n=============================\n");
    printf("      REGISTRO DO ALUNO      \n");
    printf("=============================\n");
    printf("Nome:  %s\n", aluno.nome);
    printf("Notas: %.1f | %.1f | %.1f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    printf("Média: %.2f\n", media);
    printf("=============================\n");

    return 0;
}

//2°
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do registro (struct) ALUNO
struct ALUNO {
    char nome[50];
    float notas[3];
};

// Função auxiliar para limpar o caractere de nova linha (\n) do fgets
void limparNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    FILE *arquivo;
    int quantidade;
    
    // -------------------------------------------------------------
    // PARTE 1: CRIAR O ARQUIVO E GRAVAR OS REGISTROS
    // -------------------------------------------------------------
    printf("Quantos alunos deseja cadastrar? ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }
    
    // Limpa o buffer do teclado após o scanf
    while (getchar() != '\n');

    // Abre o arquivo para escrita ("w"). Se o arquivo já existir, ele será sobrescrito.
    arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação!\n");
        return 1;
    }

    struct ALUNO alunoCadastro;

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastrando o aluno %d de %d ---\n", i + 1, quantidade);
        
        printf("Nome: ");
        fgets(alunoCadastro.nome, sizeof(alunoCadastro.nome), stdin);
        limparNovaLinha(alunoCadastro.nome);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunoCadastro.notas[j]);
        }
        
        // Limpa o buffer do teclado para a próxima leitura de string
        while (getchar() != '\n');

        // Grava os dados no arquivo de texto de forma organizada
        fprintf(arquivo, "%s\n%.2f %.2f %.2f\n", 
                alunoCadastro.nome, 
                alunoCadastro.notas[0], 
                alunoCadastro.notas[1], 
                alunoCadastro.notas[2]);
    }

    fclose(arquivo); // Fecha o arquivo após terminar a gravação
    printf("\nDados gravados com sucesso no arquivo 'alunos.txt'!\n");

    // -------------------------------------------------------------
    // PARTE 2: LER O ARQUIVO E EXIBIR OS RESULTADOS
    // -------------------------------------------------------------
    // Abre o arquivo apenas para leitura ("r")
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    struct ALUNO alunoLeitura;
    float somaMediasTurma = 0.0;
    int totalAlunosLidos = 0;

    printf("\n=============================================\n");
    printf("         LISTAGEM DE NOMES E MÉDIAS          \n");
    printf("=============================================\n");

    // O laço continuará lendo enquanto conseguir recuperar o nome e as 3 notas com sucesso
    while (fgets(alunoLeitura.nome, sizeof(alunoLeitura.nome), arquivo) != NULL) {
        limparNovaLinha(alunoLeitura.nome);

        // Lê a linha seguinte contendo as três notas correspondentes
        if (fscanf(arquivo, "%f %f %f\n", &alunoLeitura.notas[0], &alunoLeitura.notas[1], &alunoLeitura.notas[2]) == 3) {
            
            // Calcula a média do aluno atual
            float somaNotasAluno = alunoLeitura.notas[0] + alunoLeitura.notas[1] + alunoLeitura.notas[2];
            float mediaAluno = somaNotasAluno / 3.0;

            // Exibe a linha do aluno corrente
            printf("Nome: %-30s | Média: %.2f\n", alunoLeitura.nome, mediaAluno);

            // Acumula os valores para calcular a média geral do grupo
            somaMediasTurma += mediaAluno;
            totalAlunosLidos++;
        }
    }

    fclose(arquivo); // Fecha o arquivo de leitura

    // -------------------------------------------------------------
    // PARTE 3: EXIBIR A MÉDIA GERAL DA TURMA
    // -------------------------------------------------------------
    printf("=============================================\n");
    if (totalAlunosLidos > 0) {
        float mediaGeral = somaMediasTurma / totalAlunosLidos;
        printf(" Total de Alunos Listados: %d\n", totalAlunosLidos);
        printf(" MÉDIA GERAL DE TODOS OS ALUNOS: %.2f\n", mediaGeral);
    } else {
        printf(" Nenhum registro de aluno foi encontrado.\n");
    }
    printf("=============================================\n");

    return 0;
}
//3°
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARQUIVO_DADOS "alunos_notas.txt"

// Estrutura que representa o Registro do Aluno
struct ALUNO {
    char nome[50];
    float notas[3];
};

// Função auxiliar para limpar a quebra de linha (\n) deixada pelo fgets
void limparNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Opção 1: Gravar as notas no arquivo (Modo 'a' para adicionar sem apagar os anteriores)
void gravarNotas() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "a");
    if (arquivo == NULL) {
        printf("\n❌ Erro ao abrir o arquivo para gravação!\n");
        return;
    }

    struct ALUNO aluno;
    
    // Limpa o buffer do teclado antes de ler a string
    while (getchar() != '\n');

    printf("\n--- GRAVAR NOVAS NOTAS ---\n");
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    limparNovaLinha(aluno.nome);

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    // Grava no arquivo: nome em uma linha, as 3 notas na linha seguinte
    fprintf(arquivo, "%s\n%.2f %.2f %.2f\n", aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    
    fclose(arquivo);
    printf("\n✅ Aluno gravado com sucesso!\n");
}

// Opção 2: Listar apenas os alunos aprovados (Média >= 7.0)
void listarAprovados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "r");
    if (arquivo == NULL) {
        printf("\n⚠️ Nenhum registro encontrado. Grave notas primeiro!\n");
        return;
    }

    struct ALUNO aluno;
    bool encontrou = false;

    printf("\n=======================================================\n");
    printf("                  ALUNOS APROVADOS (Média >= 7.0)      \n");
    printf("=======================================================\n");

    while (fgets(aluno.nome, sizeof(aluno.nome), arquivo) != NULL) {
        limparNovaLinha(aluno.nome);
        if (fscanf(arquivo, "%f %f %f\n", &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]) == 3) {
            float media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3.0;

            if (media >= 7.0) {
                printf("Nome: %-25s | Notas: %.1f, %.1f, %.1f | Média: %.2f\n", 
                       aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2], media);
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno aprovado até o momento.\n");
    }
    printf("=======================================================\n");
    fclose(arquivo);
}

// Opção 3: Listar alunos em exame (Média entre 4.0 e 6.9) e mostrar a menor nota deles
void listarEmExame() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "r");
    if (arquivo == NULL) {
        printf("\n⚠️ Nenhum registro encontrado. Grave notas primeiro!\n");
        return;
    }

    struct ALUNO aluno;
    bool encontrou = false;

    printf("\n=======================================================\n");
    printf("                  ALUNOS EM EXAME (4.0 a 6.9)          \n");
    printf("=======================================================\n");

    while (fgets(aluno.nome, sizeof(aluno.nome), arquivo) != NULL) {
        limparNovaLinha(aluno.nome);
        if (fscanf(arquivo, "%f %f %f\n", &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]) == 3) {
            float media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3.0;

            // Critério de exame: média menor que 7.0 e maior ou igual a 4.0
            if (media >= 4.0 && media < 7.0) {
                // Descobre de forma manual qual foi a nota mínima (menor nota) do aluno
                float notaMinima = aluno.notas[0];
                if (aluno.notas[1] < notaMinima) notaMinima = aluno.notas[1];
                if (aluno.notas[2] < notaMinima) notaMinima = aluno.notas[2];

                printf("Nome: %-25s | Nota Mínima: %.1f | Média Atual: %.2f\n", 
                       aluno.nome, notaMinima, media);
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno em exame até o momento.\n");
    }
    printf("=======================================================\n");
    fclose(arquivo);
}

// Opção 4: Calcular estatísticas gerais de desempenho da turma
void exibirEstatisticas() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "r");
    if (arquivo == NULL) {
        printf("\n⚠️ Nenhum registro encontrado. Grave notas primeiro!\n");
        return;
    }

    struct ALUNO aluno;
    int totalAlunos = 0, qtdAprovados = 0, qtdExame = 0, qtdReprovados,DIRETO = 0;
    float somaAprovados = 0.0, somaExame = 0.0;

    while (fgets(aluno.nome, sizeof(aluno.nome), arquivo) != NULL) {
        limparNovaLinha(aluno.nome);
        if (fscanf(arquivo, "%f %f %f\n", &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]) == 3) {
            float media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3.0;
            totalAlunos++;

            if (media >= 7.0) {
                qtdAprovados++;
                somaAprovados += media;
            } else if (media >= 4.0) {
                qtdExame++;
                somaExame += media;
            }
        }
    }
    fclose(arquivo);

    printf("\n=======================================================\n");
    printf("                     ESTATÍSTICAS                      \n");
    printf("=======================================================\n");
    printf("Total de alunos registrados: %d\n\n", totalAlunos);

    if (totalAlunos > 0) {
        float percAprovados = ((float)qtdAprovados / totalAlunos) * 100.0;
        float percExame = ((float)qtdExame / totalAlunos) * 100.0;
        
        float mediaAprovados = (qtdAprovados > 0) ? (somaAprovados / qtdAprovados) : 0.0;
        float mediaExame = (qtdExame > 0) ? (somaExame / qtdExame) : 0.0;

        printf("APROVADOS:\n");
        printf("  - Quantidade: %d\n", qtdAprovados);
        printf("  - Percentual: %.1f%%\n", percAprovados);
        printf("  - Média das notas desse grupo: %.2f\n\n", mediaAprovados);

        printf("EM EXAME:\n");
        printf("  - Quantidade: %d\n", qtdExame);
        printf("  - Percentual: %.1f%%\n", percExame);
        printf("  - Média das notas desse grupo: %.2f\n", mediaExame);
    } else {
        printf("Sem dados suficientes para gerar estatísticas.\n");
    }
    printf("=======================================================\n");
}

int main() {
    int opcao;

    do {
        // Exibição do menu principal
        printf("\n--- MENU DE OPÇÕES ---\n");
        printf("1 - Grave as notas (nome e notas)\n");
        printf("2 - Liste os aprovados (nome, notas e média)\n");
        printf("3 - Liste os \"em exame\" (nome, nota mínima)\n");
        printf("4 - Estatística (quant. %% e média)\n");
        printf("5 - Encerra\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n❌ Entrada inválida! Digite apenas números.\n");
            while (getchar() != '\n'); // Limpa buffer
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1:
                gravarNotas();
                break;
            case 2:
                listarAprovados();
                break;
            case 3:
                listarEmExame();
                break;
            case 4:
                exibirEstatisticas();
                break;
            case 5:
                printf("\n👋 Programa encerrado. Até mais!\n");
                break;
            default:
                printf("\n❌ Opção inválida! Escolha um número de 1 a 5.\n");
        }
    } while (opcao != 5);

    return 0;
}
