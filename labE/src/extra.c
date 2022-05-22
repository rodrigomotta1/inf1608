#include <stdio.h>
#include <math.h>
#include "extra.h"
#include "matriz.h"
#include "vetor.h"


int IQI (double x0, double x1, double x2, double (*f) (double x), double* r)
{
    int iteracoes = 0;

    // Estimativas iniciais
    double* estimativas = vet_cria(3);
    estimativas[0] = x0;
    estimativas[1] = x1;
    estimativas[2] = x2;

    // Avaliações de f
    double* avaliacoes = vet_cria(3);
    

    // Matriz para calculo de estimativa final
    double** A = mat_cria(3, 3);
    double** Ac = mat_cria(3, 3);

    // Estimativa final
    double c;

    do
    {
        // Checa caso de divergência
        if (iteracoes > 50)
            return -1;

        // Define avaliações da iteração
        avaliacoes[0] = f(estimativas[0]);
        avaliacoes[1] = f(estimativas[1]);
        avaliacoes[2] = f(estimativas[2]);

        // Define matriz A e Ac
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

        // Atualiza próximas estimativas, caso sejam usadas em próxima iteração
        estimativas[0] = estimativas[1];
        estimativas[1] = estimativas[2];
        estimativas[2] = c;

        

        // Incrementa número de iterações
        iteracoes += 1;

        if (fabs(f(c)) > PRECISAO_IQI)
            printf("continua\n");
        else
            printf("fim\n");

        printf("[%d] %.16g | < %.16g >\n", iteracoes, c, fabs(f(c)));
        
    } while (fabs(f(c)) > PRECISAO_IQI);

    *r = c;
    
    vet_libera(estimativas);
    vet_libera(avaliacoes);
    mat_libera(3, A);
    mat_libera(3, Ac);

    return iteracoes;
}
