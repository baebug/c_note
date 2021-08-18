#include <stdio.h>

int main()
{
    int score_board[9];
    int i, j;
    int score;

    printf("학생들의 성적을 순서대로 입력하세요. \n");
    for(i = 0; i < 9; i++){
        printf("%d번 학생 성적 : ", i+1);
        scanf("%d", &score);
        score_board[i] = score;
    }
    
    printf("성적 막대그래프 입니다. \n");
    for(i = 0; i < 9; i++){
        printf("%d번 학생 : ", i+1);
        for(j = 0; j < score_board[i]; j++){
            printf("-");
        }
        printf("\n");
    }


    return 0;
}