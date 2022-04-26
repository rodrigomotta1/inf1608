// Cria dinamicamente uma matriz de dimensao m (linhas) x n (colunas)
double** mat_cria (int m, int n);

// Libera a memoria de uma matriz previamente criada
void mat_libera (int m, double** A);

// Realiza a Transposta de uma matriz A m x n, preenchendo uma matriz T
void mat_transposta(int m, int n, double** A, double** T);

// Realiza a multiplicacao de uma matriz A e um vetor V, preenchendo um veotr W
void mat_multv(int m, int n, double** A, double* v, double* w);

// Realiza a multiplicacao entre duas matrizes A(m x n) e B(n x q), preenchendo uma matriz C(m x q)
void mat_multm (int m, int n, int q, double** A, double** B, double** C);

// Imprime as entradas de uma matriz A(m x n)
void mat_imprime (int m, int n, double** A);

// Troca as linhas i e l de uma matriz A(m x n) de lugar
void mat_troca_linhas(int m, int n, double** A,  int i, int l);
