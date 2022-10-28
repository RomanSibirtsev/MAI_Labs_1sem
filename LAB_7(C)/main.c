#include <stdio.h>

int min(int a, int b){
  if (a > b){
    return b;
  }else{
    return a;
  }
}

int max(int a, int b){
  if (a > b){
    return a;
  }else{
    return b;
  }
}

int sign(int a){
  if (a < 0){
    return -1;
  }
  else if (a == 0){
    return 0;
  }else{
    return 1;
  }
}

int abs(int a){
  if (a < 0){
    return -1*a;
  }else{
    return a;
  }
}

int main(void)
{
  int i = 13, j = 19, l = 14, pr = 1;
  for (int k = 0; k <= 50; ++k)
  {
    printf("%d %d %d %d \n", k, i, j, l);
    if ((i + j + 10 <= 0) && (i + j + 20 >= 0))
    {
      printf("YES, k = %d, i = %d, j = %d, l = %d", k, i, j, l);
      pr = 0;
      break;
    }
    else
    {
      i = sign(i + 1) * abs(abs(k - j) - abs(i - l));
      j = j % 20 + max(i % 20, min(j - k, l - k)) - 10;
      l = k * (i + 1) * (j + 2) * (l + 3) % 20;
    }
  }
  if (pr == 1)
  {
    printf("NO  i = %d, j = %d, l = %d", i, j, l);
  }
  return 0;
}
