#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "vetor.h"


void pivotagem(double** A, double* b, int col, int n)
{
    // Indice da linha candidata a troca
    size_t p = col;

    // Temporaria para b, na troca final
    double tmp;

    for (size_t k = col + 1; k < n; k++)
    {
        if (fabs(A[k][col]) >= fabs(A[p][col]))
        {
            p = k;
        }

    }

    // Se linhar precisar ser trocada
    if (p != col)
    {
        mat_troca_linhas(n, n, A, col, p);

        // Troca linha de b
        tmp = b[p];
        b[p] = b[col];
        b[col] = tmp;
    }
    

}

void gauss (int n, double** A, double* b, double* x)
{
    // Fator para cada eliminação, pivot da coluna e somatório da retro-sub
    double fator, pivot, somatorio;

    // Eliminação
    // Para cada coluna j, parando na eliminação da penúltima (fim do triângulo inferior)
    for (size_t j = 0; j < n - 1; j++)
    {
        pivotagem(A, b, j, n);

        // Pivot da coluna, após pivotagem
        pivot = A[j][j];

        // Para cada linha da coluna, a partir do valor abaixo do pivot
        for (size_t i = j + 1; i < n; i++)
        {
            // Define o fator
            fator = A[i][j] / pivot;

            // Atualiza linha da matriz A utilizando fator
            for (size_t k = j; k < n; k++)
            {
                A[i][k] -= (A[j][k] * fator);
            }
            
            // printf("a%.16g\n", A[i][j]);

            // Atualiza vetor B utilizando fator
            b[i] -= (b[j] * fator);
        }
        // printf("%ld\n", j);
        // mat_imprime(n, n, A);
    }

    // Retro-substituição
    // 
    for (int i = n - 1; i >= 0; i--)
    {
        // Inicia somotorio
        somatorio = 0;

        for (int j = i + 1; j < n; j++)
        {
            somatorio += A[i][j] * x[j];
            // printf("\t[%d]\t%.16g\n", i, x[j]);
        }
        
        x[i] = (b[i] - somatorio) / A[i][i];
        
    }
    
}
