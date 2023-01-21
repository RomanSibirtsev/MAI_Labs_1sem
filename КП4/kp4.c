#include <stdio.h>
#include <math.h>

double mech_eps(void) {
	double e = 1.0f;

	while (1.0f + e / 2.0f > 1.0f)
		e /= 2.0f;
	return e;
}

double func(double x) {
  double res = 0.25*x*x*x + x - 1.2502;
  return res;
}

double der(double x) {
  double res = 0.25*3*x*x + 1;
  return res;
}

double sec_der(double x) {
  double res = 0.25*3*2*x;
  return res;
}

double f2 (double x) {
  return (1.2502 - 0.25*x*x*x);
}

double newton(double (*func)(double), double a, double b) {
  double x = a, x_old = -1, eps = sqrt(mech_eps());
  while (x <= b) {
    if (fabs(func(x)*sec_der(x)) < (der(x)*der(x))) {
      x_old = x;
      x = x_old - func(x)/der(x);
      if (fabs(x - x_old) <= eps) {
        return x;
      }
    }
    else {
      return ;
    }
  }
}

double half(double (*func)(double), double a, double b) {
  double x = a, mid, eps = sqrt(mech_eps());
  while (b - a > eps) {
    mid = (a + b) / 2.;
    if (func(a) * func(mid) < 0) b = mid;
    if (func(mid) * func(b) < 0) a = mid;
  }
  a *= 1e10;
  b *= 1e10;
  x = (a + b) / 2;
  x *= 1e-10;
  return x;
}

double iter(double (*func)(double), double a, double b) {
    double x = a, x_old = -1, eps = sqrt(mech_eps());
    while (fabs(x_old - x) > eps) {
      x_old = x;
      x = func(x);
    }
    return x;
}

int main(void) {
  double a = 0, b = 2;
  double x1, x2, x3;
  x1 = newton(func, a, b);
  printf("%.16f %.16f\n", x1, func(x1));
  x2 = half(func, a, b);
  printf("%.16f %.16f\n", x2, func(x2));
  x3 = iter(f2, a, b);
  printf("%.16f %.16f\n", x3, func(x3));
}
