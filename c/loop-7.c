#include <stdio.h>

int main()
{
    int N;
    int prime = 2;
    printf("소인수분해 할 수를 입력해주세요.");
    scanf("%d", &N);

    while(N != 1) {
        if ( N % prime == 0 ) {
            N = N / prime;
        }
        else {
            prime++;
            for(int p = prime - 1; p > 1; p--) {
                if ( prime % p == 0 ) {
                    break;
                }
            }
        }
    }

    return 0;
}