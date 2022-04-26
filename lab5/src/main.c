#include <stdio.h>
#include "vetor.h"
#include "mmq.h"
#include "matriz.h"

void dois_a_i()
{

    double** A = mat_cria(5, 4);
    A[0][0] = 4.0;
    A[0][1] = 2.0;
    A[0][2] = 3.0;
    A[0][3] = 0.0;

    A[1][0] = -2.0;
    A[1][1] = 3.0;
    A[1][2] = -1.0;
    A[1][3] = 1.0;

    A[2][0] = 1.0;
    A[2][1] = 3.0;
    A[2][2] = -4.0;
    A[2][3] = 2.0;

    A[3][0] = 1.0;
    A[3][1] = 0.0;
    A[3][2] = 1.0;
    A[3][3] = -1.0;

    A[4][0] = 3.0;
    A[4][1] = 1.0;
    A[4][2] = 3.0;
    A[4][3] = -2.0;
    
    double b[] = {
        10.0,
        0.0,
        2.0,
        0.0,
        5.0
    };

    double *x = vet_cria(5);

    double residuo = mmq(5, 4, A, b, x);
    
    printf("residuo: %.16g\n", residuo);

    vet_libera(x);
    mat_libera(5, A);
}

void ap()
{
    double px[] = {
        -1.0,
        0.0,
        1.0,
        2.0
    };

    double py[] = {
        1.0,
        0.0,
        0.0,
        -2.0
    };

    double a, b, c;

    double residuo = ajuste_parabola(4, px, py, &a, &b, &c);
    printf("coefs:\n %.16g\n%.16g\n%.16g\n\n residuo: %.16g\n", a, b, c, residuo);

}

void ac()
{
    double px[] = {
        0.0,
        1.0,
        2.0,
        5.0
    };

    double py[] = {
        0.0,
        3.0,
        3.0,
        6.0
    };

    double a, b, c, d;

    double residuo = ajuste_cubica(4, px, py, &a, &b, &c, &d);
    printf("coefs:\n %.16g\n%.16g\n%.16g\n%.16g\n\n residuo: %.16g\n", a, b, c, d, residuo);

}

int main(int argc, char const *argv[])
{
    // dois_a_i();
    // ap();
    ac();
    return 0;
}
