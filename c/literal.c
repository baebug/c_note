#include <stdio.h>

int main(){
    /*
    pstr은 주소값이 들어가는 변수인데 어떻게 "sentence"라는 string이 들어있는가?
    "sentence"는 "sentence"라는 문자열이 저장된 주소값?!

    literal 이란, 소스 코드 상에서 고정된 값을 가지는 것.
    C에서는 "로 묶인 것들을 문자열 리터럴(string literal)이라고 한다. ("%c" 도)
    read-only

    따라서
    char *pstr = "goodbye";
    pstr[1] = 'a'; 는 오류를 뱉는다.

    하지만
    char str[] = "hello"; 는 왜 동작해?
    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'}; 이므로 리터럴이라 할 수 없다.

    리터럴 지정은
    char *pstr = "goodbye"; 가 아니라
    const char *pstr = "goodbye"; 로 하자!
    */
    char *pstr = "sentence";

    printf("pstr: %s \n", pstr);
    printf("%d \n", "sentence");
    return 0;
}