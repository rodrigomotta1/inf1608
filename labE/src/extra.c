#include <stdio.h>
#include <math.h>
#include "extra.h"
#include "matriz.h"
#include "vetor.h"
#include "mmq.h"


int IQI (double x0, double x1, double x2, double (*f) (double x), double* r)
{
    int iteracoes = 0;

    // Estimativas
    double* estimativas = vet_cria(3);
    estimativas[0] = x0;
    estimativas[1] = x1;
    estimativas[2] = x2;

    // Avaliações de f
    double* avaliacoes = vet_cria(3);
    avaliacoes[0] = f(estimativas[0]);
    avaliacoes[1] = f(estimativas[1]);
    avaliacoes[2] = f(estimativas[2]);

    // Matriz para calculo de estimativa final
    double** A = mat_cria(3, 3);
    double** Ac = mat_cria(3, 3);

    // Estimativa final
    double c;

    // Aval da estimativa final
    double fc;

    do
    {
        // Checa caso de divergência
        if (iteracoes > 50)
        {
            *r = estimativas[2];
            return -1;
        }
        
        // Monta matrizes A e Ac
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                switch (j)
                {
                    // Primeira coluna
                    case 0:
                        A[i][j] = avaliacoes[i] * avaliacoes[i];
                        Ac[i][j] = A[i][j];
                        break;
                    
                    // Segunda coluna
                    case 1:
                        A[i][j] = avaliacoes[i];
                        Ac[i][j] = A[i][j];
                        break;

                    // Terceira coluna
                    case 2:
                        A[i][j] = 1;
                        Ac[i][j] = estimativas[i];
                        break;
                    
                    default:
                        break;
                }   
            } 
        }

        // Calcula estimativa final
        c = mat_det_3(Ac) / mat_det_3(A);

        // Aval de c
        fc = f(c);

        // Atualiza próximas estimativas, caso sejam usadas em próxima iteração
        estimativas[0] = estimativas[1];
        estimativas[1] = estimativas[2];
        estimativas[2] = c;

        // Atualiza avaliações necessárias pra próxima iteração
        avaliacoes[0] = avaliacoes[1];
        avaliacoes[1] = avaliacoes[2];
        avaliacoes[2] = fc;
        
        // Incrementa número de iterações
        iteracoes += 1;
        
    } while (fabs(fc) > PRECISAO_IQI);

    *r = c;

    vet_libera(estimativas);
    vet_libera(avaliacoes);
    mat_libera(3, A);
    mat_libera(3, Ac);

    return iteracoes;
}


void ajuste(int n, double* t, double* c, double* a, double* b)
{

    // Matriz do sistema com N linhas (uma para cada ponto) e 2 colunas (uma para cada coeficiente, no caso deste modelo)
    double** A = mat_cria(n, 2);

    // Vetor que armazena o resultado do mmq
    double* x = vet_cria(2);

    // Vetor que armazena valores para serem utilizados com y no MMQ
    double* y = vet_cria(2);

    // Variavel que armazena o residuo
    double residuo;

    // Setup da matriz A e vetor y
    for (size_t linha = 0; linha < n; linha++)
    {
        // Define vetor y que será utilizado no MMQ
        y[n] = log(c[linha]) - log(t[linha]);

        // Define linhas da matriz A que será utilizada no MMQ
        A[linha][0] = 1;
        A[linha][1] = t[linha];    

        // obs: função de ajuste normaliada -> y = k + bx :=> k = ln(a) && y = ln(y) - ln(x)
    }

    residuo = mmq(n, 2, A, y, x);

    printf("[ residuo ajuste: %.16g ]\n", residuo);

    *a = exp(x[0]); // k = ln(a)
    *b = x[1];

    mat_libera(n, A);
    vet_libera(x);
    vet_libera(y);
    
}