#include <stdio.h>

int find_prime();
int divide_N();

int N;
int prime = 2;

int main()
{
    
    printf("소인수분해 할 수를 입력해주세요.");
    scanf("%d", &N);
    /*
    find_prime(prime);
    printf("다음 소수는 %d 입니다.", prime);
    이렇게 하면 2가 리턴된다.
    
    printf("다음 소수는 %d 입니다.", find_prime(prime));
    이렇게 하면 3이 리턴된다.
    */

    while(N != 1) {
        N = divide_N(N, prime);
        printf("%d", N);
    }

    return 0;
}

int divide_N(N, prime)
{
    if (N % prime == 0) {
        N = N / prime;
        printf("%d", prime);
    }
    else {
        prime = find_prime(prime);
        divide_N(N, prime);
    }

    return N;
}

int find_prime(prime)
{
    prime++;
    int count = 0;
    for(int d = 2; d < prime; d++){
        if (prime % d != 0) {
            count++;
        }
        else continue;
    }

    if (count == prime - 2) {
        return prime;
    }
    else {
        find_prime(prime);
    }

    return 0;
}