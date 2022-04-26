#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"
#include "matriz.h"


double** mat_cria (int m, int n)
{
    double** A = (double**) malloc(m * sizeof(double*));
    if (A == NULL)
    {
        // Memoria nao alocada. Retornar erro.
        printf("Erro: memoria nao alocada (A)\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            A[i] = (double*) malloc(n * sizeof(double));
            if (A[i] == NULL)
            {
                // Memoria nao alocada. Retornar erro.
                printf("Erro: memoria nao alocada (B%d)\n", i);
                exit(1);
            }
        }
    }

    // printf("Memoria alocada com sucesso.\n");
    return A;
}


void mat_libera (int m, double** A)
{
    if (A == NULL)
    {
        printf("Ponteiro nulo. Nao pode ser liberado\n");
    }
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);
    // printf("Memoria liberada com sucesso\n");

}


void mat_transposta(int m, int n, double** A, double** T)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}


void mat_multv(int m, int n, double** A, double* v, double* w)
{
    for (int i = 0; i < m; i++)
    {
        w[i] = 0;
        for (int j = 0; j < n; j++)
        {
            // printf("\t[%d][%d]\t%.16g\t%.16g\n", i, j, A[i][j], v[j]);

            w[i] += A[i][j] * v[j];
        }
    }
}


void mat_multm(int m, int n, int q, double** A, double** B, double** C)
{
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < q; k++)
        {
            
            C[i][k] = 0;

            for (int j = 0; j < n; j++)
            {
                C[i][k] += (A[i][j] * B[j][k]);
            }
        }
    }
}


void mat_imprime(int m, int n, double** A)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.16g\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


void mat_troca_linhas(int m, int n, double** A, int i, int l)
{
    // Tmp vira linha i
    double* tmp = A[i];

    // Linha i vira linha l
    A[i] = A[l];

    // Linha l vira tmp
    A[l] = tmp;
}