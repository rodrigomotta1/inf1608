#include <math.h>
#include "simpson.h"
#include "integral.h"
#define M_1_SQRT_2_PI 1 / (sqrt(2 * M_PI))
#define SIMPSON_STEPS 32


double adaptsimpson(double a, double b, double (*f) (double x), double tol)
{
    double m = (a + b) / 2; // Metade do intervalo de integração

    double simpson_total = simpson(f, a, b, SIMPSON_STEPS); // S[a, b]

    double simpson_mi = simpson(f, a, m, SIMPSON_STEPS); // S[a, m]
    double simpson_mf = simpson(f, m, b, SIMPSON_STEPS); // S[m, b]

    double soma_metades = simpson_mi + simpson_mf; // S[a, m] + S[m, b]

    double delta = simpson_total - soma_metades; // Δ = S[a, b] - (S[a, m] + S[m, b])

    double tol_limit = 15 * tol; // Δ / 15 > ε -> Δ > 15ε

    if (fabs(delta) > tol_limit) // |Δ| > 15ε?
    {
        return adaptsimpson(a, m, f, tol/2) + adaptsimpson(m, b, f, tol/2);
    }
    else
    {
        return soma_metades - tol_limit;
    }
}

double desvio_padrao(double x)
{
    return exp((-(x * x)) / 2);
}

double probabilidade(double sigma)
{
    // double M_1_SQRT_2_PI = 1 / (sqrt(2 * M_PI));
    return (M_1_SQRT_2_PI) * adaptsimpson(-sigma, sigma, desvio_padrao, 1e-11);
}