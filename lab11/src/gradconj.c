#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "matriz.h"

// Sem pre condicionador
int gradconj (int n, double** A, double* b, double* x, double tol)
{
    int iteracoes;
    double r_n2;

    double* d = vet_cria(n);
    double* r = vet_cria(n);

    double* A_x = vet_cria(n);
    double* A_d = vet_cria(n);

    double* alfa_d = vet_cria(n);
    double* alfa_A_d = vet_cria(n);
    double* beta_d = vet_cria(n);

    double* next_x = vet_cria(n);
    double* next_r = vet_cria(n);
    double* next_d = vet_cria(n);

    double alfa;
    double beta;

    double dividendo;
    double divisor;

    // Ax
    mat_multv(n, n, A, x, A_x);

    // r0 = b - Ax
    vet_sub(n, b, A_x, r);

    // Copia valores do vetor r para o vetor d (d0 = r0) 
    vet_cpy(n, r, d);

    for (iteracoes = 0; iteracoes < n; iteracoes++)
    {
        r_n2 = vet_norma2(n, r);

        if (r_n2 < tol)
            break;
        
        // Calculate alfa division values
        vet_multrc(n, r, r, &dividendo);

        mat_multv(n, n, A, d, A_d);

        vet_multrc(n, d, A_d, &divisor);

        // Calculate alfa
        alfa = dividendo / divisor;

        // Calculate values for next x and next r
        vet_mults(n, d, alfa, alfa_d);
        vet_mults(n, A_d, alfa, alfa_A_d);

        vet_soma(n, x, alfa_d, next_x);
        vet_sub(n, r, alfa_A_d, next_r);

        
        // Calculates beta division values
        vet_multrc(n, next_r, next_r, &dividendo);
        vet_multrc(n, r, r, &divisor);

        // Calculates beta
        beta = dividendo / divisor;

        // Calculates next_d values
        vet_mults(n, d, beta, beta_d);

        // Calculates next_d
        vet_soma(n, next_r, beta_d, next_d);

        // Updates r, x, and d
        vet_cpy(n, next_x, x);
        vet_cpy(n, next_r, r);
        vet_cpy(n, next_d, d);
        
        
    }
    
    vet_libera(d);
    vet_libera(r);
    vet_libera(A_x);
    vet_libera(A_d);
    vet_libera(alfa_d);
    vet_libera(alfa_A_d);
    vet_libera(beta_d);
    vet_libera(next_x);
    vet_libera(next_r);
    vet_libera(next_d);

    return iteracoes;
}


// Com pre cond
int gradconj_jacobi (int n, double** A, double* b, double* x, double tol)
{
    int iteracoes;
    double r_n2;

    double** condicionador = mat_cria(n, n);
    double** cond_inverso = mat_cria(n, n);

    double* d = vet_cria(n);
    double* r = vet_cria(n);
    double* z = vet_cria(n);

    double* A_x = vet_cria(n);
    double* A_d = vet_cria(n);

    double* alfa_d = vet_cria(n);
    double* alfa_A_d = vet_cria(n);
    double* beta_d = vet_cria(n);

    double* next_x = vet_cria(n);
    double* next_r = vet_cria(n);
    double* next_d = vet_cria(n);
    double* next_z = vet_cria(n);

    double alfa;
    double beta;

    double dividendo;
    double divisor;

    // Define pre-condicionador como a matriz diagonal de A
    for (size_t i = 0; i < n; i++)
    {
        condicionador[i][i] = A[i][i];
    }

    // Define inversa do pre-condicionador
    mat_inv_diag(n, condicionador, cond_inverso);
    
    // Ax
    mat_multv(n, n, A, x, A_x);


    // r0 = b - Ax
    vet_sub(n, b, A_x, r);

    // z0 = M-1r0
    mat_multv(n, n, cond_inverso, r, z);

    // Copia valores do vetor r para o vetor d (d0 = r0) 
    vet_cpy(n, z, d);

    for (iteracoes = 0; iteracoes < n; iteracoes++)
    {
        r_n2 = vet_norma2(n, r);

        if (r_n2 < tol)
            break;
        
        // Calculate alfa division values
        vet_multrc(n, r, z, &dividendo);

        mat_multv(n, n, A, d, A_d);

        vet_multrc(n, d, A_d, &divisor);

        // Calculate alfa
        alfa = dividendo / divisor;

        // Calculate values for next x next r and next z
        vet_mults(n, d, alfa, alfa_d);
        vet_mults(n, A_d, alfa, alfa_A_d);

        vet_soma(n, x, alfa_d, next_x);
        vet_sub(n, r, alfa_A_d, next_r);
        mat_multv(n, n, cond_inverso, next_r, next_z);


        // Calculates beta division values
        vet_multrc(n, next_r, next_z, &dividendo);
        vet_multrc(n, r, z, &divisor);

        // Calculates beta
        beta = dividendo / divisor;

        // Calculates next_d values
        vet_mults(n, d, beta, beta_d);

        // Calculates next_d
        vet_soma(n, next_z, beta_d, next_d);

        // Updates r, x, and d
        vet_cpy(n, next_x, x);
        vet_cpy(n, next_r, r);
        vet_cpy(n, next_d, d);
        vet_cpy(n, next_z, z);

        
        
    }
    
    vet_libera(d);
    vet_libera(r);
    vet_libera(z);
    vet_libera(A_x);
    vet_libera(A_d);
    vet_libera(alfa_d);
    vet_libera(alfa_A_d);
    vet_libera(beta_d);
    vet_libera(next_x);
    vet_libera(next_r);
    vet_libera(next_d);
    vet_libera(next_z);
    mat_libera(n, condicionador);
    mat_libera(n, cond_inverso);

    return iteracoes;
}