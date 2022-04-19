#include <stdio.h>
#include <math.h>
#include "raiz.h"
#define GRAVIDADE 9.8
#define ARRASTO 15
#define TEMPO 9
#define VELOCIDADE 35

// Funções de teste
double cubica(double x)
{
    return (x * x * x) + x - 7.0;
}

double quarta(double x)
{
    return (x * x * x * x) + x + 1.0;
}

double linear(double x)
{
    return (2.0 * x) - 4.0;
}

// Função de velocidade em queda livre
double queda_livre(double m)
{
    return VELOCIDADE - (((GRAVIDADE * m) / ARRASTO) * (1 - exp(-(ARRASTO * TEMPO / m))));
}

int main()
{
    double* raiz = NULL;
    double r;
    raiz = &r;

    double* raiz_s = NULL;
    double r_s;
    raiz_s = &r_s;

    double* raiz_ss = NULL;
    double r_ss;
    raiz_ss = &r_ss;

    double a = 1.0;
    double b = 3.0;
    double x0 = 1.5;
    double x1 = 2.5; 

    int i = bissecao(a, b, cubica, raiz);
    int j = secante(a, b, cubica, raiz_s);
    printf("2.\n");
    printf("\ta) Cubica\n\n");
    printf("\t\tIntervalo [%g, %g]\n\n", a, b);
    printf("\t\t===============================================\n");
    printf("\t\t|| %-22s || %-20s ||\n", "Método da Bisseção", "Iterações");
    printf("\t\t|| %-19.16g || %-18d ||\n", *raiz, i);
    printf("\t\t===============================================\n");
    printf("\n");
    printf("\t\t==================================================\n");
    printf("\t\t|| %-23s || %-20s ||\n", "Método da Secante", "Iterações");
    printf("\t\t|| %-22.16g || %-18d ||\n", *raiz_s, j);
    printf("\t\t==================================================\n");
    printf("\n");
    printf("\n");

    i = bissecao(x0, x1, cubica, raiz);
    j = secante(x0, x1, cubica, raiz_s);
    printf("\t\tIntervalo [%g, %g]\n\n", x0, x1);
    printf("\t\t===============================================\n");
    printf("\t\t|| %-22s || %-20s ||\n", "Método da Bisseção", "Iterações");
    printf("\t\t|| %-19.16g || %-18d ||\n", *raiz, i);
    printf("\t\t===============================================\n");
    printf("\n");
    printf("\t\t==================================================\n");
    printf("\t\t|| %-23s || %-20s ||\n", "Método da Secante", "Iterações");
    printf("\t\t|| %-22.16g || %-18d ||\n", *raiz_s, j);
    printf("\t\t==================================================\n");
    printf("\n\n");

    // ------------------------
    printf("\tb) Quarta\n\n");
    i = bissecao(-1.0, 1.0, quarta, raiz);
    j = secante(-1.0, 1.0, quarta, raiz_ss);
    printf("\t\tIntervalo [%g, %g]\n\n", -1.0, 1.0);
    printf("\t\t===============================================\n");
    printf("\t\t|| %-22s || %-20s ||\n", "Método da Bisseção", "Iterações");
    printf("\t\t|| %-19.16g || %-18d ||\n", *raiz, i);
    printf("\t\t===============================================\n");
    printf("\n");
    printf("\t\t==================================================\n");
    printf("\t\t|| %-23s || %-20s ||\n", "Método da Secante", "Iterações");
    printf("\t\t|| %-22.16g || %-18d ||\n", *raiz_ss, j);
    printf("\t\t==================================================\n");
    printf("\n\n");

    // ------------------------
    printf("\tc) Queda Livre\n\n");
    i = bissecao(50.0, 70.0, queda_livre, raiz);
    j = secante(50.0, 70.0, queda_livre, raiz_ss);
    printf("\t\tIntervalo [%g, %g]\n\n", 50.0, 70.0);
    printf("\t\t===============================================\n");
    printf("\t\t|| %-22s || %-20s ||\n", "Método da Bisseção", "Iterações");
    printf("\t\t|| %-19.16g || %-18d ||\n", *raiz, i);
    printf("\t\t===============================================\n");
    printf("\n");
    printf("\t\t==================================================\n");
    printf("\t\t|| %-23s || %-20s ||\n", "Método da Secante", "Iterações");
    printf("\t\t|| %-22.16g || %-18d ||\n", *raiz_ss, j);
    printf("\t\t==================================================\n");
    printf("\n\n");


    return 0;
}