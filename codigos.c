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
