#include <math.h>
#include <stdlib.h>
#include <stdio.h>


double derivada (int n, double(*f) (double x), double x, double h)
{
    // Assert do valor de n na entrada
    if (n < 2)
    {
        printf("Valor mínimo para ordem de avaliação númerica da derivada: 2 (%d foi passado...)\n", n);
        exit(1);
    } 
    else if (n == 2)
    {
        return (f(x + h) - f(x - h)) / (2 * h);
    }
    else
    {
        double fn_h = derivada(n - 1, f, x, h);
        double fn_hp2 = derivada(n - 1, f, x, h/2.0);
        double pot2 = pow(2, n - 1);

        return ((pot2 * fn_hp2) - fn_h) / (pot2 - 1);
    }
}


double simpson(double(*f) (double x), double a, double b, int n)
{
    double final, sum_fxi = 0, sum_fxim = 0, xi, val;//, total_err;
    
    double h = (b - a)/n;
    final = f(a) + f(b);

    for (size_t i = 1; i < n; i++)
    {
        xi = a + (i * h);

        if (i % 2 == 0)
        {
            final += (2 * f(xi));
        }
        else
        {
            final += (4 * f(xi));
        }
        
    }

    final *= (h / 3);

    // total_err = (((b - a) * (h * h * h * h)) / 2880) * f''''((a + b) / 2);

    return final;
}