// Cria dinamicamente um vetor de dimensao n, sendo n o numero de elementos do vetor
double* vet_cria (int n);

// Libera a memoria de um vetor previamente alocado
void vet_libera (double* v);

// Calcula e retorna o valor do produto escalar entre dois vetores de dimensao n
double vet_escalar (int n, double* v, double* w);

// Calcula a norma-2 de um vetor de dimensao n
double vet_norma2 (int n, double* v);

// Calcula a multiplicacao de um vetor v por um valor escalar s, preenchendo o vetor w, previamente alocado, com  resultado
void vet_mults (int n, double* v, double s, double* w);

// Exibe os elementos de um vetor na tela
void vet_imprime (int n, double* v);
