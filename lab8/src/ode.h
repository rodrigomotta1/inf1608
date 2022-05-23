/**
 * Realiza o método de Runge-Kutta com passo h constante
 * 
 * @param t0 tempo inicial
 * @param t1 tempo final
 * @param h passo de integração
 * @param y0 valor inicial y(t0)
 * @param f função derivada, em função de t e y(t)
 * 
 * @returns valor no tempo final y(t1)
 */
double RungeKutta (double t0, double t1, double h, double y0, double (*f) (double t, double y));



/**
 * Realiza o método de Runge-Kutta, com h adaptando entre iterações.
 * 
 * O valor inicial de h fica definido como 10e-7
 * 
 * @param t0 tempo inicial
 * @param t1 tempo final
 * @param y0 valor inicial y(t0)
 * @param f função derivada, em função de t e y(t)
 * 
 * @returns valor no tempo final y(t1)
 */
double RungeKuttaAdapt (double t0, double t1, double y0, double (*f) (double t, double y), double tol);

