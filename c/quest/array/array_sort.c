#include <stdio.h>

int main()
{
    int score_board[10];
    int i, j;
    int score;

    printf("학생들의 성적을 순서대로 입력해주세요. \n");
    for(i = 0; i < 10; i++) {
        printf("%d번 학생 성적 : ", i + 1);
        scanf("%d", &score);
        score_board[i] = score;
    }
    for(i = 0; i < 10; i++) {
        for(j = i; j < 10; j++){
            int low = 0;
            if (score_board[i] >= score_board[j]) continue;
            else {
                low = score_board[i];
                score_board[i] = score_board[j];
                score_board[j] = low;
            }
        }
        printf("%d점. \n", score_board[i]);
    }

    return 0;
}