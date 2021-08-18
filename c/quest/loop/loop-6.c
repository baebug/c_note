#include <stdio.h>

int main()
{
    int a, b, c;
    int count = 0;
    for (a = 2000; a >= 0; a--) {
        for (b = 2; a > b; b++) {
            /* 미처 생각 못 한 부분 */
            if (a + b > 2000) continue;
            for (c = 1; b > c; c++) {
                /* 미처 생각 못 한 부분 */
                if (a + b + c > 2000) continue;
                if (a + b + c == 2000) {
                    printf("%d, %d, %d \n", a, b, c);
                    count++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}