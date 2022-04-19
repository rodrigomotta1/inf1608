#include <stdio.h>
#include <math.h>
#include "vetor.h"
#include "interp.h"
#define SIGMA 0.5
#define MI 0.0

void a()
{
    int n = 4;
    double* v = vet_cria(n);

    regular(n, 0.0, M_PI_2, v);

    vet_imprime(n, v);
    vet_libera(v);
}

void b()
{
    int n = 4;
    double* v = vet_cria(n);

    chebyshev(n, 0.0, M_PI_2, v);

    vet_imprime(n, v);
    vet_libera(v);
}

double f(double x)
{
    if (x == -1.0 || x == 1.0)
    {
        return 3.0;
    }
    else if (x == 0.0)
    {
        return 1.0;
    }
    else if (x == 3.0)
    {
        return 43.0;
    }
    else
    {
        return -9999.0;
    } 
}

void c()
{
    int n = 4;
    double* bi = vet_cria(n);
    double xi[] = {-1.0, 0.0, 1.0, 3.0};

    coeficientes(n, xi, f, bi);

    vet_imprime(n, bi);
    vet_libera(bi);
}

double distribuicao_normal(double x)
{
    return (1 / (sqrt(M_PI * 2) * SIGMA)) * exp(-0.5 * ((x - MI) / SIGMA) * ((x - MI) / SIGMA));
}

void dois()
{
    int quatro_amostras = 4;
    int amostras = 11;

    double pontos[] = {0.0, 0.4, -0.4, 0.8, 1.2};
    size_t n = 5;

    // double* q_regular = vet_cria(quatro_amostras);
    // double* d_regular = vet_cria(doze_amostras);
    // double* q_cheby = vet_cria(quatro_amostras);
    double* d_cheby = vet_cria(amostras);

    // regular(quatro_amostras, -2.0, 2.0, q_regular);
    // regular(doze_amostras, -2.0, 2.0, d_regular);
    // chebyshev(quatro_amostras, -2.0, 2.0, q_cheby);
    chebyshev(amostras, -2.0, 2.0, d_cheby);

    // double* qrb = vet_cria(quatro_amostras);
    // double* drb = vet_cria(doze_amostras);
    // double* qcb = vet_cria(quatro_amostras);
    double* dcb = vet_cria(amostras);

    // coeficientes(quatro_amostras, q_regular, distribuicao_normal, qrb);
    // coeficientes(doze_amostras, d_regular, distribuicao_normal, drb);
    // coeficientes(quatro_amostras, q_cheby, distribuicao_normal, qcb);
    coeficientes(amostras, d_cheby, distribuicao_normal, dcb);

    printf("N Amostras\tInterpolacao\tValor Exato\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t%.16g\t%.16g\n", amostras, avalia(amostras, d_cheby, dcb, pontos[i]), distribuicao_normal(pontos[i]));
    }
    
    // vet_libera(q_regular);
    // vet_libera(d_regular);
    // vet_libera(q_cheby);
    vet_libera(d_cheby);
}

int main()
{   
    // a();
    // b();
    // c();
    dois();


    return 0;
}