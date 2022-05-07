#include <stdio.h>
#include <math.h>
#include "simpson.h"
#define ln(x) log(x)


double ia(double x)
{
    return x / (sqrt((x * x) + 9));
}

double ib(double x)
{
    return M_2_SQRTPI * (exp(-(x * x)));
}

double ic(double x)
{
    return ln(cos(x) + sin(x));
}

int main(int argc, char const *argv[])
{
    printf("ia - tol = 0.01 \tesperado = 0.1622776601683793\tadapt simpson = %.16g\n", adaptsimpson(0.0, 1.0, ia, 0.01));
    printf("ia - tol = 0.0001\tesperado = 0.1622776601683793\tadapt simpson = %.16g\n", adaptsimpson(0.0, 1.0, ia, 0.0001));
    printf("ia - tol = 0.00000001\tesperado = 0.1622776601683793\tadapt simpson = %.16g\n", adaptsimpson(0.0, 1.0, ia, 0.00000001));
    printf("\n");
    printf("ib - tol = 0.01 \tesperado = 0.9999779095030014\tadapt simpson = %.16g\n", adaptsimpson(0.0, 3.0, ib, 0.01));
    printf("ib - tol = 0.0001\tesperado = 0.9999779095030014\tadapt simpson = %.16g\n", adaptsimpson(0.0, 3.0, ib, 0.0001));
    printf("ib - tol = 0.00000001\tesperado = 0.9999779095030014\tadapt simpson = %.16g\n", adaptsimpson(0.0, 3.0, ib, 0.00000001));
    printf("\n");
    printf("ic - tol = 0.01 \tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.01));
    printf("ic - tol = 0.0001\tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.0001));
    printf("ic - tol = 0.00000001\tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.00000001));
    printf("\n");
    printf("ic - tol = 0.01 \tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.01));
    printf("ic - tol = 0.0001\tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.0001));
    printf("ic - tol = 0.00000001\tesperado = 0.3715690716013184\tadapt simpson = %.16g\n", adaptsimpson(0.0, M_PI_2, ic, 0.00000001));
    printf("\n=================================================\n\n");
    printf("sigma = 0.001\t prob = %.16g %%\n", probabilidade(0.001) * 100);
    printf("sigma = 0.01\t prob = %.16g %%\n", probabilidade(0.01) * 100);
    printf("sigma = 0.05\t prob = %.16g %%\n", probabilidade(0.05) * 100);
    printf("sigma = 0.1\t prob = %.16g %%\n", probabilidade(0.1) * 100);
    printf("sigma = 0.15\t prob = %.16g %%\n", probabilidade(0.15) * 100);
    printf("sigma = 0.2\t prob = %.16g %%\n", probabilidade(0.2) * 100);
    printf("sigma = 0.25\t prob = %.16g %%\n", probabilidade(0.25) * 100);
    printf("sigma = 0.3\t prob = %.16g %%\n", probabilidade(0.3) * 100);
    printf("sigma = 0.35\t prob = %.16g %%\n", probabilidade(0.35) * 100);
    printf("sigma = 0.4\t prob = %.16g %%\n", probabilidade(0.4) * 100);
    printf("sigma = 0.45\t prob = %.16g %%\n", probabilidade(0.45) * 100);

    return 0;
}
