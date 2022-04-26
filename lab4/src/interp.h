
/* 
    Retorna n amostras espaçadas regularmente no intervalo [a, b], onde Xi[0] = a, Xi[n - 1] = b e os demais valores
são regularmente distribuídos no intervalo.
 
    A função deve calcular as amostras Xi, preenchendo o vetor xi pré-alocado, passado como param.
*/
void regular (int n, double a, double b, double* xi);


/*
    Retorna n amostras de Chebyshev para a aproximação de uma função qualquer, dentro do intervalo [a, b]

*/
void chebyshev (int n, double a, double b, double* xi);

/*
    Função recebe as amostras xi e a função que se deseja interpolar. Preenchi bi com os coeficientes calculados    
*/
void coeficientes (int n, double* xi, double (*f) (double), double* bi);


double avalia (int n, double* xi, double* bi, double x);

