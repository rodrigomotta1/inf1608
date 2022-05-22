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
    return (6 * x * x) - (2 * x * x * x);
}

int main(int argc, char const *argv[])
{
    double res;

    int iterations = IQI(4.0, 4.5, 5.0, f, &res);

    printf("result: %.16g\t iterations: %d\n", res, iterations);
    return 0;
}
