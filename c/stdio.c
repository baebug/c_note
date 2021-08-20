#include <stdio.h>

int main(){
    int num;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    /*
    stdin 비우기
    하지만 fflush가 표준으로 '어떠한 역할을 한다.'라고 정해진 것이 아니라 위험.
    gcc에서는 작동 안 하거나 다른 결과가 나올 수 있다.
    */
    // fflush(stdin); 

    /*
    getchar 함수 = stdin에서 한 문자를 읽어와서 그 값을 리턴한다.
    즉, 남아있던 '\n'를 뽑아서 호로록
    */
    getchar();

    /*
    위와 같은 복합적인 이유로 scanf에서 %c 를 사용하는 것은 정말 비추천한다.
    차라리 %s 를 통해 문자열을 입력받고 제일 앞 글자를 사용하자.
    */
    
    printf("문자를 입력하세요 : ");
    scanf("%c", &c);

    return 0;
}