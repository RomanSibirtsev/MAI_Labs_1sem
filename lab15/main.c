#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;
    int max_elem = INT_MIN, min_elem = INT_MAX;
    int mi, mj;
    int res = 0;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
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
    return 0;
}