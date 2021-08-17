#include <stdio.h>

int main()
{
    int N;
    printf("별 몇 줄 ?");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        int space = N - i;
        int star = i * 2 - 1;
        for(int j = 1; j <= space; j++){
            printf(" ");
        }
        for(int k = 1; k <= star; k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}