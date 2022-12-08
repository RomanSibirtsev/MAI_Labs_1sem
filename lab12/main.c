#include <stdio.h>
#include <math.h>
#include <ctype.h>

void process() {
    int a = 0, n = 1;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        if (!isspace(ch)) {
            n *= 10;
            a = a*10 + (ch -  '0'); 
        } else {
            if (n > 10) {
                int save = a % (n / 10) / (n / 100);
                a += -save * (n / 100) + (a % 100 / 10) * (n / 100);
                a += -(a % 100 / 10)*10 + save * 10;
            }
            printf("%d\n", a);
            a = 0;
            n = 1;
        }
    }
}

int main(void) {
    process();
    return 0;
}