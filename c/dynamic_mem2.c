#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int student;    // 입력받고자 하는 학생 수
    int i, input;
    int *score;     // 학생들의 수학 점수 (변수)
    int sum = 0;

    printf("학생의 수는? : ");
    scanf("%d", &student);

    score = (int *)malloc(sizeof(int) * student);

    for(i = 0; i < student; i++){
        printf("학생 %d의 점수를 입력하세요. : ", i+1);
        scanf("%d", &input);
        
        score[i] = input;
        
        /*        
        scanf("%d", score[i]);
        */
    }

    for(i = 0; i < student; i++){
        sum += score[i];
    }

    printf("전체 평균 점수 : %d \n", sum / student);

    free(score);

    return 0;
}