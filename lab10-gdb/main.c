#include <stdio.h>

int main(void){

  int n = 0, k, res;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i){
    n += i;
  }
  res = n / k;
  printf("%d",res);
  return 0;
}