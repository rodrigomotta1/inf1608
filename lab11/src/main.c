#include <stdio.h>
#include "gradconj.h"
#include "vetor.h"
#include "matriz.h"


void test_a()
{
    /*
    Os resultados foram levemente mais precisos na execução sem pre-condicionador.
    No entanto, precisaram de duas iterações a mais para chegar em um resultado aceitável.
    Isso faz sentido, uma vez que o objetivo na utilização de um pré-condicionador é exatamente acelerar a convergência do método.
    */

    double** A = mat_cria(10, 10);

    for (int i = 0; i < 10; i++)
    {
        A[i][i] = (double)(i + 1);

        if (i > 0 && i < 9)
        {
            A[i][i - 1] = 0.4;
            A[i][i + 1] = 0.4;
        }
        else if (i == 0)
            A[i][i + 1] = 0.4;
        else if (i == 9)        
            A[i][i - 1] = 0.4;
    }
    
    double b[10] = {
        1.4,
        2.8,
        3.8,
        4.8,
        5.8,
        6.8,
        7.8,
        8.8,
        9.8,
        10.4
    };

    double* x0 = vet_cria(10);
    double* x0b = vet_cria(10);
    double res;
    int iter_s, iter_c;

    iter_s = gradconj(10, A, b, x0, 1e-7);
    vet_imprime(10, x0);
    printf("iteracoes: %d\n", iter_s);


    iter_c = gradconj_jacobi(10, A, b, x0b, 1e-7);
    vet_imprime(10, x0b);
    printf("iteracoes: %d\n", iter_c);


    vet_libera(x0);
    vet_libera(x0b);
    mat_libera(10, A);
}

int main(int argc, char const *argv[])
{
    test_a();
    return 0;
}
