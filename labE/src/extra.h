#ifndef PRECISAO_IQI
#define PRECISAO_IQI 0.5e-8 /* valor mínimo para ser considerado raíz do algoritmo do IQI */
#endif


/**
 * Determina a raíz de uma função utilizando o método de Interpolação Inversa Quadrática.
 * 
 * Por ser um método aberto, a avaliação pode não convergir. Neste caso o valor retornado é -1.
 * 
 * @param x0 primeira estimativa inicial do método
 * @param x1 segunda estimativa inicial do método
 * @param x2 terceira estimativa inicial do método
 * @param f função cuja raíz deseja-se avaliar
 * @param r endereço de armazenamento da avaliação 
 * 
 * @return número de iterações utilizadas na avaliação do método
 * 
 */
int IQI (double x0, double x1, double x2, double (*f) (double x), double* r);


/**
 * Calcula os coeficientes para o ajuste de uma função do tipo: c = a * t * exp(b * t)
 * 
 * Basicamente calcula MMQ utilizando a função acima como referência
 * 
 * @param n número de medições (Tn, Cn)
 * @param t vetor de valores de tempo para ajuste
 * @param c vetor de valores de concentrações da droga na corrente sanguínea
 * @param a vetor de coeficientes a
 * @param b vetor de coeficientes b
 * 
 */
void ajuste(int n, double* t, double* c, double* a, double* b);
