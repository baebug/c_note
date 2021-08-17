#include <stdio.h>

int main()
{   
    int punch;

    printf("봉권이 몇 대 패실 예정인가요? (  대)");
    scanf("%d", &punch);

    printf("\n퍼버버벅! \n");
    if (punch <= 10) {
        printf("강봉권 : 하하하! 고작 %d대? 간지럽군! \n", punch);
        printf("아직 봉권이가 정신을 못차렸나 봅니다. \n");
        main();
    }
    else {
        printf("강봉권 : 흐엉! 너무아파! \n");
        printf("봉권이는 %d대를 맞고 죽어버렸습니다! \n", punch);

    }
    return 0;
}