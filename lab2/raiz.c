#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ZERO_APROX 10e-12
#define EPSLON  0.5e-18
#define ZERO_APROX_SEC 1e-15
#define EPSLON_SEC 0.5e-10



/* 
 * Função: bissecao
 * ----------------
 * calcula a raíz de uma função f utilizando o Método da Bisseção.
 *  supõe que a < b e f(a)*f(b) < 0. caso contrário, a determinação da raíz será errada.
 * 
 * a: inicio do intervalo (deve ser menor que b);
 * b: final do intervalo (deve ser maior que a);
 * f: função de avaliação, a qual deseja-se encontrar a raíz. retorna um double e recebe um double;
 * r: ponteiro para double, onde será o guardada a raíz calculada
 * 
 * return: numero de iterações utilizadas para determinação da raíz de f
 *
*/
int bissecao (double a, double b, double (*f) (double x), double* r)
{
    // Meio do intervalo [a, b]
    double c = (a + b) / 2;

    // Guarda avaliação da borda do intervalo [a, b] da última iteração para a próx. iteração
    double ultima_avaliacao = f(a);

    // Guarda as avaliações de c da última iteração
    double avaliacao_c;

    // Número de iterações para encontrar a raíz, que será retornado
    int iteracoes = 0;

    while ((b - a) / 2 > EPSLON)
    {
        // Atualização do meio do intervalo
        c = (a + b) / 2;

        avaliacao_c = f(c);

        // C é quase zero?
        if(fabs(avaliacao_c) < ZERO_APROX)
        {
            // Interrompe iteração
            break;
        }

        // Se o sinal da avaliação de c for contrário ao da outra ponta do intervalo
        if((ultima_avaliacao * avaliacao_c) < 0)
        {
            // Atualiza final do intervalo
            b = c;
        }
        else
        {
            // Atualiza início do intervalo
            a = c;

            // Guarda avaliação do próximo a como a avaliação atual de c
            ultima_avaliacao = avaliacao_c;
        }

        iteracoes += 1;
    }

    // Armazena o valor encotrado para c na variável r (raíz)
    *r = c;

    return iteracoes;
}


/* 
 * Função: secante
 * ---------------
 * calcula a raíz de uma função f utilizando o Método da Secante.
 *  
 * x0: primeira estimativa (deve ser menor que x1)
 * x1: segunda estimativa (deve ser maior que x0)
 * f: função a qual se deseja encontrar a raíz
 * r: ponteiro para a variável que guardará o resultado da raíz de f
 * 
 * 
 * return: numero de iterações utilizadas para determinação da raíz de f
 *
*/

int secante (double x0, double x1, double (*f) (double x), double* r)
{
    int iteracoes = 0;

    // double avaliacao_x1 = f(x1), avaliacao_x0 = f(x0);

    // double x2 = x1 - ((avaliacao_x1 * (x1 - x0)) / (avaliacao_x1 - avaliacao_x0));

    double avaliacao_x0 = f(x0), avaliacao_x1 = f(x1), x2, e;

    do
    {
        // Se o número de iterações ultrapassar 50
        if(iteracoes > 50)
        {
            // O Método da Secante não convergiu; Talvez o intervalo [x0, x1] não compreenda a raíz
            return 0.0;
        }

        // Se a diferença entre as avaliações for muito baixa, substitui a atribuição do valor de x2 (evita divisões por zero ou por denominadores muito baixos)
        if(fabs(avaliacao_x1 - avaliacao_x0) < ZERO_APROX_SEC)
        {
            x2 = (x0 + x1) / 2;
        }
        else
        {
            x2 = x1 - ((avaliacao_x1 * (x1 - x0)) / (avaliacao_x1 - avaliacao_x0));
        }

        // Atribuição do erro reressivo do passo atual
        e = f(x2);

        // Atualiza avaliações para próxima iteração
        avaliacao_x0 = avaliacao_x1;
        avaliacao_x1 = e;

        // Atualiza os valores de x0 e x1
        x0 = x1;
        x1 = x2;

        iteracoes += 1;

    } while (fabs(e) >= EPSLON_SEC);

    // Guarda o resultado 
    *r = x2;
    
    return iteracoes;
}