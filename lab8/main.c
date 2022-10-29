#include <stdio.h>

#define N 9

typedef unsigned int uint;

int func(uint n, char res[N]) {
    int k = 0;
    for (uint i = 0; n != 0; ++i) {
        --n;
        res[i] = n % 26 + 'A';
        n /= 26;
         k ++ ;
    }
    for (int i = 0; i < N; ++i) {
        char temp;
        temp = res[i];
        res[i] = res[N - i - 1];
        res[N - i - 1] = temp;
    }
    return k;

}

int main(void) {
    int n;
    char res[N] = {};
    scanf("%d", &n);
    func(n, res);
    for (int i = 0; i < N; i ++)
        printf("%c", res[i]);
    printf("\n");
}
