#include <stdio.h>

int main()
{
    int i, sum = 0;

    while(i <= 1000) {
        // if (i % 3 == 0) {
        //     sum += i;
        // }
        // else if (i % 5 == 0) {
        //     sum += i;
        // }
        // else
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
        i++;
    }
    printf("1000이하 3또는 5의 배수의 합은 %d 입니다.", sum);

    return 0;
}