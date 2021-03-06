#include <stdio.h>

int main()
{
    /* 포인터(주소값)를 아라보자 */
    int* pa;
    int a = 2;
    pa = &a;
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
    printf("int 변수 a가 저장된 주소 : %p \n", &a);    //&(단항연산자)로 주소값을 불러온다. 0x16fdfef98 0x16fdfefa8
    printf("포인터 pa에 들어있는 값 : %p \n", pa);
    printf("그럼 *pa는 뭔데? : %d \n", *pa);
    /* 주소값을 가지고 있는 포인터에 다시 * 찍으면 값이 나온다. */
    printf("(pa + 1)의 값 : %p \n", pa + 1);

    int i, j;
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("---- 지옥의 수레바퀴 ---- \n");
    /* 2차원 배열에서의 포인터를 아라보자 */
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("arr[%d][%d]의 주소값 : %p \n", i, j, &arr[i][j]);
            printf("*(arr+%d)+%d 의 주소값 : %p \n", i, j, *(arr+i)+j);
            printf("*(*(arr+%d)+%d) = arr[%d][%d] = %d \n", i, j, i, j, *(*(arr+i)+j));
        }
        // printf("*(arr+%d) 의 주소값 : %p \n", i, *(arr+i));
    }

    return 0;
}