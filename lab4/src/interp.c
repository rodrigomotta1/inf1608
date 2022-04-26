#include <stdio.h>
#include <math.h>
#include "vetor.h"
#include "matriz.h"


void regular (int n, double a, double b, double* xi)
{
    double step = (b - a) / (n - 1);

    // Define primeira amostra como início do intevalo
    xi[0] = a;

    // Define cada xi em funcao do step definido anteriormente
    for (size_t i = 1; i < n; i++)
    {
        xi[i] = xi[i - 1] + step;
    }
    
}


void chebyshev (int n, double a, double b, double* xi)
{   
    double beta, ene;

    // for (int i = 0; i < n; i++)
    // {
    //     beta = (2 * (i + 1)) - 1;

    //     ps1 = (b - a) / 2;

    //     pcos = cos((beta * M_PI) / (2 * (i + 1)));

    //     ps2 = (a + b) / 2;

    //     xi[i] = ps1 * pcos + ps2;
    // }
    
    for (size_t i = 0; i < n; i++)
    {
        ene = i + 1;
        beta = (2 * ene) - 1;

        xi[i] = (((b - a) / 2) * ((cos(beta * M_PI)) / (2 * ene))) + ((a + b) / 2);
    }
    
}


/*
    Define, recursivamente, as Diferenças Divididas de Newton, guardando-as numa matriz previamente alocada e fornecida.
    Recebe o ponteiro para a matriz M, a função de avaliação f, e os indíces i e j.
*/
void ddn(double** M, double (*f) (double), size_t i, size_t j, double* xi)
{
    size_t ordem = i - j;
    
    if (ordem == 0)
    {
        M[i][j] = f(xi[i]);
    }
    else
    {
        // Calcula os termos anteriores necessarios para a definicao do termo atual
        ddn(M, f, i, j - 1, xi);
        ddn(M, f, i + 1, j, xi);

        // Define o termo atual como a Diferença Divida dos termos anteriormentes calculados
        // A função só chega nessa ponto depois dos termos já terem sido calculados, devido à recursão. 
        // Assim, as funções só são avaliadas uma única vez
        M[i][j] = (M[i + 1][j] - M[i][j - 1]) / (xi[j] - xi[i]);
    } 
}


void coeficientes (int n, double* xi, double (*f) (double), double* bi)
{
    double** diferencas = mat_cria(n, n);

    ddn(diferencas, f, 0, n - 1, xi);

    for (size_t i = 0; i < n; i++)
    {
        bi[i] = diferencas[0][i];
    }
    
    // mat_imprime(n, n, diferencas);

    mat_libera(n, diferencas);
}


double avalia (int n, double* xi, double* bi, double x)
{
    double resultado = bi[0];

    double* termo_x = vet_cria(n);

    termo_x[0] = (x - xi[0]);

    for (size_t i = 1; i < n; i++)
    {
        termo_x[i] = termo_x[i - 1] * (x - xi[i]);
        resultado += (bi[i] * termo_x[i - 1]);
    }

    return resultado;
}
