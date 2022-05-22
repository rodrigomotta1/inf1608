// Calcula o resultado mais próximo possível de um sistema incosistente utilizando o Método dos Mínimos Quadrados
//  Recebe uma matriz A(m x n), um vetor b (m) e um vetor de armazenamento x para receber os valores solução do sistema
double mmq (int m, int n, double** A, double* b, double* x);


// Realiza a solução do sistema por MMQ para um ajuste à parabola, utilizando para isso os N pontos fornecidos em px e py.
// Os coeficientes são amrazenados nos endereços a, b, c recebidos
double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c);


// Realiza a solução do sistema por MMQ para um ajuste cúbico, utilizando para isso os N pontos fornecidos em px e py.
// Os coeficientes são amrazenados nos endereços a, b, c, d recebidos
double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d);
