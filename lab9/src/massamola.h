/**
 * Calcula o valor da força resultante, preenchendo os ponteiros passados com os resultados;
 * 
 * @param t tempo
 * @param x posição corrente no eixo x
 * @param y posição corrente no eixo y
 * @param fx coordenada x do vetor resultante de força
 * @param fy coordenada y do vetor resultante de força
 */
void forca (double t, double x, double y, double* fx, double* fy);



/**
 * 
 * 
 */
double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn);


void simula (double x0, double y0, double t_final, int n, double* x, double* y);