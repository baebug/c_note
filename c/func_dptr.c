#include <stdio.h>

int pswap(int **ppa, int **ppb);

int main(){
    int a, b;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("pa가 가리키는 변수(a)의 주소값 : %p \n", pa);
    printf("pa의 주소값 : %p \n \n", &pa);
    printf("pb가 가리키는 변수(b)의 주소값 : %p \n", pb);
    printf("pb의 주소값 : %p \n \n", &pb);

    printf(" ---------------- pswap ---------------- \n");
    pswap(&pa, &pb);
    printf(" -------------- pswap end -------------- \n");

    printf("pa가 가리키는 변수(a)의 주소값 : %p \n", pa);
    printf("pa의 주소값 : %p \n \n", &pa);
    printf("pb가 가리키는 변수(b)의 주소값 : %p \n", pb);
    printf("pb의 주소값 : %p \n \n", &pb);
    
    return 0;
}

int pswap(int **ppa, int **ppb){
    int *temp;

    printf("ppa 가 가리키는 변수의 주소값 : %p \n", ppa);
    printf("ppb 가 가리키는 변수의 주소값 : %p \n", ppb);

    temp = *ppa;
    *ppa = *ppb;
    *ppb = temp;

    return 0;
}