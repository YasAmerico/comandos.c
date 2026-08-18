#include<stdio.h>
#include<stdlib.h>
void pedir_e_calcular_fatorial() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    // Validação para números negativos
    if (n < 0) {
        printf("Erro: Nao existe fatorial de numero negativo.\n");
        return; // Encerra a função na hora
    }

    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    printf("O fatorial de %d e: %lld\n", n, resultado);
}

void pedir_e_contar() {
    int A, B;
    int menor, maior;
    int contador = 0;

    // Pede os números para o usuário
    printf("Digite o primeiro numero inteiro (A): ");
    scanf("%d", &A);
    
    printf("Digite o segundo numero inteiro (B): ");
    scanf("%d", &B);

    // Descobre quem é o menor e quem é o maior
    if (A < B) {
        menor = A;
        maior = B;
    } else {
        menor = B;
        maior = A;
    }

    // Conta os números que estão estritamente entre o menor e o maior
    for (int i = menor + 1; i < maior; i++) {
        contador++;
    }

    // Mostra o resultado na tela
    printf("Existem %d numeros inteiros entre %d e %d.\n", contador, A, B);
}

// Função que retorna 0 se for par e 1 se for ímpar
int verificar_par_impar(int n) {
    return n % 2;
}

//função que calcule quantos dias tem entre duas datas de um mesmo ano(dia,mês)
int dia_do_ano(int dia,int mes){
    int dias_meses[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int total = dia;
    for(int i=1;i<mes;i++){
        total+=dias_meses[i];
    }
    return total;
}

int calcular_diferenca_dias(int d1,int m1,int d2,int m2){
    int t1=dia_do_ano(d1,m1);
    int t2= dia_do_ano(d2,m2);
    return abs(t2-t1);
} 
//some dos numeros enter dois numeros

int soma_numeros(int limite) {
    int soma = 0;
    for (int i = 1; i <= limite; i++) {
        soma += i;
    }
    return soma;
}
//verifica se um numero inteiro é capucuo
int eh_capicua(int n) {
    if (n < 0) return 0;
    
    int original = n;
    int invertido = 0;
    
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }
    
    return original == invertido;
}

//fatorial duplo

long long fatorial_duplo(int n) {
    long long resultado = 1;

    // Multiplica de 2 em 2, descendo até 1 ou 2
    for (int i = n; i > 0; i -= 2) {
        resultado *= i;
    }

    return resultado;
}

//ano bissexto(calculo exato)
int eh_bissexto(int ano) {
    // Regra exata: divisível por 4 E (não divisível por 100 OU divisível por 400)
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1; // É bissexto (Verdadeiro)
    } else {
        return 0; // Não é bissexto (Falso)
    }
}
