#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

double* vet_cria (int n)
{
    double* vetor = (double*) malloc(n * sizeof(double));

    if (vetor == NULL)
    {
        // Memoria nao alocada. Retornar erro.
        printf("Erro: memoria nao alocada\n");
        exit(1);
    }
    else
    {
        // printf("Vetor alocado com sucesso em %p\n", vetor);
        return vetor;
    }
}

void vet_libera (double* v)
{
    if (v != NULL)
    {
        free(v);
        // printf("Memoria liberada com sucesso de %p.\n", v);

    }
    else
    {
        printf("Ponteiro nulo. Nao pode ser liberado.\n");
    }
}

double vet_escalar (int n, double* v, double* w)
{
    double produto = 0.0;

    for (int i = 0; i < n; i++)
    {
        produto = produto + ((*(v + i)) * (*(w + i)));
    }

    // printf("Produto Escalar = %.16g\n", produto);
    return produto;
}

double vet_norma2 (int n, double* v)
{
    double somatorio = 0.0;

    for (int i = 0; i < n; i++)
    {
        somatorio = somatorio + ((*(v + i)) * (*(v + i)));
    }

    double norma2 = sqrt(somatorio);

    // printf("Norma2 = %.16g\n", norma2);
    return norma2;
}

void vet_mults (int n, double* v, double s, double *w)
{
    for (int i = 0; i < n; i++)
    {
        *(w + i) = (*(v + i)) * s;
    }

    // printf("Multiplicacao por escalar realizada\n");

}

void vet_imprime (int n, double* v)
{   
    printf("\n");
    // printf("_  _");

    for (int i = 0; i < n; i++)
    {
        printf("%.16g\n", *(v + i));
    }

    // printf("_  _");
    printf("\n");

}