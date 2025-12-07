#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define RESET   "\x1b[0m"
#define VERMELHO "\x1b[31m"
#define VERDE    "\x1b[32m"
#define AMARELO  "\x1b[33m"
#define AZUL     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CIANO    "\x1b[36m"

// ---------- TELA INICIAL ----------
void telaInicial() {
    system("cls");

    printf(AZUL "===============================================\n" RESET);
    printf("                 " VERDE "CALCULADORA" RESET "\n");
    printf(AZUL "===============================================\n\n" RESET);

    printf("Pressione ENTER para continuar...");
    getchar();

    system("cls");
}



// ---------- OPERACOES ----------
float soma() {
    int qtd;
    float n, total = 0;

    printf("Quantos numeros deseja somar? ");
    scanf("%d", &qtd);

    for (int i = 1; i <= qtd; i++) {
        printf("Numero %d: ", i);
        scanf("%f", &n);
        total += n;
    }
    return total;
}

float sub() {
    int qtd;
    float n, total;

    printf("Quantos numeros deseja subtrair? ");
    scanf("%d", &qtd);

    printf("Numero 1 (valor inicial): ");
    scanf("%f", &total);

    for (int i = 2; i <= qtd; i++) {
        printf("Numero %d: ", i);
        scanf("%f", &n);
        total -= n;
    }
    return total;
}

float mult() {
    int qtd;
    float n, total = 1;

    printf("Quantos numeros deseja multiplicar? ");
    scanf("%d", &qtd);

    for (int i = 1; i <= qtd; i++) {
        printf("Numero %d: ", i);
        scanf("%f", &n);
        total *= n;
    }
    return total;
}

float divi() {
    int qtd;
    float n, total;

    printf("Quantos numeros deseja dividir? ");
    scanf("%d", &qtd);

    printf("Numero 1 (valor inicial): ");
    scanf("%f", &total);

    for (int i = 2; i <= qtd; i++) {
        printf("Numero %d: ", i);
        scanf("%f", &n);

        if (n == 0) {
            printf(VERMELHO "Erro: divisao por zero ignorada!\n" RESET);
            continue;
        }

        total /= n;
    }
    return total;
}

float potencia() {
    float base, exp;
    printf("Base: ");
    scanf("%f", &base);
    printf("Expoente: ");
    scanf("%f", &exp);
    return pow(base, exp);
}

float raiz() {
    float n;
    printf("Digite o numero: ");
    scanf("%f", &n);

    if (n < 0) {
        printf(VERMELHO "Erro: raiz de numero negativo!\n" RESET);
        return 0;
    }
    return sqrt(n);
}

float porcent() {
    float v, p;
    printf("Valor: ");
    scanf("%f", &v);
    printf("Porcentagem: ");
    scanf("%f", &p);
    return (v * p) / 100;
}

// ---------- MENU ----------
void menu() {
    printf(AZUL "==================== MENU ====================\n" RESET);

    printf(VERDE   "1 - " RESET "Soma\n");
    printf(VERDE   "2 - " RESET "Subtracao\n");
    printf(VERDE   "3 - " RESET "Multiplicacao\n");
    printf(VERDE   "4 - " RESET "Divisao\n");

    printf(MAGENTA "5 - " RESET "Potencia\n");
    printf(MAGENTA "6 - " RESET "Raiz quadrada\n");
    printf(MAGENTA "7 - " RESET "Porcentagem\n");

    printf(VERMELHO"0 - " RESET "Sair\n");

    printf(AZUL "===============================================\n\n" RESET);
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    int op;
    float resultado;
    char continuar = 's';

    telaInicial();

    while (continuar == 's' || continuar == 'S') {

        menu();
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {

            case 1:
                resultado = soma();
                break;

            case 2:
                resultado = sub();
                break;

            case 3:
                resultado = mult();
                break;

            case 4:
                resultado = divi();
                break;

            case 5:
                resultado = potencia();
                break;

            case 6:
                resultado = raiz();
                break;

            case 7:
                resultado = porcent();
                break;

            case 0:
                printf(AMARELO "Saindo...\n" RESET);
                return 0;

            default:
                printf(VERMELHO "Opcao invalida!\n" RESET);
                continue;
        }

        printf(VERDE "\nRESULTADO = %.2f\n\n" RESET, resultado);

        printf(AMARELO "Deseja continuar? (s/n): " RESET);
        scanf(" %c", &continuar);

        system("cls");
    }

    printf(AMARELO "Programa encerrado.\n" RESET);
    return 0;
}