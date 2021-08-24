#include <stdio.h>
#include <stdlib.h>
void get_average(int **score_board, int subject, int student);

int main(int argc, char **argv){
    int i, j, input, sum = 0;
    int subject, student;
    int **score_board;
    /*
    score_board[subject][student] 배열을 만들 예정이다.
    */
    
    printf("과목 수를 입력해주세요. : ");
    scanf("%d", &subject);

    printf("학생 수를 입력해주세요. : ");
    scanf("%d", &student);

    score_board = (int **)malloc(sizeof(int *) * subject);

    for(i = 0; i < subject; i++){
        score_board[i] = (int *)malloc(sizeof(int) * student);
    }

    for(i = 0; i < subject; i++){
        printf("%d번째 과목에 대한 학생들의 성적을 입력해주세요. \n", i + 1);
        for(j = 0; j < student; j++){
            printf("%d번째 학생의 성적 : ", j + 1);
            scanf("%d", &input);
            score_board[i][j] = input;
        }
    }

    get_average(score_board, subject, student);

    /* 메모리 누수 방지를 위한 free */
    for(i = 0; i < subject; i++){
        free(score_board[i]);
    }

    free(score_board);

    return 0;
}

void get_average(int **score_board, int subject, int student){
    int i, j, sum;
    for(i = 0; i < subject; i++){
        sum = 0;
        for(j = 0; j < student; j++){
            sum += score_board[i][j];
        }
        printf("%d번째 과목의 총 점수   : %d 점 \n", i + 1, sum);
        printf("%d번째 과목의 평균 점수 : %d 점 \n\n", i + 1, sum / student);
    }

}