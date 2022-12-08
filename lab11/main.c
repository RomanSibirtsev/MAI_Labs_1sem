#include <stdio.h>

enum State {
    TRUE,
    FALSE
};

int main(void){

  char alf[] = "IVXLCDM";
  int oldest_id = -1, old_id = -1, id = -1, k = 1, old_k = 0;
  int check_num = 1, res = 0, eow = 0, n = 0, slovo = 1;
  int n_V = 0, n_L = 0, n_D = 0;

  enum State check = FALSE;

  for (char ch = getchar(); ch != EOF; ch = getchar())
  {

    if ((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n'))
    {
      eow = 1;
    }
    else
      eow = 0;
      
    oldest_id = old_id;
    old_id = id;
    check = FALSE;

    for (int i =  0; i < sizeof(alf)/sizeof(alf[0]); i++)
    {
      if (alf[i] == ch)
      {
        check = TRUE;
        id = i;
      }
    }


    switch (check)
    {
    case TRUE:
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

        else if ((oldest_id < old_id) && (old_id <= id) && (oldest_id != -1) && (old_id != -1)) // CMM IXX
        {
            check_num = 0;
        }


        break;
    
    case FALSE:
        if (((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n')) && (eow = 1) && (n > 0) && (slovo == 1))
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
        break;
    }

    if ((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n'))
      slovo = 1;
  }

  printf("res = %d\n", res);
  return 0;

}