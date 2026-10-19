//1
#include <stdio.h>
#include <stdbool.h>

// Função manual que verifica se o vetor está em ordem crescente
bool estaOrdenadaCrescente(int vetor[], int tamanho) {
    // Vetores vazios ou com apenas 1 número sempre estão ordenados
    if (tamanho <= 1) {
        return true;
    }

    // Percorre comparando o elemento atual com o próximo
    for (int i = 0; i < tamanho - 1; i++) {
        // Se o número atual for maior que o próximo, quebrou a ordem crescente
        if (vetor[i] > vetor[i + 1]) {
            return false; // Para imediatamente
        }
    }

    return true; // Se passou por tudo, está ordenada
}

int main() {
    int tamanho;

    // Solicita o tamanho da lista ao usuário
    printf("Digite a quantidade de elementos da lista: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    // Cria o vetor com o tamanho especificado pelo usuário
    int minhaLista[tamanho];

    // Preenche a lista com os valores digitados
    printf("Digite os %d números da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &minhaLista[i]);
    }

    // Exibe a lista inserida apenas para conferência
    printf("\nSua lista: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", minhaLista[i]);
    }
    printf("]\n");

    // Executa a validação manual
    if (estaOrdenadaCrescente(minhaLista, tamanho)) {
        printf("Resultado: A lista ESTÁ ordenada de forma crescente!\n");
    } else {
        printf("Resultado: A lista NÃO está ordenada de forma crescente.\n");
    }

    return 0;
}

//2
  #include <stdio.h>

// Função que faz a ordenação manual por inserção
void ordenacaoPorInsercao(int vetor[], int tamanho) {
    // Começa a partir do segundo elemento (índice 1)
    for (int i = 1; i < tamanho; i++) {
        int atual = vetor[i]; // Guarda o elemento que queremos posicionar
        int j = i - 1;

        // Move os elementos que são maiores que o 'atual' uma posição para a direita
        while (j >= 0 && vetor[j] > atual) {
            vetor[j + 1] = vetor[j]; // Faz o deslocamento/empurrão
            j--; // Passa para o elemento anterior à esquerda
        }

        // Coloca o elemento 'atual' na vaga que abriu
        vetor[j + 1] = atual;
    }
}

// Função simples para exibir os elementos do vetor
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho;

    // Solicita o tamanho da lista ao usuário
    printf("Digite a quantidade de elementos da lista: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    // Cria o vetor dinamicamente com o tamanho especificado (VLA em C99)
    int minhaLista[tamanho];

    // Preenche a lista com os valores que você digitar
    printf("Digite os %d números da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &minhaLista[i]);
    }

    // Mostra a lista antes de rodar o algoritmo
    printf("\nLista original: ");
    imprimirVetor(minhaLista, tamanho);

    // Executa a ordenação manual por inserção
    ordenacaoPorInsercao(minhaLista, tamanho);

    // Mostra o resultado final ordenado
    printf("Lista ordenada (Crescente): ");
    imprimirVetor(minhaLista, tamanho);

    return 0;
}
//3
#include <stdio.h>

// Função que faz a ordenação manual por seleção
void ordenacaoPorSelecao(int vetor[], int tamanho) {
    // Percorre o vetor até o penúltimo elemento
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i; // Assume inicialmente que o elemento atual é o menor

        // Varre o restante do vetor (à direita de i) procurando alguém ainda menor
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j; // Atualiza o índice do menor elemento encontrado
            }
        }

        // Se encontrou um elemento menor do que o atual, faz a troca de lugar
        if (indiceMenor != i) {
            int temporario = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temporario;
        }
    }
}

// Função auxiliar para exibir a lista na tela
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho;

    // Solicita o tamanho da lista ao usuário
    printf("Digite a quantidade de elementos da lista: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    // Cria o vetor com o tamanho especificado pelo usuário
    int minhaLista[tamanho];

    // Preenche a lista com os valores digitados no teclado
    printf("Digite os %d números da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &minhaLista[i]);
    }

    // Mostra a lista antes de rodar o algoritmo
    printf("\nLista original: ");
    imprimirVetor(minhaLista, tamanho);

    // Executa a ordenação por seleção manual
    ordenacaoPorSelecao(minhaLista, tamanho);

    // Mostra o resultado final ordenado
    printf("Lista ordenada (Crescente): ");
    imprimirVetor(minhaLista, tamanho);

    return 0;
}

//4
#include <stdio.h>
#include <stdbool.h>

// Função que faz a ordenação manual pelo método da bolha
void ordenacaoBolha(int vetor[], int tamanho) {
    bool trocou;
    
    // O laço externo controla quantas passagens faremos pelo vetor
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false; // Reinicia a flag a cada nova rodada

        // O laço interno compara os elementos vizinhos
        // (tamanho - i - 1) evita retestar os números que já "subiram" para o fim do vetor
        for (int j = 0; j < tamanho - i - 1; j++) {
            
            // Se o elemento da esquerda for maior que o da direita, eles trocam de lugar
            if (vetor[j] > vetor[j + 1]) {
                int temporario = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temporario;
                
                trocou = true; // Sinaliza que houve uma troca nesta rodada
            }
        }

        // Otimização: Se nenhuma troca aconteceu na rodada inteira, o vetor já está ordenado!
        if (!trocou) {
            break;
        }
    }
}

// Função auxiliar para exibir a lista na tela
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho;

    // Solicita o tamanho da lista ao usuário
    printf("Digite a quantidade de elementos da lista: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    // Cria o vetor com o tamanho especificado pelo usuário
    int minhaLista[tamanho];

    // Preenche a lista com os valores que você digitar no teclado
    printf("Digite os %d números da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &minhaLista[i]);
    }

    // Mostra a lista antes de rodar o algoritmo
    printf("\nLista original: ");
    imprimirVetor(minhaLista, tamanho);

    // Executa a ordenação por bolha manual
    ordenacaoBolha(minhaLista, tamanho);

    // Mostra o resultado final ordenado
    printf("Lista ordenada (Crescente): ");
    imprimirVetor(minhaLista, tamanho);

    return 0;
}
