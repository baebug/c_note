#include <stdio.h>

int main()
{
    int i = 1;
    int odd = 1;
    int even = 0;
    int sum = 0;
    while (i <= 1000000) {
        if ( i % 2 == 1) {
            /* 홀수 항 */
            even = odd + even;
        }
        else {
            /* 짝수 항 */
            odd = even + odd;
            sum += even;
        }
        i++;
    }
    printf("짝수항의 총 합은 %d 입니다.", sum);

    return 0;
}