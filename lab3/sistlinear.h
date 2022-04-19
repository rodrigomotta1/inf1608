// Realiza o pivotamento do sistema composto pela matriz A(n x n) e o vetor resultante b, para a coluna col
void pivotagem(double **A, double* b, int col, int n);

// Calcula as raizes do sistema definido por Ax = b, sendo A(n x n). As raizes sao guardadas no vetor recebido x
void gauss (int n, double** A, double* b, double* x);