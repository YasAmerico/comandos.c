#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipação das funções
char* criar_copia_string(const char* str_original);
void inverter_string_recursiva(char* str, int inicio, int fim);
void exibir_reversa(const char* nome);

int main() {
    // 1. Strings: Declaração de um buffer estático para a entrada do usuário
    char buffer[100];

    printf("Digite um nome completo: ");
    // Lê a string do teclado incluindo os espaços
    fgets(buffer, sizeof(buffer), stdin);
    
    // Remove a quebra de linha (\n) que o fgets captura ao pressionar Enter
    buffer[strcspn(buffer, "\n")] = '\0';

    // 2. Alocação Dinâmica e Função: Duplica a string alocando a memória exata necessária
    char* nome_armazenado = criar_copia_string(buffer);

    if (nome_armazenado == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("\n--- Resultados ---\n");
    printf("Nome original armazenado: %s\n", nome_armazenado);

    // 3. Função e Recursividade: Modifica a string invertendo seus caracteres
    int tamanho = strlen(nome_armazenado);
    inverter_string_recursiva(nome_armazenado, 0, tamanho - 1);

    printf("Nome invertido na memória: %s\n", nome_armazenado);

    // 4. Liberação de memória: Regra de ouro da alocação dinâmica
    free(nome_armazenado);
    nome_armazenado = NULL;

    return 0;
}

// FUNÇÃO + ALOCAÇÃO DINÂMICA + STRINGS
// Aloca dinamicamente o espaço exato para a string informada e copia seu conteúdo
char* criar_copia_string(const char* str_original) {
    // strlen calcula o tamanho sem contar o caractere nulo '\0', por isso somamos 1
    int tamanho = strlen(str_original) + 1; 
    
    // Alocação dinâmica de memória usando malloc
    char* nova_str = (char*) malloc(tamanho * sizeof(char));
    
    if (nova_str != NULL) {
        strcpy(nova_str, str_original); // Copia o conteúdo para a nova memória
    }
    
    return nova_str; // Retorna o ponteiro da memória alocada
}

// RECURSIVIDADE + STRINGS
// Inverte os caracteres de uma string diretamente na memória usando recursão
void inverter_string_recursiva(char* str, int inicio, int fim) {
    // Caso base: se os índices se cruzarem ou forem iguais, a inversão acabou
    if (inicio >= fim) {
        return;
    }

    // Passo recursivo: Troca o caractere do início com o do fim
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    // Subproblema: Chama a si mesma aproximando os índices do centro
    inverter_string_recursiva(str, inicio + 1, fim - 1);
}
