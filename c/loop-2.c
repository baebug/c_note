#include <stdio.h>

int main()
{
    int N;
    printf("별 몇 줄 ? (역)");
    scanf("%d", &N);

    for(int i = N; i > 0; i--) {
        int stars = i * 2 - 1;
        int space = N - i;
        while(space > 0) {
            printf(" ");
            space--;
        }
        while(stars > 0) {
            printf("*");
            stars--;
        }
        printf("\n");

    }


    return 0;
}