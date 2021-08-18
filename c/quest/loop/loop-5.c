#include <stdio.h>

int main()
{
    int N;
    int multiple = 1;
    printf("N을 입력해주세요.");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        multiple *= i;
    }
    printf("1부터 %d까지의 곱은 %d 입니다.", N, multiple);

    return 0;
}