#include <stdio.h>

int main()
{
    char a;
    a = 'a';

    printf("a의 값과 들어있는 문자는? 값: %d, 문자: %c \n", a, a); // 값: 97, 문자: a

    /* 섭씨를 입력받아 화씨로 변경하는 프로그램 */
    double celsius; // 섭씨 온도

    printf("섭씨 온도를 화씨 온도로 바꿔주는 프로그램입니다. \n");
    printf("섭씨 온도를 입력해 주세요 : ");
    /*
    섭씨 온도를 입력받는다.
    double은 무조건 %lf, float는 무조건 %f로 입력받아야 함.
    scanf는 자료형마다 포맷이 모두 정해져 있다.
    */
    scanf("%lf", &celsius); 

    printf("섭씨 %.1f 도는 화씨로 %.1f 도 입니다. \n", celsius, 9 * celsius / 5 + 32);

    /* scanf 총 정리 */
    // 문자
    char ch;

    // 정수
    short sh;
    int i;
    long lo;

    // 실수
    float fl;
    double du;
    
    /*
    scanf로 입력받다보면 입력버퍼 안의 개행 문자(\n)가 지워지지 않아서
    문자 입력을 받지 않고 건너뛰는 경우가 종종 있다.
    그때 getchar()를 통해 비워줄 수 있다.
    */
    getchar();

    printf("char 형 변수 입력 : ");
    scanf("%c", &ch);
    
    printf("short 형 변수 입력 : ");
    scanf("%hd", &sh);
    printf("int 형 변수 입력 : ");
    scanf("%d", &i);
    printf("long 형 변수 입력 : ");
    scanf("%ld", &lo);
    
    printf("float 형 변수 입력 : ");
    scanf("%f", &fl);
    printf("double 형 변수 입력 : ");
    scanf("%lf", &du);

    printf("char: %c, short: %d, int: %d", ch, sh, i);
    printf("long: %ld, float: %f, double: %f \n", lo, fl, du);
    
    return 0;
}