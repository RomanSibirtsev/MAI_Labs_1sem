#include <stdio.h>
#include <limits.h>

int n;

int get_result (int a[n][n], int n);
void input(int n);


void input(int n){
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    get_result(a, n);
}

int get_result (int a[n][n], int n) {
    int max_elem = INT_MIN, min_elem = INT_MAX;
    int mi, mj;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > max_elem) {
                max_elem = a[i][j];
                mj = j;
            }
            if (a[i][j] < min_elem) {
                min_elem = a[i][j];
                mi = i;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        res += a[mi][i] * a[i][mj];
    }
    printf("%d\n", res);
    return res;
}


int main(void) {
    scanf("%d", &n);
    input(n);
    return 0;
}
