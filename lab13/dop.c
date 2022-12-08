#include <stdio.h>
#include <string.h>

int result = 0;

int P(int a){
    int res = 0;
    while (a % 2 == 0){
        ++res;
        a /= 2;
    }
    return res;
}

int solve(int n) {
    int id; 
    int ch = 0, nech = 0;
    int minp = 999999, pr;
    int res1 = 0;
    for (long int i = 0; i < n; ++i) {
        scanf("%d", &id);
        if (id % 2 != 0) {
            ++nech;
        } else {
            ++ch;
            pr = P(id);
            if (pr < minp) {
                minp = pr;
            }
        }

    }
    if ((nech > 0) && (ch > 0)) {
        res1 = ch ;
    } else if ((nech > 0) && (ch == 0)) {
        res1 = 0;
    } else {
        res1 = (ch - 1) + minp;
    }
    return res1;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    int otvet[t];
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        otvet[i] = solve(n);
    }
    for (int i = 0; i < t; ++i) {
        printf("%d\n", otvet[i]);
    }
    return 0;
}