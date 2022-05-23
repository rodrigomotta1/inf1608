#include "ode.h"
#include <stdio.h>
#include <math.h>
#define QUASE_ZERO 1e-10


double avancoRungeKutta(double ti, double yi, double h, double (*f) (double t, double y))
{
    double k0, k1, k2, k3, y;

    k0 = h * f(ti, yi);
    k1 = h * f(ti + (h / 2), yi + k0/2);
    k2 = h * f(ti + (h / 2), yi + k1/2);
    k3 = h * f(ti + h, yi + k2);

    y = yi + ((k0 + (2.0 * k1) + (2.0 * k2) + k3) / 6);

    return y;
}


double RungeKutta (double t0, double t1, double h, double y0, double (*f) (double t, double y))
{
    // Variável de passo ti
    double ti;

    double yi = y0;

    // Para cada passo ti, comecando de t0 e avançando com passo h, até t1
    for (ti = t0; fabs(ti - t1) > QUASE_ZERO; ti += h)
        yi = avancoRungeKutta(ti, yi, h, f);
    
    // y no tempo final
    return yi;
}


double avancoRungeKuttaAdaptativo(double *ti, double yi, double *h, double (*f) (double t, double y), double tol)
{
    // Variáveis para guardar valores de avaliações de RK
    double y1, ym, y2;

    // Variáveis de controle do algoritmo
    double delta, fator;

    // Guardando valores de h que serão utilizados
    double val_h = *h;
    double val_h_2 = val_h / 2.0;

    // Variável que guarda o mínimo valor para ajuste do passo
    double min;

    y1 = avancoRungeKutta(*ti, yi, val_h, f);
    ym = avancoRungeKutta(*ti, yi, val_h_2, f);
    y2 = avancoRungeKutta(*ti + val_h_2, ym, val_h_2, f);

    delta = (y2 - y1) / 15.0;
    fator = pow(tol / fabs(delta), 1.0 / 5.0);

    if (fator >= 1.0)
    {
        // Incrementa o passo com o h antigo
        *ti += *h;
        
        // Atualiza h
        min = 1.2 > fator ? fator : 1.2;
        *h *= min;

        return y2 + delta;
    }

    *h *= (0.8 * fator);

    return avancoRungeKuttaAdaptativo(ti, yi, h, f, tol);
}


double RungeKuttaAdapt (double t0, double t1, double y0, double (*f) (double t, double y), double tol)
{    
    // Controle de passo
    double ti = t0;

    // Armazenamento do resultado final
    double yi = y0;

    // Passo h0
    double h0 = 1e-7;
    
    while (ti < t1)
    {
        if (ti + h0 > t1)
        {
            h0 = t1 - ti;
        }

        yi = avancoRungeKuttaAdaptativo(&ti, yi, &h0, f, tol);
    }

    return yi;
}
