#include <stdio.h>
int copy_arr(char *parr1, const char *parr2);

struct Human
{
    int age;    /* 나이 */
    int height; /* 키 */
    int weight; /* 몸무게 */
};              /* ;로 끝내야 함 */

struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 대출 유무 */
    int borrowed;
};

int main(){
    struct Human bong;

    bong.age = 30;
    bong.height = 183;
    bong.weight = 73;    

    printf("봉권이 신상털이 \n");
    printf("나이    : %d살 \n", bong.age);
    printf("키      : %dcm \n", bong.height);
    printf("몸무게  : %dkg \n", bong.weight);

    struct Books Harry_Potter;

    copy_arr(Harry_Potter.name, "Harry Potter");
    copy_arr(Harry_Potter.auth, "J.K. Rolling");
    copy_arr(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0; // 구조체 내에서 변수 초기화 할 수 없음.

    printf("책 정보 출력 \n");
    printf("책 이름      : %s \n", Harry_Potter.name);
    printf("저자 이름    : %s \n", Harry_Potter.auth);
    printf("출판사 이름  : %s \n", Harry_Potter.publ);

    return 0;
}

int copy_arr(char *parr1, const char *parr2){
    int count = 0;

    while(parr2[count]){
        parr1[count] = parr2[count];
        count++;
    }
    /* 마지막에 Null 넣어주기! (detail) */
    parr1[count] = '\0';

    return 0;
}