#include "vetor.h"
#include "matriz.h"
#include "sistlinear.h"
#include <stdio.h>


double mmq (int m, int n, double** A, double* b, double* x)
{
    // m linhas, n colunas !!

    double** AT = mat_cria(n, m);
    double** AT_A = mat_cria(n, n);
    double* AT_b = vet_cria(n);
    double* residuo = vet_cria(m);
    double* A_xb = vet_cria(m);

    double n2_residuo;

    // Calcular e armazenar o valor da matriz transposta de A
    mat_transposta(m, n, A, AT);

    // Multiplica A por AT, guardando o valor
    mat_multm(n, m, n, AT, A, AT_A);

    // Multiplica AT por b, guardando o valor
    mat_multv(n, m, AT, b, AT_b);

    // Chamar gauss para ATAx = ATb
    gauss(n, AT_A, AT_b, x);

    // Calcula Ax barra, guardando o valor
    mat_multv(m, n, A, x, A_xb);

    // Calcula o residuo, b - Ax, guardando o valor
    vet_sub(m, b, A_xb, residuo);

    // Calcula norma2 do residuo previamente calculado
    n2_residuo = vet_norma2(m, residuo);

    // libera tudo
    mat_libera(n, AT);
    mat_libera(n, AT_A);
    vet_libera(AT_b);
    vet_libera(residuo);
    vet_libera(A_xb);

    return n2_residuo;
}


double ajuste_parabola(int n, double* px, double* py, double* a, double* b, double* c)
{   
    // Obs: o vetor b para MMQ corresponde ao vetor py recebido

    // Matriz do sistema com N linhas (uma para cada ponto) e 2 colunas (uma para cada coeficiente, nesse caso do ajuste à parabola)
    double** A = mat_cria(n, 3);

    // Vetor que armazena resultado do sistema
    double* x = vet_cria(3);

    // Variavel de armazenamento do residuo
    double residuo;

    for (size_t linha = 0; linha < n; linha++)
    {
        A[linha][0] = 1;
        A[linha][1] = px[linha];
        A[linha][2] = px[linha] * px[linha];
    }

    residuo = mmq(n, 3, A, py, x);
    
    // Atribuição dos coeficientes
    *a = x[0];
    *b = x[1];
    *c = x[2];

    // Liberaão de memória
    vet_libera(x);
    mat_libera(n, A);

    return residuo;
}


double ajuste_cubica(int n, double* px, double* py, double* a, double* b, double* c, double* d)
{   
    // Obs: o vetor b para MMQ corresponde ao vetor py recebido
    
    // Matriz do sistema com N linhas (uma para cada ponto) e 2 colunas (uma para cada coeficiente, nesse caso do ajuste à parabola)
    double** A = mat_cria(n, 4);

    // Vetor que armazena resultado do sistema
    double* x = vet_cria(4);

    // Variavel de armazenamento do residuo
    double residuo;

    for (size_t linha = 0; linha < n; linha++)
    {
        A[linha][0] = 1;
        A[linha][1] = px[linha];
        A[linha][2] = px[linha] * px[linha];
        A[linha][3] = px[linha] * px[linha] * px[linha];
    }

    residuo = mmq(n, 4, A, py, x);
    
    // Atribuição dos coeficientes
    *a = x[0];
    *b = x[1];
    *c = x[2];
    *d = x[3];

    // Liberaão de memória
    vet_libera(x);
    mat_libera(n, A);

    return residuo;
}