#include <stdio.h>
#include <stdlib.h>
#include "massamola.h"


int main(int argc, char const *argv[])
{
    int amostras = 1000;

    double *x = malloc(sizeof(double) * amostras);
    double *y = malloc(sizeof(double) * amostras);

    simula(200.0, 0.0, 100.0, amostras, x, y);

    for (size_t i = 0; i < amostras; i++)
        printf("%.16g\t%.16g\n", x[i], y[i]);
    
    return 0;
}
