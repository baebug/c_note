/* 비트 연산의 예 2 */
if (i % 2 == 1) // 이 수가 홀수인가
{
    printf("%d 는 홀수 입니다. \n", i);
} else {
    printf("%d 는 짝수 입니다. \n", i);
}
/* 나눗셈 연산은 굉장히 느리다. */
if (i & 1) // 이 수가 홀수인가
{
    printf("%d 는 홀수 입니다. \n", i);
} else {
    printf("%d 는 짝수 입니다. \n", i);
}


/* 비트 연산의 예 1 */
struct HUMAN
{
    int is_Alive;
    int is_Walking;
    int is_Running;
    int is_Jumping;
    int is_Sleeping;
    int is_Eating;
};
/* 이것은 굉장한 메모리 낭비. */

#include <stdio.h>
#define ALIVE 0x1       // 2 진수로 1
#define WALKING 0x2     // 2 진수로 10
#define RUNNING 0x4     // 2 진수로 100
#define JUMPING 0x8     // 2 진수로 1000
#define SLEEPING 0x10   // 2 진수로 10000
#define EATING 0x20     // 2 진수로 100000

int main(){
    int my_status = ALIVE | WALKING | EATING;
    /* my_status = 100011
    if 는 0이 아닌 모든 값을 참으로 본다. */
    if (my_status & ALIVE){
        /*
          100011
        &      1
        */
        printf("I am ALIVE!! \n");
    }
    if (my_status & WALKING){
        /*
          100011
        &     10
        */
        printf("I am WALKING!! \n");
    }
    if (my_status & RUNNING){
        /*
          100011
        &    100
        */
        printf("I am RUNNING!! \n");
    }
    if (my_status & JUMPING){
        /*
          100011
        &   1000
        */
        printf("I am JUMPING!! \n");
    }
    if (my_status & SLEEPING){
        /*
          100011
        &  10000
        */
        printf("I am SLEEPING!! \n");
    }
    if (my_status & EATING){
        /*
          100011
        & 100000
        */
        printf("I am EATING!! \n");
    }

    return 0;
}