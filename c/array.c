#include <stdio.h>

int main()
{
    /*
    소수 만들기
    : 소수로 나눠지지 않는다면 그 수는 소수이다.
    */
    int i;
    int is_prime = 5;
    int prime[1000];
    int index = 2;
    int count;
    prime[0] = 2;
    prime[1] = 3;

    while(1) {
        count = 0;
        for(i = 0; i < index; i++){
            if(is_prime % prime[i] != 0) {
                count++;
            } else {
                break;
            }
        }
        if (count == index) {
            index++;
            prime[index] = is_prime;
            printf("소수 %d를 찾았다! \n", prime[index]);
            if(index == 999) break;
        }
        is_prime += 2;

    }
    return 0;
}