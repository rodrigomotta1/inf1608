#include <stdio.h>
#include "vetor.h"
#include "metiter.h"
#include "matriz.h"
#define TRUE 1
#define FALSE 0

void test_a(double w, int sobre_relaxacao)
{
    double** A = mat_cria(2, 2);
    double* x0 = vet_cria(2);

    x0[0] = 0.0;
    x0[1] = 0.0;

    A[0][0] = 3.0;
    A[0][1] = 1.0;
    A[1][0] = 1.0;
    A[1][1] = 2.0;

    double* b = vet_cria(2);

    b[0] = 5.0;
    b[1] = 5.0;

    int iter;

    if (sobre_relaxacao)
        iter = sor_gauss_seidel(2, A, b, x0, 1e-7, w);
    else
        iter = gauss_seidel(2, A, b, x0, 1e-7);
    
    

    vet_imprime(2, x0);
    printf("teste1 iteracoes: %d\n", iter);

    mat_libera(2, A);
    vet_libera(b);
    vet_libera(x0);

    double** B = mat_cria(6, 6);
    double* xb0 = vet_cria(6);

    xb0[0] = 0.0;
    xb0[1] = 0.0;
    xb0[2] = 0.0;
    xb0[3] = 0.0;
    xb0[4] = 0.0;
    xb0[5] = 0.0;

    B[0][0] = 3.0;
    B[0][1] = -1.0;
    B[0][2] = 0.0;
    B[0][3] = 0.0;
    B[0][4] = 0.0;
    B[0][5] = 0.5;

    B[1][0] = -1.0;
    B[1][1] = 3.0;
    B[1][2] = -1.0;
    B[1][3] = 0.0;
    B[1][4] = 0.5;
    B[1][5] = 0.0;

    B[2][0] = 0.0;
    B[2][1] = -1.0;
    B[2][2] = 3.0;
    B[2][3] = -1.0;
    B[2][4] = 0.0;
    B[2][5] = 0.0;

    B[3][0] = 0.0;
    B[3][1] = 0.0;
    B[3][2] = -1.0;
    B[3][3] = 3.0;
    B[3][4] = -1.0;
    B[3][5] = 0.0;

    B[4][0] = 0.0;
    B[4][1] = 0.5;
    B[4][2] = 0.0;
    B[4][3] = -1.0;
    B[4][4] = 3.0;
    B[4][5] = -1.0;

    B[5][0] = 0.5;
    B[5][1] = 0.0;
    B[5][2] = 0.0;
    B[5][3] = 0.0;
    B[5][4] = -1.0;
    B[5][5] = 3.0;

    double* bb = vet_cria(6);

    bb[0] = 2.5;
    bb[1] = 1.5;
    bb[2] = 1.0;
    bb[3] = 1.0;
    bb[4] = 1.5;
    bb[5] = 2.5;

    int iterB;
    
    if (sobre_relaxacao)
        iterB = sor_gauss_seidel(6, B, bb, xb0, 1e-7, w);
    else
        iterB = gauss_seidel(6, B, bb, xb0, 1e-7);

    vet_imprime(6, xb0);
    printf("teste2 iteracoes: %d\n", iterB);

    mat_libera(6, B);
    vet_libera(bb);
    vet_libera(xb0);
}


int main(int argc, char const *argv[])
{
    printf("gauss seidel sem sobre-relaxacao\n");
    test_a(1.1, FALSE);
    printf("gauss seidel com sobre-relaxacao (w = 1.2)\n");
    test_a(1.1, TRUE);
    return 0;
}
