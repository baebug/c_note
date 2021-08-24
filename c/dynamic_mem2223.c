#include <stdio.h>
#include <stdlib.h>
void print_score(int subject, int student, int (*score_board)[subject]);
void get_average(int subject, int student, int (*score_board)[subject]);

int main(){
    int subject, student;
    printf("배열 행 크기 (과목 수) : ");
    scanf("%d", &subject);
    printf("배열 열 크기 (학생 수) : ");
    scanf("%d", &student);

    int (*score_board)[subject];
    score_board = (int(*)[subject])malloc(sizeof(int) * subject * student);

    for(int i = 0; i < student; i++){
        printf("%d 번 학생의 성적 입력하기 ------- \n", i + 1);
        for(int j = 0; j < subject; j++){
            int score;
            printf("%d 번째 과목의 성적을 입력하세요. : ", j + 1);
            scanf("%d", &score_board[i][j]);

            /*
            scanf("%d", &score);
            score_board[i][j] = score;
            */
        }
    }

    printf("\n");
    print_score(subject, student, score_board);
    printf("\n");
    get_average(subject, student, score_board);

    free(score_board);

    return 0;
}

void print_score(int subject, int student, int (*score_board)[subject]){
    int i, j;

    for(int i = 0; i < student; i++){
        printf("학생 %d의 성적 : ", i + 1);
        for(int j = 0; j < subject; j++){
            printf("%d점", score_board[i][j]);
        }
        printf("\n");
    }
    
}

void get_average(int subject, int student, int (*score_board)[subject]){
    int i, j, sum;

    for(int i = 0; i < student; i++){
        sum = 0;
        printf("%d 번 학생의 평균 점수 : ", i + 1);
        for(int j = 0; j < subject; j++){
            sum += score_board[i][j];
        }
        printf("%d 점 \n", sum / subject);
    }


}