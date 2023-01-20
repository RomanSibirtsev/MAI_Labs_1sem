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

void newton(double a, double b) {
  double x = a, x_old = -1, eps = sqrt(mech_eps());
  while (x <= b) {
    if (fabs(func(x)*sec_der(x)) < (der(x)*der(x))) {
      x_old = x;
      x = x_old - func(x)/der(x);
      if (fabs(x - x_old) <= eps) {
        printf("Newton's method\n");
        printf("%.16f \n", x);
        printf("%.16f \n", func(x));
        break;
      }
    }
    else {
      printf("doesn`t converge\n");
      break;
    }
  }
}

void half(double a, double b) {
  double x = a, mid, eps = sqrt(mech_eps());
  while (b - a > eps) {
    mid = (a + b) / 2.;
    if (func(a) * func(mid) < 0) b = mid;
    if (func(mid) * func(b) < 0) a = mid;
  }
  x = (a + b) / 2;
  printf("dichotomy method\n");
  printf("%.16f \n", x);
  printf("%.16f \n", func(x));
}

void iter(double a, double b) {
    double x = a, x_old = -1, eps = sqrt(mech_eps());
    while (fabs(x_old - x) > eps) {
      x_old = x;
      x = f2(x);
    }
    printf("iterations method\n");
    printf("%.16f \n", x);
    printf("%.16f \n", func(x));
}

int main(void) {
  double a = 0, b = 2;
  newton(a, b);
  printf("\n");
  half(a, b);
  printf("\n");
  iter(a, b);

}
