#include "vetor.h"
#include "matriz.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int gauss_seidel (int n, double** A, double* b, double* x, double tol)
{
    int iteracoes = 0;
    double* residuo = vet_cria(n);
    double* A_x = vet_cria(n);

    double sum;
    double n2_residuo;

    do
    {
        for (size_t linha = 0; linha < n; linha++)
        {
            
            sum = 0;
            
            for (size_t coluna = 0; coluna < n; coluna++)
            {
                if (linha != coluna)
                {
                    sum += (A[linha][coluna] * x[coluna]);
                }

            }

            x[linha] = (b[linha] - sum) / A[linha][linha];
            
        }

        mat_multv(n, n, A, x, A_x);

        for (size_t i = 0; i < n; i++)
        {
            residuo[i] = b[i] - A_x[i];
        }
        
        n2_residuo = vet_norma2(n, residuo);

        iteracoes += 1;

    } while (n2_residuo > tol);
    
    vet_libera(residuo);
    vet_libera(A_x);

    return iteracoes;
}

int sor_gauss_seidel (int n, double** A, double* b, double* x, double tol, double w)
{
    if (w <= 1.0)
    {
        printf("Valor de w menor ou igual que 1.0 para realizar sobre-relaxação (w = %.16g)\n", w);
        exit(1);
    }

    int iteracoes = 0;
    double* residuo = vet_cria(n);
    double* A_x = vet_cria(n);

    double sum;
    double n2_residuo;
    double x_k_1, x_k;

    do
    {
        for (size_t linha = 0; linha < n; linha++)
        {
            
            sum = 0;
            
            for (size_t coluna = 0; coluna < n; coluna++)
            {
                if (linha != coluna)
                {
                    sum += (A[linha][coluna] * x[coluna]);
                }

            }

            x_k_1 = (b[linha] - sum) / A[linha][linha];
            x_k = x[linha];
            
            x[linha] = ((1 - w) * x_k) + (w * x_k_1);
            
        }

        mat_multv(n, n, A, x, A_x);

        for (size_t i = 0; i < n; i++)
        {
            residuo[i] = b[i] - A_x[i];
        }
        
        n2_residuo = vet_norma2(n, residuo);

        iteracoes += 1;

    } while (n2_residuo > tol);
    
    vet_libera(residuo);
    vet_libera(A_x);

    return iteracoes;


    
}
