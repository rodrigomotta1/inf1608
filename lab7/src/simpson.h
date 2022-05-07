// Recebe o intervalo de integração [a, b], a função f(x) que será integrada e a tolerância de erro desejada tol. 
// Retorna o valor da integral no intervalo dentro da tolerância.
double adaptsimpson (double a, double b, double (*f) (double x), double tol);


// Recebe o valor de sigma para um desvio padrão e retorna uma probabilidade, com precisão de 8 dígitos
// Utiliza Integral de Simpson Adpatativa
double probabilidade (double sigma);



// Define a formula da função de desvio padrão, para x
double desvio_padrao(double x);