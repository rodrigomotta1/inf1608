#include <stdio.h>
#include "vetor.h"
#include "matriz.h"

int main()
{
    int m = 2;
    int n = 3;
    int q = 4;

    double* arr = vet_cria(n);
    // double* arrb = vet_cria(n);
    // double* multres = vet_cria(n);
    double* resmulmave = vet_cria(m);
    

    double** matriz = mat_cria(m, n);
    double** transposta = mat_cria(n, m);
    double** mulmatriz = mat_cria(m, m);

    for (int i = 0; i < m; i++)
    {
        
        // arr[i] = 2.0;
        // arrb[i] = 4.0;

        for(int j = 0; j < n; j++)
        {
            arr[j] = 2.0;
            matriz[i][j] = (double)(i + j);
        }
    } 

    // double res = vet_escalar(n, arr, arrb);
    // double nor = vet_norma2(n, arr);

    // vet_mults(n, arr, 3.1, multres);

    // vet_imprime(n, multres);

    // vet_libera(arrb);
    // vet_libera(multres);

    printf("Matriz\n");
    mat_imprime(m, n, matriz);

    mat_transposta(m, n, matriz, transposta);

    printf("Matriz Transposta\n");
    mat_imprime(n, m, transposta);

    printf("Vetor\n");
    vet_imprime(n, arr);

    mat_multv(m, n, matriz, arr, resmulmave);

    printf("Res. Mul. Ma x Ve\n");
    vet_imprime(m, resmulmave);

    printf("Mulmatriz\n");
    mat_multm(m, n, m, matriz, transposta, mulmatriz);
    mat_imprime(m, m, mulmatriz);

    vet_libera(arr);
    vet_libera(resmulmave);
    mat_libera(m, matriz);
    mat_libera(n, transposta);
    mat_libera(m, mulmatriz);
    
    return 0;
}