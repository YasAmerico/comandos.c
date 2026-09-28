//busca sequencial
#include <stdio.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Le um numero inteiro de forma segura, garantindo que a entrada seja valida.
 */
int ler_inteiro(const char *mensagem) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1) {
            return valor;
        }
        printf("[ERRO] Entrada invalida. Digite apenas numeros inteiros.\n");
        limpar_buffer();
    }
}

/**
 * Aloca memoria dinamicamente para o vetor de inteiros.
 */
int* alocar_lista(int tamanho) {
    int *ponteiro = (int *)malloc(tamanho * sizeof(int));
    if (ponteiro == NULL) {
        fprintf(stderr, "[ERRO CRITICO] Falha de segmentacao: Memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    return ponteiro;
}

/**
 * Preenche a lista exigindo que os dados inseridos mantenham a propriedade de ordenacao.
 */
void preencher_lista(int arr[], int tamanho) {
    printf("\n--- Preenchimento da Lista (Ordem Crescente) ---\n");
    for (int i = 0; i < tamanho; i++) {
        char msg[50];
        sprintf(msg, "Digite o elemento na posicao [%d]: ", i);
        
        while (1) {
            int valor = ler_inteiro(msg);
            
            // Validacao da invariante de ordenacao (lista[i] >= lista[i-1])
            if (i > 0 && valor < arr[i - 1]) {
                printf("[AVISO] A lista deve estar ordenada! O valor deve ser maior ou igual a %d.\n", arr[i - 1]);
            } else {
                arr[i] = valor;
                break;
            }
        }
    }
}

/**
 * Executa a Busca Sequencial Otimizada para Listas Ordenadas.
 * Identifica multiplas ocorrencias (duplicatas) e encerra precocemente se possivel.
 * Retorna a quantidade de correspondencias encontradas.
 */
int buscar_sequencial_ordenada(const int arr[], int tamanho, int alvo) {
    int contador_ocorrencias = 0;

    printf("\nResultados para a busca do elemento (%d):\n", alvo);
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == alvo) {
            printf("-> Elemento localizado no indice: %d (Posicao academica: %d)\n", i, i + 1);
            contador_ocorrencias++;
        } 
        // Criterio de parada precoce (Otimizacao O(n) no melhor/medio caso)
        else if (arr[i] > alvo) {
            printf("[INFO] Busca interrompida no indice %d: %d > %d. Elemento nao existe adiante.\n", i, arr[i], alvo);
            break;
        }
    }

    return contador_ocorrencias;
}

/**
 * Imprime os elementos contidos na estrutura de dados.
 */
void exibir_lista(const int arr[], int tamanho) {
    printf("\nEstado atual da lista: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    int tamanho = 0;
    
    printf("===================================================\n");
    printf(" SISTEMA DE BUSCA SEQUENCIAL EM LISTAS ORDENADAS \n");
    printf("===================================================\n\n");

    // Garante um tamanho de vetor estritamente positivo
    while (tamanho <= 0) {
        tamanho = ler_inteiro("Informe o tamanho maximo da sequencia (N > 0): ");
        if (tamanho <= 0) {
            printf("[AVISO] O tamanho da lista deve ser maior que zero.\n");
        }
    }

    // Inicializacao da estrutura
    int *lista = alocar_lista(tamanho);
    preencher_lista(lista, tamanho);

    int opcao = -1;
    do {
        printf("\n================ MENU DE OPERACOES ================\n");
        printf("1. Executar Busca Sequencial Ordenada\n");
        printf("2. Exibir Estrutura de Dados (Lista)\n");
        printf("0. Finalizar Programa\n");
        printf("---------------------------------------------------\n");
        opcao = ler_inteiro("Selecione a opcao desejada: ");

        switch (opcao) {
            case 1: {
                int alvo = ler_inteiro("\nInforme o valor inteiro que deseja pesquisar: ");
                int total = buscar_sequencial_ordenada(lista, tamanho, alvo);
                
                if (total == 0) {
                    printf("-> O elemento %d nao foi localizado na estrutura.\n", alvo);
                } else {
                    printf("-> Sucesso: Foram encontradas %d ocorrencia(s) do elemento %d.\n", total, alvo);
                }
                break;
            }
            case 2:
                exibir_lista(lista, tamanho);
                break;
                
            case 0:
                printf("\nDesalocando estruturas e encerrando a execucao...\n");
                break;
                
            default:
                printf("[AVISO] Opcao inexistente no menu. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    // Liberacao de recursos e encerramento seguro
    free(lista);
    lista = NULL; // Evita ponteiro solto (dangling pointer)
    
    return EXIT_SUCCESS;
}

//busca binaria
#include <stdio.h>
#include <stdlib.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int buscaBinariaOcorrencia(const int *arr, int tamanho, int alvo, int buscarPrimeiro) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int resultado = -1;

    while (esquerda <= direita) {
        // Prevenção contra overflow de inteiros em índices grandes
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == alvo) {
            resultado = meio; // Registra que encontrou, mas continua procurando o limite
            if (buscarPrimeiro) {
                direita = meio - 1; // Continua para a esquerda (procurando o primeiro)
            } else {
                esquerda = meio + 1; // Continua para a direita (procurando o último)
            }
        } else if (arr[meio] > alvo) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return resultado;
}

/**
 * Exibe todos os elementos do vetor formatados.
 */
void exibirVetor(const int *arr, int tamanho) {
    printf("\nVetor atual: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int tamanho = 0;
    int *vetor = NULL;

    printf("====================================================\n");
    printf("   SISTEMA DE BUSCA BINÁRIA INTERATIVA (ACADÊMICO)   \n");
    printf("====================================================\n");

    // Validação estrita do tamanho do vetor
    while (tamanho <= 0) {
        printf("\nDigite o tamanho do vetor (inteiro positivo): ");
        if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
            printf("[ERRO] Entrada inválida. Digite um número inteiro maior que zero.\n");
            limparBuffer();
            tamanho = 0;
        }
    }

    // Alocação dinâmica de memória
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "[ERRO CRÍTICO] Falha na alocação de memória.\n");
        return EXIT_FAILURE;
    }

    // Entrada e validação da ordenação em tempo de inserção
    printf("\n--- PREENCHIMENTO DO VETOR ---\n");
    printf("Insira os elementos em ordem CRESCENTE (valores duplicados são permitidos):\n");
    for (int i = 0; i < tamanho; i++) {
        while (1) {
            printf("Elemento [%d]: ", i);
            if (scanf("%d", &vetor[i]) != 1) {
                printf("[ERRO] Por favor, insira um número inteiro válido.\n");
                limparBuffer();
                continue;
            }

            // Garante que o vetor mantenha-se ordenado
            if (i > 0 && vetor[i] < vetor[i - 1]) {
                printf("[ERRO] Quebra de ordenação! O valor %d é menor que o anterior (%d).\n", vetor[i], vetor[i - 1]);
                continue;
            }
            break;
        }
    }

    int opcao;
    int alvo;

    // Menu interativo orientado a eventos
    do {
        printf("\n========================================\n");
        printf("             MENU PRINCIPAL             \n");
        printf("========================================\n");
        printf("1. Executar Busca Binária\n");
        printf("2. Visualizar Estrutura de Dados (Vetor)\n");
        printf("0. Finalizar Programa\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Opção inválida. Digite um número do menu.\n");
            limparBuffer();
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o valor que deseja buscar: ");
                if (scanf("%d", &alvo) != 1) {
                    printf("[ERRO] Entrada inválida.\n");
                    limparBuffer();
                    break;
                }

                // Executa as duas buscas binárias para delimitar o intervalo de duplicatas
                int primeiroIdx = buscaBinariaOcorrencia(vetor, tamanho, alvo, 1);

                if (primeiroIdx != -1) {
                    int ultimoIdx = buscaBinariaOcorrencia(vetor, tamanho, alvo, 0);
                    int totalOcorrencias = (ultimoIdx - primeiroIdx) + 1;

                    printf("\n[SUCESSO] Elemento '%d' localizado no sistema!\n", alvo);
                    if (totalOcorrencias == 1) {
                        printf("-> Encontrado na posição (índice): %d\n", primeiroIdx);
                    } else {
                        printf("-> Detectada duplicidade! Intervalo de índices: [%d] até [%d]\n", primeiroIdx, ultimoIdx);
                        printf("-> Total de vezes que o número aparece: %d\n", totalOcorrencias);
                    }
                } else {
                    printf("\n[AVISO] O elemento '%d' NÃO existe neste vetor.\n", alvo);
                }
                break;

            case 2:
                exibirVetor(vetor, tamanho);
                break;

            case 0:
                printf("\nDesalocando estruturas e encerrando o sistema... Até logo!\n");
                break;

            default:
                if (opcao != -1) {
                    printf("\n[ERRO] Opção inexistente. Tente novamente.\n");
                }
                break;
        }
    } while (opcao != 0);

    // Liberação de recursos antes do encerramento
    free(vetor);
    vetor = NULL;

    return EXIT_SUCCESS;
}
