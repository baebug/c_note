#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Human {
    char name[10];
    int age;
    int gender; // 1: 군필, 2: 미필
};

int main(){
    struct Human *misae; // 미새라는 사람 집단 생성
    int size, i;

    printf("원하는 구조체 배열의 크기 : ");
    scanf("%d", &size);

    /* array_name = (type)malloc( sizeof(type) * size ) */
    misae = (struct Human *)malloc(sizeof(struct Human) * size);

    for(i = 0; i < size; i++){
        char name[10];
        printf("니 이름이 뭐고? : ");
        scanf("%s", name);
        strcpy(misae[i].name, name);
        printf("맻살이고? : ");
        scanf("%d", &misae[i].age);
        printf("군대갔다왔나? : ");
        scanf("%d", &misae[i].gender);
    }

    /* 출력 */
    printf("신상공개 \n");
    for(i = 0; i < size; i++){
        printf("%d번 : %s / %d / ", i + 1, misae[i].name, misae[i].age);
        if(misae[i].gender == 1){
            printf("군필 \n");
        } else {
            printf("미필 \n");
        }
    }

    /* 까먹지마라 */
    free(misae);

    return 0;
}