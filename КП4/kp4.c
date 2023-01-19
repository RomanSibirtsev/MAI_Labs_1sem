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

int main(void) {
  double a = 0, b = 2;
  double x = a, x_old, eps = mech_eps();
  while (x <= b) {
    if (fabs(func(x)*sec_der(x)) < (der(x)*der(x))) {
      x_old = x;
      x = x_old - func(x)/der(x);
      if (fabs(x - x_old) <= eps) {
        printf("%f \n", x);
        printf("%f \n", func(x));
        break;
      }
    }
    else {
      printf("doesn`t converge\n");
      break;
    }
  }
}
