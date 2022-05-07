// Retorna o valor da derivada númerica correspondente à um método de ordem n, de uma função no ponto x, com passo h, tendo como base no método de segunda ordem, usando extrapolação de Richardson. Considera-se n >= 2.
double derivada (int n, double(*f) (double x), double x, double h);


// Retorna o valor da integral composta do intervalo de A a B, considerando n passos de integração, i.e., h = (b - a)/n
double simpson(double(*f) (double x), double a, double b, int n);