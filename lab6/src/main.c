#include <stdio.h>
#include <math.h>
#include "integral.h"
#define ln(x) log(x)


// Funções para avaliação nos testes
double f(double x)
{
    return cos(x) - 2.0*sin(x);
}


double df(double x)
{
    return -sin(x) - 2.0*cos(x);
}


double fi_a(double x)
{
    return x / (sqrt((x * x) + 9));
}


double fi_b(double x)
{
    return (x * x) * ln(x);
}


double fi_c(double x)
{
    return (x * x) * sin(x);
}


// Funções de teste
void test_a()
{
    double h = 2.0;
    int n = 5;
    double pt = 0.0;
    double analitica = df(pt);

    printf("\n\t[ teste de derivadas variando ordem n ]\t (h = %g\t, x = %g)\n", h, pt);
    printf("------------------------------------------------------\n");
    printf("%-6s | %-21s | %-20s\n", "ordem", "aval. analítica", "aval. númerica");
    printf("%-6s | %-20s | %-20s\n", "------", "------", "------");
    for (int i = 2; i < 7; i++)
    {
        printf("%-6d | %-20.16g | %20.16g\n", i*2, analitica, derivada(i, f, 0, h));
    }
    printf("------------------------------------------------------\n");

    printf("\n\n\t[ teste de derivadas variando passo h ]\t (n = %d\t, x = %g)\n", n, pt);
    printf("------------------------------------------------------\n");
    printf("%-6s | %-21s | %-20s\n", "passo", "aval. analítica", "aval. númerica");
    printf("%-6s | %-20s | %-20s\n", "------", "------", "------");
    for (int j = 2; j < 7; j++)
    {
        printf("%-6g | %-20.16g | %20.16g\n", (double) j * 3, analitica, derivada(n, f, 0, (double) j + 3));
    }
    printf("------------------------------------------------------\n");

    
}


void test_b()
{

    printf("\n\t[ teste de integral com n = 16 ]\n");
    printf("------------------------------------------------------\n");
    printf("%-10s | %-20s | %-20s\n", "integral", "simpson", "valor exato");
    printf("%-10s | %-20s | %-20s\n", "------", "------", "------");

    printf("%-10c | %-20.16g | %20.16g\n", 'a', simpson(fi_a, 0.0, 4.0, 16), 2.0);
    printf("%-10c | %-20.16g | %20.16g\n", 'b', simpson(fi_b, 1.0, 3.0, 16), 6.9986217091241);
    printf("%-10c | %-20.16g | %20.16g\n", 'c', simpson(fi_c, 0.0, M_PI, 16), 5.8696044010894);

    printf("------------------------------------------------------\n");

    printf("\n\t[ teste de integral com n = 32 ]\n");
    printf("------------------------------------------------------\n");
    printf("%-10s | %-20s | %-20s\n", "integral", "simpson", "valor exato");
    printf("%-10s | %-20s | %-20s\n", "------", "------", "------");

    printf("%-10c | %-20.16g | %20.16g\n", 'a', simpson(fi_a, 0.0, 4.0, 32), 2.0);
    printf("%-10c | %-20.16g | %20.16g\n", 'b', simpson(fi_b, 1.0, 3.0, 32), 6.9986217091241);
    printf("%-10c | %-20.16g | %20.16g\n", 'c', simpson(fi_c, 0.0, M_PI, 32), 5.8696044010894);

    printf("------------------------------------------------------\n");
}


// Execução dos testes
int main(int argc, char const *argv[])
{
    // test_a();
    test_b();
    return 0;
}
