#include <stdio.h>

int k;

void solve(int a[k][k], int n) {
    int i, j;
    int old_n = n;
    n = k - n;
    int start_i = k - n;
    int start_j = k - n;
    int id_i = start_i;
    int id_j = k - start_j - 1;
    while (id_j >= start_j) {
        printf("%d ", a[id_i][id_j]);
        id_j -= 2;
    }
    id_j += 2;
    id_i += 2;
    while (id_i <= k - start_i - 1) {
        printf("%d ", a[id_i][id_j]);
        id_i += 2;
    }
    id_i -= 2;
    id_j += 2;
    while (id_j <= k - 1 - start_j) {
        printf("%d ", a[id_i][id_j]);
        id_j += 2;

    }
    id_j -= 2;
    id_i -= 2;
    while (id_i > start_i) {
        printf("%d ", a[id_i][id_j]);
        id_i -= 2;

    }
    id_i += 2;



    id_i = start_i;
    id_j = k - start_j - 1;
    id_j -= 1;
    while (id_j >= start_j) {
        printf("%d ", a[id_i][id_j]);
        id_j -= 2;
    }
    id_j += 1;
    id_i += 1;
    while (id_i <= k - start_i - 1) {
        printf("%d ", a[id_i][id_j]);
        id_i += 2;
    }
    id_i -= 1;
    id_j += 1;
    while (id_j <= k - 1 - start_j) {
        printf("%d ", a[id_i][id_j]);
        id_j += 2;

    }
    id_j -= 1;
    id_i -= 1;
    while (id_i >= start_i) {
        printf("%d ", a[id_i][id_j]);
        id_i -= 2;

    }
    id_i += 2;

    if (old_n <= k/2) {
        solve(a, old_n+1);
    }
}


int main(void) {
    scanf("%d", &k);
    int a[k][k];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
    solve(a, 0);
    putchar('\n');
    return 0;
}