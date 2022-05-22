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
