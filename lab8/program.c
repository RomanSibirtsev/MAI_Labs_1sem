//Найти первые 10 простых чисел
#include <stdio.h>

int main()
{
    int z, k = 1, i = 0;
    while (i < 10)
    {
        ++k;
        z = 1;
        for (int j = 2; j * j <= k; ++j)
        {
            if (k % j == 0)
            {
                z = 0;
                break;
            }
        }
        if (z == 1)
        {
            printf("%d ", k);
            ++i;
        }
    }
}
