#include <stdio.h>

int main()
{
    int input;

    printf("마이 봉권이 \n");
    printf("무엇을 하실 것인지 입력하세요 \n");
    printf("1. 밥주기 \n");
    printf("2. 재우기 \n");
    printf("3. 줘패기 \n");

    scanf("%d", &input);

    /*
    if (input == 1) {
        printf("아이 맛있어 \n");
    } else if (input == 2) {
        printf("zzz \n");
    } else if (input == 3) {
        printf("흐엉ㅠ 왜 때려! \n");
    } else {
        printf("뭐라카노? \n");
    }
    */

    switch (input) {
        case 1:
            printf("아이 맛있어 \n");
            break;
        case 2:
            printf("zzz \n");
            break;
        case 3:
            printf("흐엉ㅠ 왜 때려! \n");
            break;
        
        default:
            printf("뭐라카노? \n");
            break;
    }
    
    return 0;
}