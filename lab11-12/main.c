#include <stdio.h>

int main(void){

  char alf[] = "IVXLCDM";
  int oldest_id = -1, old_id = -1, id = -1, k = 1, old_k = 0;
  int check = 0, check_num = 1, res = 0, eow = 0, n = 0, slovo = 1;
  int n_V = 0, n_L = 0, n_D = 0;
  for (char ch = getchar(); ch != EOF; ch = getchar())
  {
    if ((ch == ' ') || (ch == ',') || (ch == '  ') || (ch == '\n'))
    {
      eow = 1;
    }
    else
      eow = 0;
    oldest_id = old_id;
    old_id = id;
    check = 0;

    for (int i =  0; i < sizeof(alf)/sizeof(alf[0]); i++)
    {
      if (alf[i] == ch)
      {
        check = 1;
        id = i;
      }
    }

    if (check == 1)
    {
      if (ch == 'V')
        n_V++;
      if (ch == 'L')
        n_L++;
      if (ch == 'D')
        n_D++;

      n++;
      if (old_id == id)
        k++;
      else
      {
        old_k = k;
        k = 1;
      }

      if (k > 3) // IIII XXXX VVVV
      {
        check_num = 0;
      }

      else if ((k > 1) && ((id == 1) || (id == 3) || (id == 5))) // VV LL DD VVV LLL ...
      {
        check_num = 0;
      }

      else if ((old_k > 1) && (old_id < id)) // IIV VVX IIX ...
      {
        check_num = 0;
      }

      else if ((oldest_id == id) && (oldest_id != -1) && (oldest_id < old_id)) // IXI VXV ...
      {
        check_num = 0;
      }
      else if ((n_V > 1) || (n_L > 1) || (n_D > 1)) // VIV VIIV XXVXV ...
      {
        check_num = 0;
      }

    }

    else
    {
      if (((ch == ' ') || (ch == ',') || (ch == '  ') || (ch == '\n')) && (eow = 1) && (n > 0) && (slovo == 1))
      {
        res += check_num;
      }
      slovo = 0;
      n = 0;
      check_num = 1;
      oldest_id = -1;
      old_id = -1;
      id = -1;
      k = 1;
      n_V = 0;
      n_D = 0;
      n_L = 0;
    }
    if ((ch == ' ') || (ch == ',') || (ch == '  ') || (ch == '\n'))
      slovo = 1;

  }
  printf("res = %d", res);

}
