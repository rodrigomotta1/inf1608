#include <stdio.h>
#include "matriz.h"
#include "vetor.h"
#include "sistlinear.h"



void q1()
{
    int n = 3;

    double** M = mat_cria(n, n);
    double* x = vet_cria(n);
    double* b = vet_cria(n);

    M[2][0] = 1.0;
    M[2][1] = -1.0;
    M[2][2] = 0.0;

    M[1][0] = -1.0;
    M[1][1] = 2.0;
    M[1][2] = 1.0;

    M[0][0] = 0.0;
    M[0][1] = 1.0;
    M[0][2] = 2.0;
    
    b[2] = 0.0;
    b[1] = 2.0;
    b[0] = 3.0;

    mat_imprime(n, n, M);
    vet_imprime(n, b);

    gauss(n, M, b, x);

    vet_imprime(n, x);

    mat_libera(n, M);
    vet_libera(x);
    vet_libera(b);

    return;
}

void q2()
{
    int n = 6;

    double** M = mat_cria(n, n);
    double* x = vet_cria(n);
    double* b = vet_cria(n);

    M[1][0] = 3.0;
    M[1][1] = -1.0;
    M[1][2] = 0.0;
    M[1][3] = 0.0;
    M[1][4] = 0.0;
    M[1][5] = 0.5;

    M[0][0] = -1.0;
    M[0][1] = 3.0;
    M[0][2] = -1.0;
    M[0][3] = 0.0;
    M[0][4] = 0.5;
    M[0][5] = 0.0;

    M[5][0] = 0.0;
    M[5][1] = -1.0;
    M[5][2] = 3.0;
    M[5][3] = -1.0;
    M[5][4] = 0.0;
    M[5][5] = 0.0;

    M[3][0] = 0.0;
    M[3][1] = 0.0;
    M[3][2] = -1.0;
    M[3][3] = 3.0;
    M[3][4] = -1.0;
    M[3][5] = 0.0;

    M[4][0] = 0.0;
    M[4][1] = 0.5;
    M[4][2] = 0.0;
    M[4][3] = -1.0;
    M[4][4] = 3.0;
    M[4][5] = -1.0;

    M[2][0] = 0.5;
    M[2][1] = 0.0;
    M[2][2] = 0.0;
    M[2][3] = 0.0;
    M[2][4] = -1.0;
    M[2][5] = 3.0;

    b[1] = 2.5;
    b[0] = 1.5;
    b[5] = 1.0;
    b[3] = 1.0;
    b[4] = 1.5;
    b[2] = 2.5;

    mat_imprime(n, n, M);
    vet_imprime(n, b);

    gauss(n, M, b, x);

    vet_imprime(n, x);

    mat_libera(n, M);
    vet_libera(x);
    vet_libera(b);

    return;
}

int main()
{
    // test();
    // q1();
    q2();

    return 0;
}