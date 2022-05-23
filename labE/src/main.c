#include <stdio.h>
#include "extra.h"


/**
 * Função dummy para avaliação do método IQI
 * 
 * @param x valor númerico de ponto flutuante
 * @returns avaliação da função
 */ 
double f(double x)
{
    return (x * x * x) + x - 7;
}


/**
 * Função dummy para verificação do critério de não-convergência do IQI
 * 
 * @param x valor númerico de ponto flutuante
 * @returns avaliação da função
 */ 
double fnc(double x)
{
   return (x * x * x * x) + x + 1;
}


/**
 * Procedimentos de teste para o IQI
 */
void test_IQI()
{
    double res;

    int iterations = IQI(1.0, 2.0, 3.0, f, &res);

    printf("[1.0  2.0  3.0] result: %.16g\t iterations: %d\n", res, iterations);

    iterations = IQI(1.5, 1.7, 2.0, f, &res);

    printf("[1.5  1.7  2.0] result: %.16g\t iterations: %d\n", res, iterations);

    iterations = IQI(1.6, 1.9, 3.2, f, &res);

    printf("[1.6  1.9  3.2] result: %.16g\t iterations: %d\n", res, iterations);

}


/**
 * Procedimentos de teste para o ajuste
 */
void test_ajuste()
{
    double t[] = {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0,
        6.0,
        7.0,
        8.0
    };

    double c[] = {
        8.0,
        12.3,
        15.5,
        16.8,
        17.1,
        15.8,
        15.2,
        14.0
    };

    // coeficientes
    double a, b;

    ajuste(10, t, c, &a, &b);

    printf("coeficientes calculados:\n");
    printf("a = %.16g\tb = %.16g\n", a, b);
}

int main(int argc, char const *argv[])
{
    test_IQI();
    test_ajuste();
    return 0;
}
