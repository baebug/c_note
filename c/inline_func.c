#include <stdio.h>
/*
extern 안써주면 undefine symbol error 
inline 함수는 단순히 '함수처럼 보이는 것'일 뿐이다.
매크로 함수 사용말고 인라인 함수 사용하자.
*/
extern __inline int square(int a) { return a * a; }
int main(int argc, char **argv){
    printf("%d", square(3));

    return 0;
}