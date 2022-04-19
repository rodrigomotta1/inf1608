#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"


// auxiliares
int fatorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        int fat = n;

        for(int i = n - 1; i > 0; i--)
        {
            fat *= i;
        }

        return fat;
    }
}


double potencia(double val, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        double pot = val;

        for(int i = 1; i < n; i++)
        {
            pot *= val;
        }

        return pot;
    }
}


double avalia_taylor(int n, double* c, double x0, double x)
{
    double resultado = 0.0;

    for(int i = 0; i < n; i++)
    {
        double i_fat = (double) fatorial(i);
        resultado += (c[i]/i_fat) * (potencia(x - x0, i));
    }

    return resultado;
}


double avalia_cosseno(int n, double x)
{   
    double* coefs = vet_cria(n);

    // Variavel que indica se ultimo 1 foi negativo ou nao, para controlar a criacao dos coeficientes de taylor do cos
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int idx = i + 1;
        if(idx % 2 == 0)
        {
            coefs[i] = 0.0;
        }
        else
        {
            if(count == 2)
                coefs[i] = -1.0;
            else
                coefs[i] = 1.0;            
        }

        if(count == 3)
        {
            count = 0;
        }

        count += 1;        
    }
    
    double resultado = avalia_taylor(n, coefs, 0, x);

    vet_libera(coefs);

    return resultado;
}


double avalia_seno(int n, double x)
{   
    double* coefs = vet_cria(n);

    // Variavel que indica se ultimo 1 foi negativo ou nao, para controlar a criacao dos coeficientes de taylor do cos
    int count = 0;

    // 0, 1, 0, -1

    for(int i = 0; i < n; i++)
    {
        int idx = i + 1;

        if(idx % 2 == 0)
        {
            if(count == 3)
                coefs[i] = -1.0;
            else
                coefs[i] = 1.0;
        }
        else
        {
            coefs[i] = 0.0;         
        }

        if(count == 3)
        {
            count = 0;
        }

        count += 1;
    }
    
    double resultado = avalia_taylor(n, coefs, 0, x);

    vet_libera(coefs);

    return resultado;
}