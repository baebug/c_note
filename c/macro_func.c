#include <stdio.h>
/* 함수이름(인자)  치환할 것 */
#define square(x) (x) * (x)
/*
전처리기 내부의 특수문자
#: 인자를 문자열로 바꾼다.
##: 입력된 것을 하나로 합쳐준다.
*/


int main(){
    /*
    매크로 함수는 컴파일 이전에 전처리기에 의해 단순히 치환되는 것이다.
    따라서   #define square(x) x*x
            square(3+1) 을 한다면,
            3 + 1 * 3 + 1 = 7이 나온다.
    해결법 (x)*(x)
    */
    printf("square(3) : %d \n", square(3 + 1));


    return 0;
}