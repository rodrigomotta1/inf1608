#include <stdio.h>
#include <math.h>
#include "ode.h"

/**
 * Função derivada dummy para teste de Runge-Kutta constante e adaptativo
 * 
 * @param t valor do tempo
 * @param y valor de y
 */
double fderiv(double t, double y)
{
    return (t * y) + (t * t * t);
}


/**
 * Procedimentos de teste para RK de quarta ordem com h constante
 */
void test_cte()
{
    double res;

    // y' = ty + t^3
    // y(0) = -1
    res = RungeKutta(0.0, 2.4, 0.001, -1.0, fderiv);

    printf("RK4 = %.16g   [ h = 0.001 (constante) ]\n", res);

    printf("esperado = %.16g\n", exp((2.4 * 2.4) / 2)) - (2.4 * 2.4) - 2;
}

void test_adapt()
{
    double res;

    res = RungeKuttaAdapt(0.0, 2.4, -1.0, fderiv, 1e-12);

    printf("RK4 = %.16g   [ h = 10e-7 (adaptativo) ]\n", res);

    printf("esperado = %.16g\n", exp((2.4 * 2.4) / 2)) - (2.4 * 2.4) - 2;
}


int main(int argc, char const *argv)
{
    test_cte();
    test_adapt();
    return 0;
}
