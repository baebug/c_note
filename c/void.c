#include <stdio.h>

/*
int main(){
    void a;

    a = 3;

    return 0;
}
*/

/*
void형 변수?? 컴파일러가 메모리에 얼만큼의 공간을 만들어놔야할지 모름, error
void*는 왜 되는데? 포인터는 결국 8바이트의 공간을 차지하기 때문
타입에 상관없이 주소값만 가지게 됨. (어떤 타입의 변수든 주소값을 저장할 수 있다.)
대신 출력할 때 얼마만큼 읽어야하는지 모르는 문제가 발생하기때문에
printf("%lf", *(double *)a); --> 형변환: a는 double형을 담고 있는 포인터입니다.
*/

/* 어떠한 타입 변수의 시작 주소값과 얼마나 읽을지 */
int read_char(void *p, int byte);

int main(){
    int arr[1] = {0x12345678};

    printf("%x \n", arr[0]);
    read_char(arr, 4);

    return 0;
}

int read_char(void *p, int byte){
    do {
        /* 리틀 엔디안 */
        printf("%x \n", *(char *)p);
        byte--;

        /* p 에 들어있는 값은 char형 변수의 주소값이다. */
        p = (char *)p + 1;
    } while (p && byte);

    return 0;
}