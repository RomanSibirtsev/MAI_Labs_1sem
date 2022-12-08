#include <stdio.h>

int n;

void solve(int a[n][n], int k) {
    int start_i = (k + k % 2) / 2 - 1;
    int start_j = (k + k % 2) / 2 - 1;

    int s = 0;
    int t = 1;
    int id = 1, id_i = 1, id_j = 0;
    printf("%d ", a[start_i][start_j]);
    while (s < n*n) {
        for (int z = 0; z < t; ++z) {
            if ((start_i + id * id_i >= 0) && (start_i + id * id_i < n) && (start_j + id * id_j >= 0) && (start_j + id * id_j < n)){
                
                start_i += id * id_i;
                start_j += id * id_j;
                printf("%d ", a[start_i][start_j]);
            }
        }
        if (id_j == 1) {
                id *= -1;
                t++;
            }
        id_i = 1 - id_i;
        id_j = 1 - id_j;
        s += t;
    }

}


int main(void) {
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
    solve(a, n);
    putchar('\n');
    return 0;
}