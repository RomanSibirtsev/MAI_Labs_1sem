#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define sign(x) ((x)<0 ? -(x) : (x))
int main(void)
{
  int i = 13, j = 19, l = 14, pr = 1;
  for (int k = 0; k <= 50; ++k)
  {
    if ((i + j + 10 >= 0) && (i + j + 20 <= 0))
    {
      printf("YES, k = %d, i = %d, j = %d, l = %d", k, i, j, l);
      pr = 0;
      break;
    }
    else
    {
      i = sign(i + 1) * abs(abs(k - j) - abs(i - l));
      j = j % 20 + fmax(i % 20, fmin(j - k, l - k)) - 10;
      l = k * (i + l) * (j + 2) * (l + 3) % 20;
    }
  }
  if (pr == 1)
  {
    printf("NO  i = %d, j = %d, l = %d", i, j, l);
  }
  return 0;
}
