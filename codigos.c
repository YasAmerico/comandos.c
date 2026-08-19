#include"Arquivo.h"

int main(){
    pedir_e_calcular_fatorial();
    return 0;
}

int main(){
    pedir_e_contar();
    return 0;
}

int main(){
    int numero;
    int resultado;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Chama a função e guarda o resultado
    resultado = verificar_par_impar(numero);

    // Mostra o resultado na tela
    if (resultado == 0) {
        printf("O número %d é PAR (Retorno: %d)\n", numero, resultado);
    } else {
        printf("O número %d é ÍMPAR (Retorno: %d)\n", numero, resultado);
    }

    return 0;
}

int main(){
    int d1,m1,d2,m2;

    printf("digite a primeira data(dia mes):");
    scanf("%d %d",&d1,&m1);

    printf("digite a segunda data (dia mes):");
    scanf("%d %d",&d2,&m2);
    int resultado = calcular_diferenca_dias(d1,m1,d2,m2);
    printf("dias entre as data: %d\n",resultado);
    return 0;
}

int main() {
    int numero_usuario;
    int resultado;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero_usuario);

    // O programa chama a função usando o número digitado
    resultado = soma_numeros(numero_usuario);

    // Mostra o resultado na tela
    printf("A soma de 1 ate %d eh: %d\n", numero_usuario, resultado);

    return 0;
}

int main() {
    int n, original, invertido = 0, resto;

    printf("Digite um numero: ");
    scanf("%d", &n);

    original = n;

    while (n > 0) {
        resto = n % 10;
        invertido = invertido * 10 + resto;
        n /= 10;
    }

    if (original == invertido) {
        printf("O numero e capicua!\n");
    } else {
        printf("O numero nao e capicua.\n");
    }

    return 0;
}

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, digite um numero maior ou igual a zero.\n");
    } else {
        long long res = fatorial_duplo(numero);
        printf("O fatorial duplo (%d!!) e: %lld\n", numero, res);
    }

    return 0;
}

int main() {
    int ano;

    printf("Digite um ano: ");
    scanf("%d", &ano);

    if (eh_bissexto(ano)) {
        printf("O ano %d e bissexto!\n", ano);
    } else {
        printf("O ano %d nao e bissexto.\n", ano);
    }

    return 0;
}

//fibonacci
int main() {
    int termos;

    printf("Digite o numero de termos da sequencia: ");
    scanf("%d", &termos);

    if (termos <= 0) {
        printf("Por favor, insira um numero maior que zero.\n");
        return 1;
    }

    printf("Sequencia de Fibonacci: ");
    for (int i = 0; i < termos; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

//soma dos elementos de um vetor
int main() {
    int tamanho;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Por favor, insira um tamanho maior que zero.\n");
        return 1;
    }

    int vetor[tamanho];

    // Preenche o vetor com os dados do usuário
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Calcula a soma chamando a função recursiva
    int total = somar_vetor(vetor, tamanho);

    printf("\nA soma de todos os elementos do vetor e: %d\n", total);

    return 0;
}

//potencia
int main() {
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente (inteiro positivo): ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Por favor, insira um expoente maior ou igual a zero.\n");
        return 1;
    }

    long long resultado = potencia(base, expoente);
    printf("%d elevado a %d e: %lld\n", base, expoente, resultado);

    return 0;
}

//MDC
int main() {
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // Evita problemas caso o usuário digite números negativos
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    int resultado = mdc(num1, num2);
    printf("O MDC de %d e %d e: %d\n", num1, num2, resultado);

    return 0;
}

//Inverter strings
int main() {
    char texto[100]; // Array de tamanho 100 para guardar o texto de forma correta

    printf("Digite uma string para inverter: ");
    // Lê a string inteira, incluindo espaços
    fgets(texto, sizeof(texto), stdin);

    // Remove a quebra de linha (\n) que o fgets captura automaticamente
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n') {
            texto[i] = '\0';
            break;
        }
    }

    printf("String invertida: ");
    imprimir_invertido(texto);
    printf("\n");

    return 0;
}
