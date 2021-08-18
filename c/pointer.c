#include <stdio.h>

int main()
{
    /* 포인터(주소값)를 아라보자 */
    int *p;
    int a;

    p = &a;
    /*
    포인터는 주소값을 보관하는 데이터의 형에 *를 붙임으로 정의되고,
    & 연산자로 특정한 데이터의 메모리 상 주소값을 알아낼 수 있다.
    int a (어떤 데이터가 저장되어 있음.)
    int b (어떤 주소값이 저장되어 있음.)
    &a = 데이터(a)가 저장된 주소값을 가지고 옴.
    *b = 주소(b)가 가리키는 데이터를 가지고 옴.

    young = &chul
    *young = chul
    */
    printf("포인터 p에 들어있는 값 : %p \n", p);
    printf("int 변수 a가 저장된 주소 : %p \n", &a);    //&(단항연산자)로 주소값을 불러온다. 0x16fdfef98 0x16fdfefa8

    return 0;
}