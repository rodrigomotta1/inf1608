#include <stdio.h>
#include <math.h>
#include "taylor.h"
#include "vetor.h"

int main()
{
    int termos[] = {3, 4, 5, 6, 7};
    double x[] = {M_PI/10.0, M_PI/8.0, M_PI/6.0, M_PI/4.0, M_PI/3.0};
    int testes = 5;
    printf("ORDEM CRESCENTE DE PRECISAO DA SERIE DE TAYLOR\n\n");
    printf("VALOR EXATO do COSSENO\t|\tSERIE DE TAYLOR do COS\t|\tDIF\n");
    for(int i = 0; i < testes; i++)
    {   
        printf("%.16g\t|\t%.16g\t|\t%.16g\n", cos(x[i]) , avalia_cosseno(termos[i], x[i]), cos(x[i]) - avalia_cosseno(termos[i], x[i]));
    }

    printf("\n");
    printf("VALOR EXATO do SENO\t|\tSERIE DE TAYLOR do SENO\t|\tDIF\n");
    for(int j = 0; j < testes; j++)
    {
        
        printf("%.16g\t|\t%.16g\t|\t%.16g\n", sin(x[j]) , avalia_seno(termos[j], x[j]), sin(x[j]) - avalia_seno(termos[j], x[j]));
    }
    
    printf("\n");

    return 0;
}