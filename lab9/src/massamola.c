#include <stdio.h>
#include <math.h>
#define GRAVIDADE 9.8
#define ARRASTO 


void forca (double t, double x, double y, double* fx, double* fy)
{
    // Armazena valores de x e y ao quadrado
    double xq = x * x, yq = y * y;
    
    // 
    double fk_x, fk_y;

    fk_x = -0.5 * (sqrt(xq + yq) - 200.0) * x / sqrt(xq + yq);
    fk_y = -0.5 * (sqrt(xq + yq) - 200.0) * y / sqrt(xq + yq);

    *fy = 2.0 * 9.8 + fk_y;
    *fx = 20.0 * exp(-t/20.0) + fk_x;
}


double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn)
{
    double fx, fy, hq;
  
    forca(t, x, y, &fx, &fy);

    hq = h * h;
    *xn = x + (1.0 - 0.002) * (x - xp) + hq * fx / 2.0;
    *yn = y + (1.0 - 0.002) * (y - yp) + hq * fy / 2.0;

    return t+h;
}


void simula (double x0, double y0, double t_final, int n, double* x, double* y)
{
  double t = 0.0, h = t_final / n, xn, yn;
  double x_atual = x0, y_atual = y0, xp = x0, yp = y0;

  for(size_t i = 0; i < n; ++i)
  {
    t = evolui(t, h, x_atual, y_atual, xp, yp, &x[i], &y[i]);

    xp = x_atual;
    yp = y_atual;

    x_atual = x[i];
    y_atual = y[i];
  }

}